#include "stdio.h"

int main(){
    int i = 0;
    while(i < 6){
        if(i == 5){
            break;
        } else {
            printf("i = %d\n", i);
            i = i+1;
        }
    }  
}
