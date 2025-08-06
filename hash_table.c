//
// Created by Murilo on 05/08/2025.
//


#include "hash_table.h"

hash_table initiliaze_table(int table_size)
{
    hash_table *new_hash_table = malloc(sizeof(hash_table));
    new_hash_table->table_indexes = malloc(sizeof(table_node) * table_size);

    for (int i = 0; i < table_size; i++)
    {
        new_hash_table->table_indexes[i] = NULL;

    }
    new_hash_table->table_size = table_size;

    return *new_hash_table;
}

int Hash_Func(int value, int table_size)
{
    const double hash_constant = 0.6180339887;
    double hashed_frac = (value * hash_constant) - (unsigned long)(value * hash_constant);

    int index =  table_size * hashed_frac;


    return index;
}

void insert_table_node(int value, int table_size, hash_table *ht)
{
    int depth = 0;
    int index = Hash_Func(value, table_size);

    table_node **current_table_array = ht->table_indexes;
    if(current_table_array[index] == NULL)
    {
        table_node *new_node = malloc(sizeof(table_node));
        new_node->node_value = value;
        new_node->node_below = NULL;
        current_table_array[index] = new_node;
        printf("Inserting node %d at index %d at depth %d\n", value, index, depth);
        printf("\n");
    }
    else
    {
        table_node *aux_pointer = current_table_array[index];
        while(aux_pointer->node_below != NULL)
        {

            aux_pointer = aux_pointer->node_below;
            printf("moving below\n");
            depth = depth + 1;
        }
        table_node *new_node = malloc(sizeof(table_node));
        new_node->node_value = value;
        new_node->node_below = NULL;
        aux_pointer->node_below  = new_node;
        printf("Inserting node %d at index %d at depth %d\n", value, index, depth);
        printf("\n");
    }
}

void print_table(hash_table *ht)
{
    table_node **current_table_array = ht->table_indexes;
    int table_size = ht->table_size;

    for (int counter = 0; counter < table_size; counter++)
    {
        table_node *current_table_index = current_table_array[counter];
        if(current_table_index != NULL)
        {

            while(current_table_index->node_below != NULL)
            {
                printf("%d -> ", current_table_index->node_value);
                current_table_index = current_table_index->node_below;
            }
        }
        else
        {
            printf("Index %d is empty!", counter);
        }

        printf("\n");
    }
}

/**
void search_table_node(int value, hash_table hash_table)
{
    int table_size = (sizeof(&hash_table) / sizeof(table_node));
    int search_index = Hash_Func(value, table_size);
    int depth = 0;

    table_node **current_node = hash_table[search_index];

    if((*current_node)->node_value == value)
    {
        printf("New node with value %d has been inserted at index %d at depth %d\n", value, search_index, depth);
    }
    else
    {
        while((*current_node)->node_value != value)
        {
            current_node = (*current_node)->node_below;
            depth++;
        }
    }

}
**/