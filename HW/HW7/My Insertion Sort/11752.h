//
// Created by 贾松昊 on 2017/12/21.
//

#ifndef TEST_FOR_C_FUNCTION_H
#define TEST_FOR_C_FUNCTION_H

#include <stdio.h>

int compare(const void* a, const void* b);

void assign(char* x, char* y, size_t size);

void mysort(void* arr, size_t count, size_t size, int (*cmp) (const void*, const void*));

#endif //TEST_FOR_C_FUNCTION_H
