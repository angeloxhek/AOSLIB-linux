#ifndef _AOS_SYSINFO_H
#define _AOS_SYSINFO_H

#include <aos/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CAN_PRINT (1 << 0)
#define CAN_REGISTER_KERNEL_DRIVERS (1 << 1)
#define KERNEL_PANIC (1 << 2)
#define FSGSBASE (1 << 0)

typedef struct {
    uint64_t uptime;
    uint64_t fs_base;
    uint64_t gs_base;
    uint64_t kernel_gs_base;
    uint32_t flags;
    uint16_t cpu_flags;
} system_info_t;

typedef struct {
    uint32_t pid;
    char     name[32];
    uint8_t  state;
    uint64_t heap_limit;
    uint64_t threads_count;
} proc_info_user_t;

typedef struct {
    uint64_t tid;
    uint32_t parent_pid;
    uint8_t  state;
    int      waiting_for_msg; 
    uint64_t wake_up_time;
} thread_info_user_t;

int get_sysinfo(system_info_t* info);
int get_proc_info(uint32_t pid, proc_info_user_t* out_info);
int get_thread_info(uint32_t pid, thread_info_user_t* out_info);
int get_pid_list(uint32_t* buff, uint64_t count);
int get_tid_list(uint32_t pid, uint32_t* buff, uint64_t count);

uint64_t shm_alloc(uint64_t size_bytes, void** out_vaddr);
int shm_allow(uint64_t shm_id, uint64_t target_tid);
void* shm_map(uint64_t shm_id);
int shm_free(uint64_t shm_id);

#ifdef __cplusplus
}
#endif

#endif /* _AOS_SYSINFO_H */