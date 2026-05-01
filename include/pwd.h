#ifndef _PWD_H
#define _PWD_H

#include <stddef.h>
#include <stdint.h>

typedef uint32_t uid_t;
typedef uint32_t gid_t;

struct passwd {
    char   *pw_name;
    char   *pw_passwd;
    uid_t   pw_uid;
    gid_t   pw_gid;
    char   *pw_gecos;
    char   *pw_dir;
    char   *pw_shell;
};

int getpwnam_r(const char *name, struct passwd *pwd, char *buffer, size_t buflen, struct passwd **result);
struct passwd *getpwnam(const char *name);
int getpwuid_r(uid_t uid, struct passwd *pwd, char *buffer, size_t buflen, struct passwd **result);
struct passwd *getpwuid(uid_t uid);

#endif