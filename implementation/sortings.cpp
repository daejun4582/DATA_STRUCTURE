#include <iostream>
#include <stdlib.h>
using namespace std;

void bubble_sort(int *p,int n);
void insertion_sort(int *p,int n);
void selection_sort(int *p,int n);

int main(void){
    int values[] = { 4, 6, 3, 2, 5, 7, 9, 8};
    int n = sizeof(values)/sizeof(values[0]);

    void (*sortings[])(int *,int) = {bubble_sort,insertion_sort,selection_sort};
    sortings[2](values,n);


    for(int i = 0; i<n; i++){
        cout<<values[i]<<" ";
    }
    return EXIT_SUCCESS;
}

void bubble_sort(int *p,int n){
    int temp;
    for (int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(p[j]>p[j+1]){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
        for(int k = 0; k<n; k++){
            cout<<p[k]<<" ";
        }
        printf("\n");
    }
}



void insertion_sort(int *p,int n){
    int min,temp;

    for(int i = 0; i<n; i++){
        min = i;
        for(int j = i; j<n; j++){
            if(p[j] < p[min]){
                min = j;
            }
        }
        temp = p[min];
        p[min] = p[i];
        p[i] = temp;
        for(int k = 0; k<n; k++){
            cout<<p[k]<<" ";
        }
        printf("\n");
    }
    

}

void selection_sort(int *p,int n){
    int temp;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(p[i]>p[j]){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
            for(int k = 0; k<n; k++){
                cout<<p[k]<<" ";
            }
            printf("\n");
        }
    }
}