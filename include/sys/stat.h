#ifndef _SYS_STAT_H
#define _SYS_STAT_H

#include <stdint.h>
#include <stddef.h>
#include <time.h>
#include <sys/types.h>

struct stat {
    uint32_t st_dev;
    uint64_t st_ino;
    mode_t   st_mode;
    uint16_t st_nlink;
    uint32_t st_uid;
    uint32_t st_gid;
    int64_t  st_size;
    time_t   st_atime;
    time_t   st_mtime;
    time_t   st_ctime;
};

#define S_IFDIR  0x0040000
#define S_IFREG  0x0100000

#define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#define S_IFMT   0x170000

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);

#endif