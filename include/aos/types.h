#ifndef _AOS_TYPES_H
#define _AOS_TYPES_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Коды результатов системных вызовов */
#define SYS_RES_OK                   0
#define SYS_RES_INVALID             -1
#define SYS_RES_NO_PERM             -2
#define SYS_RES_ALREADY             -3
#define SYS_RES_RESERVED1           -4
#define SYS_RES_QUEUE_EMPTY         -5
#define SYS_RES_DSK_ERR             -6
#define SYS_RES_RANGE               -7
#define SYS_RES_NOTFOUND            -8
#define SYS_RES_KERNEL_ERR         -99

/* Статусы завершения */
#define STAT_OK                      0
#define STAT_STACK_SMASHING       -256
#define STAT_NO_ENTRY             -257

/* Thread Control Block (TCB) */
typedef struct {
    void*    tcb_self;      // 0x00: Указатель на себя (требование ABI)
    uint64_t tid;           // 0x08: Идентификатор потока (TID)
    uint64_t pid;           // 0x10: Идентификатор процесса (PID)
    int32_t  thread_errno;  // 0x18: Потокобезопасная переменная ошибки
    uint32_t pending_msgs;  // 0x1C: Количество непрочитанных IPC-сообщений
    void*    local_heap;    // 0x20: Указатель для быстрого malloc
    uint64_t stack_canary;  // 0x28: Канарейка для безопасности (-fstack-protector)
} aos_tcb_t;

/* Доступ к TCB текущего потока через сегмент FS */
#define AOS_GET_TCB() ((aos_tcb_t __seg_fs *)0)

#ifndef UNUSED
    #define UNUSED(x) (void)(x)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _AOS_TYPES_H */