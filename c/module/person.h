#ifndef PERSON_H
#define PERSON_H

struct Person {
    int age;
    char name[32];
};

// Function prototypes
void print_person(const struct Person *p);
void save_person(const struct Person *p, const char *filename);
int load_person(struct Person *p, const char *filename);

#endif

