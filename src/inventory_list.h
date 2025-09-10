#ifndef INVENTORY_LIST_H
#define INVENTORY_LIST_H
#include "inventory_array.h"

typedef struct Node {
    Item item;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int n;
    int next_id;
} InventoryList;

void init_inventory_list(InventoryList *l);
int add_item_list_head(InventoryList *l, const char *name, ItemType type, int priority);
int add_item_list_tail(InventoryList *l, const char *name, ItemType type, int priority);
int remove_item_list(InventoryList *l, int id);
Node* find_item_list_seq(InventoryList *l, const char *name);
void list_inventory_list(InventoryList *l);
void free_inventory_list(InventoryList *l);
#endif
