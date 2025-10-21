#include <stdio.h>
#include <string.h>

int main(int argc, char *args[] ){
  
    struct Person {
      int age; 
      char name[32];
    };

    struct Person person;

    char buffer[32];

    printf("This program will read an ojbect from a file or create a new one \n");
    printf("Would you like to make a new object (yes)? \n");

    while(fgets(buffer, sizeof(buffer), stdin)){
        if (strcmp(buffer, "yes\n") != 0){
             break; 
        }

        printf("Please enter your age: \n");
        fgets(buffer, sizeof(buffer), stdin);

        sscanf(buffer, "%d", &person.age);  // safer than atoi, can check return value


        printf("Please enter your name:  \n");
        fgets(buffer, sizeof(buffer), stdin);
        
        strncpy(person.name, buffer, sizeof(person.name) - 1);
        person.name[sizeof(person) -1] = '\0';

        FILE *file = fopen("person.txt", "wb");

        fwrite(&person, sizeof(struct Person), 1, file); // fwrite is for writting binary, unlike fputs
                                                      //
        fclose(file);

        printf("Would you like to keep this person (enter), or create a new one (yes)?");
    }  

    FILE *file = fopen("person.txt", "rb");

    if (file == NULL){
      printf("\nThere is no person file. Creaete one by entering 'yes' when prompted.\n");
      return 1;
    }

    fread(&person, sizeof(struct Person), 1, file);

    fclose(file);

    printf("The Person Age: %d, Name: %s", person.age, person.name);

    return 0;
}
