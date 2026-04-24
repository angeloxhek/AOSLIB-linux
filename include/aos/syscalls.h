#ifndef _AOS_SYSCALLS_H
#define _AOS_SYSCALLS_H

#include <aos/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SYS_EXIT                      1
#define SYS_IPC_SEND                  2
#define SYS_IPC_TRYRECV               3
#define SYS_IPC_RECV                  4
#define SYS_REGISTER_DRIVER           5
#define SYS_GET_DRIVER_TID            6
#define SYS_GET_DRIVER_TID_BY_NAME    7
#define SYS_GET_SYSTEM_INFO           8
#define SYS_SBRK                      9
#define SYS_BLOCK_READ               10
#define SYS_BLOCK_WRITE              11
#define SYS_GET_DISK_COUNT           12
#define SYS_GET_DISK_INFO            13
#define SYS_GET_PARTITION_COUNT      14
#define SYS_GET_PARTITION_INFO       15
#define SYS_YIELD                    16
#define SYS_PRINT                    17
#define SYS_SHM_ALLOC                18
#define SYS_SHM_ALLOW                19
#define SYS_SHM_MAP                  20
#define SYS_SHM_FREE                 21
#define SYS_GET_PID_LIST             22
#define SYS_GET_PROC_INFO            23
#define SYS_GET_TID_LIST             24
#define SYS_GET_THREAD_INFO          25
#define SYS_GET_TIME_INFO            26
#define SYS_SPAWN                    27
#define SYS_FORK                     28

int64_t syscall(uint64_t nr, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);
void* syscall_sbrk(int64_t increment);
void sysprint(const char* str);
void thread_yield(void);

#ifdef __cplusplus
}
#endif

#endif /* _AOS_SYSCALLS_H */