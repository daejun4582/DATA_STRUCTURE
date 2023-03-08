#include <iostream>
#include <stdlib.h>
using namespace std;

void bubble_sort(int *p,int n);
void insertion_sort(int *p,int n);
void selection_sort(int *p,int n);
void quick_sort(int p[],int start, int end,int size);

void swap(int *a, int *b);
void print_process(int p[],int size);

int main(void){
    int values[] = { 4, 6, 3, 2, 5, 7, 9, 8};
    int n = sizeof(values)/sizeof(values[0]);
     

    void (*sortings[])(int *,int) = {bubble_sort,insertion_sort,selection_sort};
    
    // sortings[3](values,n);
    quick_sort(values,0,n-1,n);


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
                swap(p[j],p[j+1]);
            }
        }
        print_process(p,n);
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
        swap(p[min],p[i]);
        print_process(p,n);
    }
    

}

void selection_sort(int *p,int n){
    int temp;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(p[i]>p[j]){
                swap(p[i],p[j]);
            }
            print_process(p,n);
        }
    }
}



void quick_sort(int p[],int start, int end,int size){
    printf("start : %d end: %d\n",start,end);
    int lo = start+1,hi = end,pivot = start;
    if(start >= end) return;
    
    while(lo<= hi){
        
        while(lo <= end && p[pivot] >= p[lo]) lo++;
        while(hi > start && p[pivot] <= p[hi]) hi--;


        if(lo>hi) swap(p[hi],p[pivot]);
        else swap(p[hi],p[lo]);
    }
    print_process(p,size);
    quick_sort(p,start,hi-1,size);
    quick_sort(p,hi+1,end,size);

}


void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_process(int p[],int size){
    for(int i = 0; i<size; i++){
        cout<<p[i]<<" ";
    }
    cout<<"\n";
}