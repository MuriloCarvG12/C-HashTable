#include <stdio.h>
#include "hash_table.h"

int main() {
    hash_table current_table = initiliaze_table(20);
    for(int i = 1; i < 21; i++)
    {
        insert_table_node(i, 10, &current_table);
    }

    print_table(&current_table);
    index_clear(2,&current_table);
    print_table(&current_table);

    return 0;
}