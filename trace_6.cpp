

#include <iostream>
#include "hash_list.h"

//TESTING COPY CONSTRUCTOR WITH TRACE 1 INSERTS
int trace_6()
{
    std::cout << "Running trace 6\n";
    
    hash_list list;
    std::cout << "Inserting key=1, value=1\n";
    list.insert(1, 1);
    std::cout << "Inserting key=2, value=2\n";
    list.insert(2, 2);
    std::cout << "Inserting key=3, value=3\n";
    list.insert(3, 3);
    std::cout << "Inserting key=4, value=4\n";
    list.insert(4, 4);
    
    std::cout << "Testing Copy Constructor\n";

    hash_list copy_list = list;

    return 0;
}

