# Survival Mini-Game - Projeto em C (Estruturas e Algoritmos)

Este projeto é um mini-game educacional em C inspirado em modos de sobrevivência (estilo Free Fire).
Foco: listas estáticas e dinâmicas, listas encadeadas, operações de inserção/remoção/busca,
comparação entre vetor e lista encadeada, busca binária (iterativa e recursiva) e algoritmos de ordenação
(com contagem de comparações para análise de eficiência).

## Estrutura do repositório
```
/SurvivalProject
  /src
    main.c
    inventory_array.c
    inventory_array.h
    inventory_list.c
    inventory_list.h
    sort_search.c
    sort_search.h
  Makefile
  README.md
```
## Como compilar
No diretório do projeto execute:
```
make
```
Isso gera o executável `survival`.

## Como usar
Rode `./survival`. Há um menu com opções para:
- Adicionar/remover/listar itens (vetor e lista encadeada)
- Ordenar inventário (Selection Sort e Insertion Sort)
- Buscar itens (busca sequencial, busca binária iterativa e recursiva)
- Comparar desempenho entre vetor e lista encadeada (medido por número de operações/comparações)
- Exemplo de mapa/itens já carregados para testes

## Observações
- Código modular, comentado e pensado para entrega acadêmica.
- Usa malloc/free e tratamento básico de erros.
- Para extensão: adicionar outras ordenações (QuickSort), persistência, e interface mais rica.
