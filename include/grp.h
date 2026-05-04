#ifndef _GRP_H
#define _GRP_H

#include <stddef.h>
#include <stdint.h>

typedef uint32_t gid_t;

struct group {
    char   *gr_name;
    char   *gr_passwd;
    gid_t   gr_gid;
    char  **gr_mem;
};

struct group *getgrnam(const char *name);
struct group *getgrgid(gid_t gid);

int getgrnam_r(const char *name, struct group *grp, char *buf, size_t buflen, struct group **result);
int getgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen, struct group **result);

#endif