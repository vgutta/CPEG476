#include <string.h>

void go(char *data) {
    char name[64];

    strlcpy(name, data, 64);
}

int main(int argc, char **argv) {
    go(argv[1]);
}