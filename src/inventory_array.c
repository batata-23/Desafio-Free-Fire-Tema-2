#include "inventory_array.h"
#include <string.h>
#include <stdio.h>

void init_inventory_array(InventoryArray *inv) {
    inv->n = 0;
    inv->next_id = 1;
}

int add_item_array(InventoryArray *inv, const char *name, ItemType type, int priority) {
    if (inv->n >= MAX_ITEMS) return 0;
    Item *it = &inv->items[inv->n++];
    it->id = inv->next_id++;
    strncpy(it->name, name, NAME_MAX-1);
    it->name[NAME_MAX-1] = '\0';
    it->type = type;
    it->priority = priority;
    return it->id;
}

int remove_item_array(InventoryArray *inv, int id) {
    for (int i=0;i<inv->n;i++) {
        if (inv->items[i].id == id) {
            // shift left
            for (int j=i;j<inv->n-1;j++) inv->items[j] = inv->items[j+1];
            inv->n--;
            return 1;
        }
    }
    return 0;
}

int find_item_array_seq(InventoryArray *inv, const char *name) {
    for (int i=0;i<inv->n;i++) {
        if (strcmp(inv->items[i].name, name) == 0) return i;
    }
    return -1;
}

void list_inventory_array(InventoryArray *inv) {
    printf("-- Inventário (vetor) [%d itens] --\n", inv->n);
    for (int i=0;i<inv->n;i++) {
        Item *it = &inv->items[i];
        printf("ID:%d | %s | Tipo:%d | Prioridade:%d\n", it->id, it->name, it->type, it->priority);
    }
}
