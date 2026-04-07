#ifndef _AOS_DRIVER_H
#define _AOS_DRIVER_H

#include <aos/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DT_NONE = 0,
    DT_KEYBOARD,
    DT_VFS,
    DT_VIDEO,
    DT_USER = 100
} driver_type_t;

typedef enum {
    DISK_TYPE_UNKNOWN = 0,
    DISK_TYPE_IDE,
    DISK_TYPE_AHCI,
    DISK_TYPE_NVME,
    DISK_TYPE_USB,
    DISK_TYPE_RAM
} disk_connection_type_t;

typedef struct {
    uint64_t id;
    uint64_t total_sectors;
    uint32_t sector_size;
    disk_connection_type_t type;
    char model[40];
    uint8_t is_removable;
} disk_info_t;

typedef struct {
    uint64_t id;
    uint64_t parent_disk_id;
    uint64_t start_lba;
    uint64_t size_sectors;
    uint8_t  partition_type;
    uint8_t  bootable;
} partition_info_t;

typedef struct {
    uint64_t disk_id;
    uint64_t partition_offset_lba;
    uint64_t size_sectors;
} block_dev_t;

int64_t register_driver(driver_type_t type, const char* name);
uint64_t get_driver_tid(driver_type_t type);
uint64_t get_driver_tid_name(const char* name);

uint8_t get_scancode(void);
uint64_t get_disk_count(void);
uint64_t get_partition_count(void);
uint64_t get_disk_info(uint64_t index, disk_info_t* pinfo);
uint64_t get_partition_info(uint64_t index, partition_info_t* pinfo);
int64_t block_read(block_dev_t* dev, uint64_t lba, uint64_t count, void* buffer);
int64_t block_write(block_dev_t* dev, uint64_t lba, uint64_t count, void* buffer);

#ifdef __cplusplus
}
#endif

#endif /* _AOS_DRIVER_H */