#include <stdio.h>
#include "hash_table.h"




int main() {
    hash_table current_table = initiliaze_table(10);
    insert_table_node(2, 10, &current_table);
    //insert_table_node(4, 10, &current_table);
    //insert_table_node(1, 10, &current_table);
    insert_table_node(23, 10, &current_table);
    insert_table_node(57, 10, &current_table);
    print_table(&current_table);
    return 0;
}

