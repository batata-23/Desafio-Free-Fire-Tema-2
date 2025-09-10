#ifndef INVENTORY_ARRAY_H
#define INVENTORY_ARRAY_H

#define NAME_MAX 64
#define MAX_ITEMS 256

typedef enum { FOOD=0, WEAPON=1, TOOL=2 } ItemType;

typedef struct {
    int id;
    char name[NAME_MAX];
    ItemType type;
    int priority; // menor = mais importante
} Item;

// Vetor estático com operações básicas
typedef struct {
    Item items[MAX_ITEMS];
    int n;
    int next_id;
} InventoryArray;

void init_inventory_array(InventoryArray *inv);
int add_item_array(InventoryArray *inv, const char *name, ItemType type, int priority);
int remove_item_array(InventoryArray *inv, int id);
int find_item_array_seq(InventoryArray *inv, const char *name); // busca sequencial
void list_inventory_array(InventoryArray *inv);
