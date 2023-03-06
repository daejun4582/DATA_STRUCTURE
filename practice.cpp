#include <iostream>
#include <stdlib.h>

  int main(void) {
    int *p = (int*)malloc(sizeof(5));
    for(int i = 0; i<5; i++){
      p[i] = i;
    }
    for(int i = 0; i<5; i++){
      printf("%d ",p[i]);
    }
    printf("\n");
    p = (int*)realloc(p,sizeof(10));
    for(int i = 0; i<10; i++){
      printf("%d ",p[i]);
    }

    




  }
