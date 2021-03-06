## Process this file with automake to produce Makefile.in
CLEANFILES = `find . -name "*~"`

AM_CFLAGS = -Wall -Werror -ggdb -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64
AM_MAKEFLAGS = --no-print-directory

sbin_PROGRAMS = bin/spfs bin/spfs-client bin/spfs-manager

noinst_PROGRAMS = bin/swapfd

bin_spfs_SOURCES =		spfs/main.c			\
				spfs/gateway.c			\
				spfs/proxy.c			\
				spfs/stub.c			\
				spfs/context.c			\
				spfs/interface.c		\
				spfs/xattr.c			\
								\
				spfs/interface.h		\
				spfs/context.h			\
				spfs/xattr.h			\
								\
				src/util.c			\
				src/log.c			\
				src/socket.c			\
				src/futex.c			\
				src/namespaces.c		\
								\
				include/log.h			\
				include/socket.h		\
				include/list.h			\
				include/util.h			\
				include/namespaces.h		\
				include/futex.h


bin_spfs_client_SOURCES =	client/main.c			\
								\
				src/socket.c			\
				src/log.c			\
				src/util.c			\
								\
				spfs/interface.h		\
				spfs/context.h			\
								\
				include/socket.h		\
				include/util.h


bin_spfs_manager_SOURCES =	manager/main.c			\
				manager/context.c		\
				manager/interface.c		\
				manager/replace.c		\
				manager/spfs.c			\
				manager/freeze.c		\
				manager/swapfd.c		\
				manager/swap.c			\
				manager/trees.c			\
				manager/processes.c		\
				manager/cgroup.c		\
				manager/mount.c			\
				manager/file_obj.c		\
				manager/link_remap.c		\
				manager/unix-sockets.c		\
								\
				manager/context.h		\
				manager/interface.h		\
				manager/replace.h		\
				manager/spfs.h			\
				manager/freeze.h		\
				manager/swapfd.h		\
				manager/swap.h			\
				manager/trees.h			\
				manager/processes.h		\
				manager/cgroup.h		\
				manager/mount.h			\
				manager/file_obj.h		\
				manager/link_remap.h		\
				manager/unix-sockets.h		\
								\
				src/util.c			\
				src/socket.c			\
				src/ipc.c			\
				src/log.c			\
				src/shm.c			\
				src/ptrace.c			\
				src/pie-util-fd.c		\
				src/futex.c			\
				src/namespaces.c		\
				src/netlink.c			\
								\
				spfs/interface.h		\
				spfs/context.h			\
								\
				include/log.h			\
				include/ipc.h			\
				include/socket.h		\
				include/list.h			\
				include/shm.h			\
				include/ptrace.h		\
				include/pie-util-fd.h		\
				include/util.h			\
				include/namespaces.h		\
				include/futex.h			\
				include/netlink.h

bin_swapfd_SOURCES =		main.c				\
								\
				manager/swapfd.c		\
								\
				manager/swapfd.h		\
								\
				src/util.c			\
				src/log.c			\
				src/ptrace.c			\
				src/pie-util-fd.c		\
								\
				include/log.h			\
				include/util.h
				include/pie-util-fd.h		\
				include/ptrace.h

bin_spfs_manager_LDFLAGS = -Wl,--wrap=nla_parse,--wrap=nlmsg_parse
