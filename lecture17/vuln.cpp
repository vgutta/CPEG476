#include <cstring>
#include <stdexcept>
#include <iostream>

void go(char *data) {
    char name[64];
    strcpy(name, data);
}

int main(int argc, char **argv) {
    if(sizeof(argv[1]) > 64){
        throw runtime_error("input too long");
    }
    go(argv[1]);
}
