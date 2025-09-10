#include "inventory_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init_inventory_list(InventoryList *l) {
    l->head = NULL;
    l->n = 0;
    l->next_id = 1;
}

static Node* create_node(InventoryList *l, const char *name, ItemType type, int priority) {
    Node *nd = (Node*) malloc(sizeof(Node));
    if (!nd) return NULL;
    nd->item.id = l->next_id++;
    strncpy(nd->item.name, name, NAME_MAX-1);
    nd->item.name[NAME_MAX-1] = '\0';
    nd->item.type = type;
    nd->item.priority = priority;
    nd->next = NULL;
    return nd;
}

int add_item_list_head(InventoryList *l, const char *name, ItemType type, int priority) {
    Node *nd = create_node(l, name, type, priority);
    if (!nd) return 0;
    nd->next = l->head;
    l->head = nd;
    l->n++;
    return nd->item.id;
}

int add_item_list_tail(InventoryList *l, const char *name, ItemType type, int priority) {
    Node *nd = create_node(l, name, type, priority);
    if (!nd) return 0;
    if (!l->head) l->head = nd;
    else {
        Node *cur = l->head;
        while (cur->next) cur = cur->next;
        cur->next = nd;
    }
    l->n++;
    return nd->item.id;
}

int remove_item_list(InventoryList *l, int id) {
    Node *cur = l->head, *prev = NULL;
    while (cur) {
        if (cur->item.id == id) {
            if (prev) prev->next = cur->next;
            else l->head = cur->next;
            free(cur);
            l->n--;
            return 1;
        }
        prev = cur; cur = cur->next;
    }
    return 0;
}

Node* find_item_list_seq(InventoryList *l, const char *name) {
    Node *cur = l->head;
    while (cur) {
        if (strcmp(cur->item.name, name) == 0) return cur;
        cur = cur->next;
    }
    return NULL;
}

void list_inventory_list(InventoryList *l) {
    printf("-- Inventário (lista encadeada) [%d itens] --\n", l->n);
    Node *cur = l->head;
    while (cur) {
        printf("ID:%d | %s | Tipo:%d | Prioridade:%d\n", cur->item.id, cur->item.name, cur->item.type, cur->item.priority);
        cur = cur->next;
    }
}

void free_inventory_list(InventoryList *l) {
    Node *cur = l->head;
    while (cur) {
        Node *nx = cur->next;
        free(cur);
        cur = nx;
    }
    l->head = NULL;
    l->n = 0;
}
