#ifndef SORT_SEARCH_H
#define SORT_SEARCH_H
#include "inventory_array.h"

// Sorting with comparison counting
long selection_sort_items(Item *arr, int n); // returns comparisons count
long insertion_sort_items(Item *arr, int n);

// Binary search (assumes arr sorted by name)
// returns index or -1. counts via pointer parameter.
int binary_search_iterative(Item *arr, int n, const char *name, long *comparisons);
int binary_search_recursive(Item *arr, int left, int right, const char *name, long *comparisons);

#endif
