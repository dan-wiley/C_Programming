#include <stdio.h>
#include <string.h>
#include "person.h"

int main() {
    struct Person p1 = {30, "Alice"};
    save_person(&p1, "person.dat");

    struct Person p2;
    if (load_person(&p2, "person.dat")) {
        print_person(&p2);
    } else {
        printf("Failed to load person\n");
    }

    return 0;
}

