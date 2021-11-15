#include <iostream>
#include "Array.hpp"
#include <vector>
#include <string>
#include <fstream>

#define CARD(arr) ((sizeof(arr))/(sizeof(*arr)))

int main(void) {

    int a[] {1, 2, 3, 4};
    Array<int> arr {a, CARD(a)};

    char as1[] {"um"};
    char as2[] {"dois"};
    char as3[] {"tres"};
    char as4[] {"quatro"};

    char *as[] {as1, as2, as3, as4};
    size_t szs {sizeof as/ sizeof *as};
    Array<char*> arrs {as, szs};

    arrs.print();
    
    return 0;
}