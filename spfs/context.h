#ifndef __SPFS_CONTEXT_H_
#define __SPFS_CONTEXT_H_

#include <stdio.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include "include/list.h"

#define ERESTARTSYS		512

typedef enum {
	SPFS_INVALID_MODE = -1,
	SPFS_PROXY_MODE = 0,
	SPFS_STUB_MODE,
	SPFS_MAX_MODE,
} spfs_mode_t;

struct work_mode_s {
	int			cnt;
	spfs_mode_t		mode;
	char                    *proxy_dir;
	int			proxy_dir_fd;
};

struct spfs_context_s {
	struct work_mode_s	*wm;
	pthread_mutex_t		wm_lock;

	struct fuse_operations	*operations[SPFS_MAX_MODE];

	struct stat		stub_root_stat;

	int			packet_socket;
	struct sockaddr_un	sock_addr;
	pthread_t		sock_pthread;
	bool			single_user;

	int			mnt_ns_fd;
};

int context_init(const char *proxy_dir, int proxy_mnt_ns_pid,
		 spfs_mode_t mode, const char *log_file,
		 const char *socket_path, int verbosity, bool single_user);
int start_socket_thread(void);

void context_fini(void);

struct spfs_context_s *get_context(void);
const struct fuse_operations *get_operations(struct work_mode_s *wm);

int change_work_mode(struct spfs_context_s *ctx, spfs_mode_t mode,
		     const char *path, int ns_pid);
int set_work_mode(struct spfs_context_s *ctx, spfs_mode_t mode,
		  const char *path, int mnt_ns_pid);
int wait_mode_change(int current_mode);

const struct work_mode_s *ctx_work_mode(void);
struct work_mode_s *get_work_mode(void);
void put_work_mode(struct work_mode_s *wm);

extern int spfs_execute_cmd(int sock, void *data, void *package, size_t psize);

static inline spfs_mode_t spfs_mode(const char *mode, const char *path)
{
	if (!strcmp(mode, "stub"))
		return SPFS_STUB_MODE;
	if (!strcmp(mode, "proxy")) {
		if (!path) {
			printf("Proxy directory path wasn't provided\n");
			return SPFS_INVALID_MODE;
		}
		if (!strlen(path)) {
			printf("Proxy directory path is empty\n");
			return SPFS_INVALID_MODE;
		}
		return SPFS_PROXY_MODE;
	}
	printf("Unknown mode: %s\n", mode);
	return SPFS_INVALID_MODE;
}
#endif
