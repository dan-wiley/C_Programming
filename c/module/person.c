#include <stdio.h>
#include <string.h>
#include "person.h"

void print_person(const struct Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

void save_person(const struct Person *p, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) return;
    fwrite(p, sizeof(struct Person), 1, f);
    fclose(f);
}

int load_person(struct Person *p, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return 0;
    fread(p, sizeof(struct Person), 1, f);
    fclose(f);
    return 1;
}

