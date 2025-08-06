//
// Created by Murilo on 05/08/2025.
//

#ifndef UNTITLED6_HASH_TABLE_H
#define UNTITLED6_HASH_TABLE_H

#include "stdio.h"
#include <malloc.h>



typedef struct table_node
{
    int node_value;
    struct table_node *node_below;
} table_node;

typedef struct hash_table
{
    int table_size;
    table_node **table_indexes;
} hash_table;


hash_table initiliaze_table(int table_size);

int Hash_Func(int value, int table_size);

void insert_table_node(int value, int table_size,  hash_table *hash_table);

void delete_table_node(int value, table_node *hash_table);

void search_table_node(int value, hash_table hash_table);

void  * get_table_node(int value, table_node *hash_table);

int amount_of_table_nodes(table_node *hash_table);

int index_node_amount(int index, table_node *hash_table);

void index_clear(int index, table_node *hash_table);

void print_table(hash_table *hash_table);

#endif //UNTITLED6_HASH_TABLE_H
