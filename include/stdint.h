#ifndef _STDINT_H
#define _STDINT_H

typedef __INT8_TYPE__          int8_t;
typedef __UINT8_TYPE__         uint8_t;
typedef __INT16_TYPE__         int16_t;
typedef __UINT16_TYPE__        uint16_t;
typedef __INT32_TYPE__         int32_t;
typedef __UINT32_TYPE__        uint32_t;
typedef __INT64_TYPE__         int64_t;
typedef __UINT64_TYPE__        uint64_t;

typedef __INT_LEAST8_TYPE__    int_least8_t;
typedef __UINT_LEAST8_TYPE__   uint_least8_t;
typedef __INT_LEAST16_TYPE__   int_least16_t;
typedef __UINT_LEAST16_TYPE__  uint_least16_t;
typedef __INT_LEAST32_TYPE__   int_least32_t;
typedef __UINT_LEAST32_TYPE__  uint_least32_t;
typedef __INT_LEAST64_TYPE__   int_least64_t;
typedef __UINT_LEAST64_TYPE__  uint_least64_t;

typedef __INT_FAST8_TYPE__     int_fast8_t;
typedef __UINT_FAST8_TYPE__    uint_fast8_t;
typedef __INT_FAST16_TYPE__    int_fast16_t;
typedef __UINT_FAST16_TYPE__    uint_fast16_t;
typedef __INT_FAST32_TYPE__    int_fast32_t;
typedef __UINT_FAST32_TYPE__    uint_fast32_t;
typedef __INT_FAST64_TYPE__    int_fast64_t;
typedef __UINT_FAST64_TYPE__    uint_fast64_t;

typedef __INTPTR_TYPE__        intptr_t;
typedef __UINTPTR_TYPE__       uintptr_t;

typedef __INTMAX_TYPE__        intmax_t;
typedef __UINTMAX_TYPE__       uintmax_t;

#define INT8_MIN               (-__INT8_MAX__ - 1)
#define INT16_MIN              (-__INT16_MAX__ - 1)
#define INT32_MIN              (-__INT32_MAX__ - 1)
#define INT64_MIN              (-__INT64_MAX__ - 1)

#define INT8_MAX               __INT8_MAX__
#define INT16_MAX              __INT16_MAX__
#define INT32_MAX              __INT32_MAX__
#define INT64_MAX              __INT64_MAX__

#define UINT8_MAX              __UINT8_MAX__
#define UINT16_MAX             __UINT16_MAX__
#define UINT32_MAX             __UINT32_MAX__
#define UINT64_MAX             __UINT64_MAX__

#if __INTPTR_WIDTH__ == 64
#  define INTPTR_MIN           (-9223372036854775807L - 1)
#  define INTPTR_MAX           9223372036854775807L
#  define UINTPTR_MAX          18446744073709551615UL
#else
#  define INTPTR_MIN           (-2147483647 - 1)
#  define INTPTR_MAX           2147483647
#  define UINTPTR_MAX          4294967295U
#endif

#define INT8_C(c)              c
#define INT16_C(c)             c
#define INT32_C(c)             c
#define INT64_C(c)             c ## LL

#define UINT8_C(c)             c
#define UINT16_C(c)            c
#define UINT32_C(c)            c ## U
#define UINT64_C(c)            c ## ULL

#define INTMAX_C(c)            c ## LL
#define UINTMAX_C(c)           c ## ULL

#endif /* _STDINT_H */