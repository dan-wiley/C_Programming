#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverse_str(char *s){
    int s_len = strlen(s);

    // Use of malloc allows size below to be defined at run time
    // we add +1 because the null terminator
    char *s_rev = malloc((s_len+1) * sizeof(char));

    for (int i =0; i<s_len; i++){
        s_rev[i] = s[s_len - i - 1];
    }

    s_rev[s_len] = '\0'; // add null character to terminate the string

    return s_rev;
}

int main(int argc, char *argv[]){

    for (int i=1; i<argc; i++){
        printf("%s", argv[i]);
        printf("\n");
        char *rev_argv_str = reverse_str(argv[i]);  
        printf("REVERSED: %s", rev_argv_str);
        //free(rev_argv_str);
        printf("\n");
    }

    return 0;
}
