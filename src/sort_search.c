#include "sort_search.h"
#include <string.h>
#include <stdio.h>

static int cmp_name(const Item *a, const Item *b) {
    return strcmp(a->name, b->name);
}

long selection_sort_items(Item *arr, int n) {
    long comps = 0;
    for (int i=0;i<n-1;i++) {
        int min = i;
        for (int j=i+1;j<n;j++) {
            comps++;
            if (strcmp(arr[j].name, arr[min].name) < 0) min = j;
        }
        if (min != i) {
            Item tmp = arr[i]; arr[i] = arr[min]; arr[min] = tmp;
        }
    }
    return comps;
}

long insertion_sort_items(Item *arr, int n) {
    long comps = 0;
    for (int i=1;i<n;i++) {
        Item key = arr[i];
        int j = i-1;
        while (j>=0) {
            comps++;
            if (strcmp(arr[j].name, key.name) > 0) {
                arr[j+1] = arr[j];
                j--;
            } else break;
        }
        arr[j+1] = key;
    }
    return comps;
}

int binary_search_iterative(Item *arr, int n, const char *name, long *comparisons) {
    int l = 0, r = n-1;
    *comparisons = 0;
    while (l <= r) {
        int m = l + (r-l)/2;
        (*comparisons)++;
        int c = strcmp(arr[m].name, name);
        if (c == 0) return m;
        if (c < 0) l = m+1;
        else r = m-1;
    }
    return -1;
}

int binary_search_recursive(Item *arr, int left, int right, const char *name, long *comparisons) {
    if (left > right) return -1;
    int mid = left + (right-left)/2;
    (*comparisons)++;
    int c = strcmp(arr[mid].name, name);
    if (c == 0) return mid;
    if (c < 0) return binary_search_recursive(arr, mid+1, right, name, comparisons);
    else return binary_search_recursive(arr, left, mid-1, name, comparisons);
}
