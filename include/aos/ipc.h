#ifndef _AOS_IPC_H
#define _AOS_IPC_H

#include <aos/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    MSG_TYPE_NONE = 0,
    MSG_TYPE_KEYBOARD,
    MSG_TYPE_VFS,
    MSG_TYPE_DATA
} msg_type_t;

typedef enum {
    MSG_SUBTYPE_NONE = 0,
    MSG_SUBTYPE_QUERY,
    MSG_SUBTYPE_SEND,
    MSG_SUBTYPE_RESPONSE
} msg_subtype_t;

typedef struct message_t {
    uint64_t sender_tid;
    uint32_t type;
    uint32_t subtype;
    uint64_t param1;
    uint64_t param2;
    uint64_t param3;
    uint8_t  data[64];
} __attribute__((packed, aligned(8))) message_t;

int64_t __ipc_recv(message_t* out_msg);
int64_t ipc_tryrecv(message_t* out_msg);
int64_t ipc_send(uint64_t dest_tid, message_t* msg);
uint64_t get_ipc_count(void);
void ipc_recv(message_t* out_msg);
void ipc_recv_ex(uint64_t tid, msg_type_t type, msg_subtype_t subtype, message_t* out_msg);
void ipc_seek(int64_t offset, seek_whence_t whence);
int ipc_get_at(uint64_t index, message_t* out);

#ifdef __cplusplus
}
#endif

#endif /* _AOS_IPC_H */