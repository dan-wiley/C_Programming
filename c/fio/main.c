#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
   
    char *text = malloc(1); // create var on heap
    if (!text) { perror("malloc"); return 1; }
    text[0] = '\0';

    char buffer[64];

    printf("Please Enter Data: \n");

    while(fgets(buffer, sizeof(buffer), stdin)){
        if (strcmp(buffer, "\n") == 0) break;

        // Reallocate text to fit existing content + new buffer + null terminator
        text = realloc(text, strlen(text) + strlen(buffer) + 1);

        // Append buffer at the end of text
        // text + strlen(text) points to the null terminator of the existing string
        strcpy(text + strlen(text), buffer);
    }

    FILE *file_ptr = fopen("data.txt", "w");  
    if (!file_ptr) { perror("fopen"); free(text); return 1; }

    fputs(text, file_ptr);

    // free(text);

    fclose(file_ptr);

    return 0;
}
