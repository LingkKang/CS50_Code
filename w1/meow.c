#include <stdio.h>

void meow(int n);

int main(void){
    meow(3);
}


void meow(int n){
    for (int i = 0; i < n; i++){
        printf("Meow. \n");
    }
}


// int main(void){
//     int i = 0;
//     while (i < 3){
//         printf("Meow! \n");
//         i++;
//     }
// }