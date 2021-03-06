#ifndef __SPFS_MANAGER_REPLACE_H_
#define __SPFS_MANAGER_REPLACE_H_

#include <stddef.h>

struct freeze_cgroup_s;

int __replace_resources(struct freeze_cgroup_s *fg, int *ns_fds,
		        const char *source_mnt, dev_t src_dev,
			int src_mnt_ref, int src_mnt_id,
			const char *target_mnt);

int replace_resources(struct freeze_cgroup_s *fg,
		      const char *source_mnt, dev_t src_dev,
		      const char *target_mnt,
		      pid_t ns_pid);

#endif
