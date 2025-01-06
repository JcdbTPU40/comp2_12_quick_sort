#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

static void swap(item* a, item* b)
{
    item temp = *a;
    *a = *b;
    *b = temp;
}

static item* partition(item* low, item* high)
{
    int pivot = high->key;
    item* i = low - 1;

    for (item* j = low; j < high; ++j)
    {
        if (j->key < pivot)
        {
            ++i;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return i + 1;
}

static void quick_sort_recursive(item* low, item* high)
{
    if (low < high)
    {
        item* pivot = partition(low, high);
        quick_sort_recursive(low, pivot - 1);
        quick_sort_recursive(pivot + 1, high);
    }
}

bool quick_sort(item* begin, const item* end)
{
    if (!begin || !end || begin >= end)
    {
        return false;
    }

    quick_sort_recursive(begin, (item*)(end - 1));
    return true;
}

