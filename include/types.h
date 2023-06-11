#ifndef _TYPES_H
#define _TYPES_H

typedef unsigned int size_t;

typedef char int8;
typedef short int16;
typedef int int32;
typedef long long int64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef int32 pid_t;
typedef int32 dev_t;

typedef u32 time_t;
typedef u32 idx_t;

typedef u16 mode_t; // 文件权限

typedef int32 fd_t;


typedef int32 off_t; // 文件偏移

typedef int err_t; // 错误类型

#endif