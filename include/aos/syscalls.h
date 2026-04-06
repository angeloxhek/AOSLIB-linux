#ifndef _AOS_SYSCALLS_H
#define _AOS_SYSCALLS_H

#include <aos/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SYS_EXIT                     1
#define SYS_IPC_SEND                 2
#define SYS_IPC_RECV                 3
#define SYS_REGISTER_DRIVER          4
#define SYS_GET_DRIVER_TID           5
#define SYS_GET_DRIVER_TID_BY_NAME   6
#define SYS_GET_SYSTEM_INFO          7
#define SYS_SBRK                     8
#define SYS_BLOCK_READ               9
#define SYS_BLOCK_WRITE             10
#define SYS_GET_DISK_COUNT          11
#define SYS_GET_DISK_INFO           12
#define SYS_GET_PARTITION_COUNT     13
#define SYS_GET_PARTITION_INFO      14
#define SYS_YIELD                   15
#define SYS_PRINT                   16
#define SYS_RESERVED1               17
#define SYS_RESERVED2               18
#define SYS_SHM_ALLOC               19
#define SYS_SHM_ALLOW               20
#define SYS_SHM_MAP                 21
#define SYS_SHM_FREE                22
#define SYS_GET_PID_LIST            23
#define SYS_GET_PROC_INFO           24
#define SYS_GET_TID_LIST            25
#define SYS_GET_THREAD_INFO         26

int64_t syscall(uint64_t nr, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);
void* syscall_sbrk(int64_t increment);
void sysprint(const char* str);
void thread_yield(void);

#ifdef __cplusplus
}
#endif

#endif /* _AOS_SYSCALLS_H */