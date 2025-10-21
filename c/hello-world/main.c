#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc > 1){
	printf("%s", argv[1]);
	printf("\n");
    }
    printf("hello world!");
    return 1;
}
