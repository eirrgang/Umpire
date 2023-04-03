// typesUmpire.h
// This file is generated by Shroud 0.12.2. Do not edit.
// Copyright (c) 2016-23, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
// For C users and C++ implementation

#ifndef TYPESUMPIRE_H
#define TYPESUMPIRE_H

#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

// helper capsule_data_helper
struct s_umpire_SHROUD_capsule_data {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_SHROUD_capsule_data umpire_SHROUD_capsule_data;

/* helper ShroudTypeDefines */
/* Shroud type defines */
#define SH_TYPE_SIGNED_CHAR 1
#define SH_TYPE_SHORT       2
#define SH_TYPE_INT         3
#define SH_TYPE_LONG        4
#define SH_TYPE_LONG_LONG   5
#define SH_TYPE_SIZE_T      6

#define SH_TYPE_UNSIGNED_SHORT       SH_TYPE_SHORT + 100
#define SH_TYPE_UNSIGNED_INT         SH_TYPE_INT + 100
#define SH_TYPE_UNSIGNED_LONG        SH_TYPE_LONG + 100
#define SH_TYPE_UNSIGNED_LONG_LONG   SH_TYPE_LONG_LONG + 100

#define SH_TYPE_INT8_T      7
#define SH_TYPE_INT16_T     8
#define SH_TYPE_INT32_T     9
#define SH_TYPE_INT64_T    10

#define SH_TYPE_UINT8_T    SH_TYPE_INT8_T + 100
#define SH_TYPE_UINT16_T   SH_TYPE_INT16_T + 100
#define SH_TYPE_UINT32_T   SH_TYPE_INT32_T + 100
#define SH_TYPE_UINT64_T   SH_TYPE_INT64_T + 100

/* least8 least16 least32 least64 */
/* fast8 fast16 fast32 fast64 */
/* intmax_t intptr_t ptrdiff_t */

#define SH_TYPE_FLOAT        22
#define SH_TYPE_DOUBLE       23
#define SH_TYPE_LONG_DOUBLE  24
#define SH_TYPE_FLOAT_COMPLEX       25
#define SH_TYPE_DOUBLE_COMPLEX      26
#define SH_TYPE_LONG_DOUBLE_COMPLEX 27

#define SH_TYPE_BOOL       28
#define SH_TYPE_CHAR       29
#define SH_TYPE_CPTR       30
#define SH_TYPE_STRUCT     31
#define SH_TYPE_OTHER      32

// helper array_context
struct s_umpire_SHROUD_array {
    umpire_SHROUD_capsule_data cxx;      /* address of C++ memory */
    union {
        const void * base;
        const char * ccharp;
    } addr;
    int type;        /* type of element */
    size_t elem_len; /* bytes-per-item or character len in c++ */
    size_t size;     /* size of data in c++ */
    int rank;        /* number of dimensions, 0=scalar */
    long shape[7];
};
typedef struct s_umpire_SHROUD_array umpire_SHROUD_array;

// helper capsule_umpire_allocator
struct s_umpire_allocator {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_allocator umpire_allocator;

// helper capsule_umpire_resourcemanager
struct s_umpire_resourcemanager {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_resourcemanager umpire_resourcemanager;

// helper capsule_umpire_strategy_allocationadvisor
struct s_umpire_strategy_allocationadvisor {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_strategy_allocationadvisor umpire_strategy_allocationadvisor;

// helper capsule_umpire_strategy_allocationprefetcher
struct s_umpire_strategy_allocationprefetcher {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_strategy_allocationprefetcher umpire_strategy_allocationprefetcher;

// helper capsule_umpire_strategy_dynamicpoollist
struct s_umpire_strategy_dynamicpoollist {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_strategy_dynamicpoollist umpire_strategy_dynamicpoollist;

// helper capsule_umpire_strategy_fixedpool
struct s_umpire_strategy_fixedpool {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_strategy_fixedpool umpire_strategy_fixedpool;

// helper capsule_umpire_strategy_namedallocationstrategy
struct s_umpire_strategy_namedallocationstrategy {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_strategy_namedallocationstrategy umpire_strategy_namedallocationstrategy;

// helper capsule_umpire_strategy_quickpool
struct s_umpire_strategy_quickpool {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_strategy_quickpool umpire_strategy_quickpool;

// helper capsule_umpire_strategy_threadsafeallocator
struct s_umpire_strategy_threadsafeallocator {
    void *addr;     /* address of C++ memory */
    int idtor;      /* index of destructor */
};
typedef struct s_umpire_strategy_threadsafeallocator umpire_strategy_threadsafeallocator;

void umpire_SHROUD_memory_destructor(umpire_SHROUD_capsule_data *cap);

#ifdef __cplusplus
}
#endif

#endif  // TYPESUMPIRE_H
