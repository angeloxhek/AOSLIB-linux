#ifndef _AOS_TYPES_H
#define _AOS_TYPES_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SYS_RES_OK                    0
#define SYS_RES_INVALID              -1
#define SYS_RES_NO_PERM              -2
#define SYS_RES_ALREADY              -3
#define SYS_RES_DRV_ERR              -4
#define SYS_RES_QUEUE_EMPTY          -5
#define SYS_RES_DSK_ERR              -6
#define SYS_RES_RANGE                -7
#define SYS_RES_NOTFOUND             -8
#define SYS_RES_KERNEL_ERR          -99

#define STAT_OK                       0
#define STAT_STACK_SMASHING        -256
#define STAT_NO_ENTRY              -257
#define STAT_OOM                   -258

typedef struct {
    uint64_t uptime;
    uint64_t boot_time;
    uint64_t frequency;
} time_info_t;

typedef enum : uint8_t {
	STARTUP_MAIN = 1,
	STARTUP_DRIVERMAIN
} startup_type_t;

typedef struct {
	startup_type_t type;
	union {
		struct {
			int argc;
			int envc;
			char** argv;
			char** envp;
		} main;
		struct {
			void* reserved1;
			void* reserved2;
		} driver;
	} data;
} startup_info_t;

typedef struct {
    void*       tcb_self;
    uint64_t    tid;
    uint64_t    pid;
    int32_t     thread_errno; // Reserved
    uint32_t    pending_msgs;
    void*       local_heap;   // Reserved
    uint64_t    stack_canary;
	time_info_t startup_time;
} aos_tcb_t;

#define AOS_GET_TCB() ((aos_tcb_t __seg_fs *)0)

#ifndef UNUSED
    #define UNUSED(x) (void)(x)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _AOS_TYPES_H */