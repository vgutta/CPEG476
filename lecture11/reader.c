#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    size_t bytes = 256;
    char* p2chunk = (char *)malloc(bytes);
    
    getline(&p2chunk, &bytes, stdin);
    printf("%s\n", p2chunk);
    memset(p2chunk, 'A', 256 * sizeof(char));
    /*p2chunk = (char*) calloc (256,sizeof(char));*/
    free(p2chunk);
    printf("%s\n", p2chunk);
}