#ifndef _STDDEF_H
#define _STDDEF_H

#undef NULL
#ifdef __cplusplus
    #define NULL 0
#else
    #define NULL ((void *)0)
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
    #ifdef __SIZE_TYPE__
        typedef __SIZE_TYPE__ size_t;
    #else
        typedef unsigned long size_t;
    #endif
#endif

#ifndef _PTRDIFF_T_DEFINED
#define _PTRDIFF_T_DEFINED
    #ifdef __PTRDIFF_TYPE__
        typedef __PTRDIFF_TYPE__ ptrdiff_t;
    #else
        typedef long ptrdiff_t;
    #endif
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
    #ifndef __cplusplus
        #ifdef __WCHAR_TYPE__
            typedef __WCHAR_TYPE__ wchar_t;
        #else
            typedef int wchar_t;
        #endif
    #endif
#endif

/* 
 * 5. offsetof
 * Макрос возвращает смещение поля внутри структуры в байтах.
 * GCC имеет встроенную (безопасную) реализацию. Если её нет, используем классический хак.
 */
#undef offsetof
#ifdef __GNUC__
    #define offsetof(TYPE, MEMBER) __builtin_offsetof(TYPE, MEMBER)
#else
    #define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#endif /* _STDDEF_H */