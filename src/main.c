#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory_array.h"
#include "inventory_list.h"
#include "sort_search.h"

void seed_data_array(InventoryArray *inv) {
    add_item_array(inv, "Bandage", TOOL, 3);
    add_item_array(inv, "AK47", WEAPON, 1);
    add_item_array(inv, "Apple", FOOD, 5);
    add_item_array(inv, "Helmet", TOOL, 2);
    add_item_array(inv, "Boots", TOOL, 4);
}

void seed_data_list(InventoryList *l) {
    add_item_list_tail(l, "Bandage", TOOL, 3);
    add_item_list_tail(l, "AK47", WEAPON, 1);
    add_item_list_tail(l, "Apple", FOOD, 5);
    add_item_list_tail(l, "Helmet", TOOL, 2);
    add_item_list_tail(l, "Boots", TOOL, 4);
}

void print_menu() {
    printf("\n=== Survival Mini-Game - Estruturas e Algoritmos ===\n");
    printf("1) Listar inventário (vetor)\n");
    printf("2) Listar inventário (lista)\n");
    printf("3) Add item ao vetor\n");
    printf("4) Add item à lista (tail)\n");
    printf("5) Remover item do vetor (por id)\n");
    printf("6) Remover item da lista (por id)\n");
    printf("7) Ordenar vetor (Selection Sort) e mostrar comparações\n");
    printf("8) Ordenar vetor (Insertion Sort) e mostrar comparações\n");
    printf("9) Busca sequencial no vetor\");
    printf("\n10) Busca binária iterativa (vetor ordenado)\n");
    printf("11) Busca binária recursiva (vetor ordenado)\n");
    printf("12) Comparar busca sequencial (lista) vs vetor (mesmo nome)\n");
    printf("0) Sair\n");
    printf("Escolha: ");
}

int main() {
    InventoryArray inv;
    InventoryList list;
    init_inventory_array(&inv);
    init_inventory_list(&list);
    seed_data_array(&inv);
    seed_data_list(&list);

    int opt;
    while (1) {
        print_menu();
        if (scanf("%d", &opt) != 1) { while(getchar()!='\n'); printf("Entrada inválida\n"); continue; }
        while(getchar()!='\n');
        if (opt == 0) break;
        if (opt == 1) list_inventory_array(&inv);
        else if (opt == 2) list_inventory_list(&list);
        else if (opt == 3) {
            char name[64]; int type, pr;
            printf("Nome: "); if (!fgets(name, sizeof(name), stdin)) continue; name[strcspn(name, "\n")]='\0';
            printf("Tipo (0=FOOD 1=WEAPON 2=TOOL): "); if (scanf("%d", &type)!=1) { while(getchar()!='\n'); continue; }
            printf("Prioridade (int, menor = mais importante): "); if (scanf("%d", &pr)!=1) { while(getchar()!='\n'); continue; }
            while(getchar()!='\n');
            int id = add_item_array(&inv, name, (ItemType)type, pr);
            if (id) printf("Item adicionado com id %d\n", id); else printf("Erro ao adicionar\n"); 
        }
        else if (opt == 4) {
            char name[64]; int type, pr;
            printf("Nome: "); if (!fgets(name, sizeof(name), stdin)) continue; name[strcspn(name, "\n")]='\0';
            printf("Tipo (0=FOOD 1=WEAPON 2=TOOL): "); if (scanf("%d", &type)!=1) { while(getchar()!='\n'); continue; }
            printf("Prioridade (int, menor = mais importante): "); if (scanf("%d", &pr)!=1) { while(getchar()!='\n'); continue; }
            while(getchar()!='\n');
            int id = add_item_list_tail(&list, name, (ItemType)type, pr);
            if (id) printf("Item adicionado com id %d\n", id); else printf("Erro ao adicionar\n"); 
        }
        else if (opt == 5) {
            int id; printf("ID para remover do vetor: "); if (scanf("%d", &id)!=1) { while(getchar()!='\n'); continue; }
            while(getchar()!='\n');
            if (remove_item_array(&inv, id)) printf("Removido\n"); else printf("ID não encontrado\n");
        }
        else if (opt == 6) {
            int id; printf("ID para remover da lista: "); if (scanf("%d", &id)!=1) { while(getchar()!='\n'); continue; }
            while(getchar()!='\n');
            if (remove_item_list(&list, id)) printf("Removido\n"); else printf("ID não encontrado\n");
        }
        else if (opt == 7) {
            // copy to temp array for sorting comparison
            Item tmp[ MAX_ITEMS ];
            for (int i=0;i<inv.n;i++) tmp[i]=inv.items[i];
            long comps = selection_sort_items(tmp, inv.n);
            printf("Selection Sort feito em cópia. Comparações: %ld\n", comps);
        }
        else if (opt == 8) {
            Item tmp[ MAX_ITEMS ];
            for (int i=0;i<inv.n;i++) tmp[i]=inv.items[i];
            long comps = insertion_sort_items(tmp, inv.n);
            printf("Insertion Sort feito em cópia. Comparações: %ld\n", comps);
        }
        else if (opt == 9) {
            char name[64]; printf("Nome a buscar (sequencial no vetor): "); if (!fgets(name, sizeof(name), stdin)) continue; name[strcspn(name, "\n")]=0;
            int idx = find_item_array_seq(&inv, name);
            if (idx>=0) printf("Encontrado no vetor: ID=%d\n", inv.items[idx].id);
            else printf("Não encontrado no vetor\n");
        }
        else if (opt == 10 || opt == 11) {
            // ensure sorted copy by name
            Item tmp[ MAX_ITEMS ];
            for (int i=0;i<inv.n;i++) tmp[i]=inv.items[i];
            insertion_sort_items(tmp, inv.n);
            char name[64]; printf("Nome a buscar (binária): "); if (!fgets(name, sizeof(name), stdin)) continue; name[strcspn(name, "\n")]=0;
            long comps = 0;
            int res = -1;
            if (opt == 10) res = binary_search_iterative(tmp, inv.n, name, &comps);
            else res = binary_search_recursive(tmp, 0, inv.n-1, name, &comps);
            if (res >= 0) printf("Encontrado (binária) em índice %d após %ld comparações. ID=%d\n", res, comps, tmp[res].id);
            else printf("Não encontrado (binária). Comparações: %ld\n", comps);
        }
        else if (opt == 12) {
            char name[64]; printf("Nome a buscar: "); if (!fgets(name, sizeof(name), stdin)) continue; name[strcspn(name, "\n")]=0;
            // vetor seq
            long comps_v = 0;
            int idx_v = -1;
            for (int i=0;i<inv.n;i++) { comps_v++; if (strcmp(inv.items[i].name, name)==0) { idx_v=i; break; } }
            // lista seq
            long comps_l = 0;
            Node *found = list.head;
            int pos = -1; int i=0;
            while (found) {
                comps_l++;
                if (strcmp(found->item.name, name)==0) { pos = i; break; }
                found = found->next; i++;
            }
            printf("Vetor: idx=%d, comparações=%ld\n", idx_v, comps_v);
            printf("Lista: pos=%d, comparações=%ld\n", pos, comps_l);
        }
        else printf("Opção inválida\n");
    }

    free_inventory_list(&list);
    return 0;
}
