#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

void bubble_sort(int *p,int n);
void insertion_sort(int *p,int n);
void selection_sort(int *p,int n);
void quick_sort(int p[],int start, int end,int size);
void merge_sort(int p[],int pux[],int n,int lo, int hi);
void merging(int p[],int pux[],int lo,int mi, int hi);

int isSorted(int a[], int i, int j);

void swap(int *a, int *b);
void print_process(int p[],int size);

int main(void){
    int values[] = { 4, 6, 3, 2, 5, 7, 9, 8};
    int n = sizeof(values)/sizeof(values[0]);
    int val_sorted[8];

    void (*sortings[])(int *,int) = {bubble_sort,insertion_sort,selection_sort};
    
    // sortings[3](values,n);
    // quick_sort(values,0,n-1,n);

    merge_sort(values,val_sorted,n,0,n-1);

    for(int i = 0; i<n; i++){
        cout<<values[i]<<" ";
    }
    cout << endl;
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


void merge_sort(int p[],int pux[],int n,int lo, int hi){
    if(hi <= lo) return;
    int mi = (lo + hi) / 2;

    merge_sort( p, pux, n, lo    , mi);
    merge_sort( p, pux, n, mi + 1, hi);
    merging( p, pux, lo, mi, hi);
}

void merging(int p[],int pux[],int lo,int mi, int hi){
    assert(isSorted(p, lo, mi));
    assert(isSorted(p, mi+1, hi));

    print_process(p,8);
    for(int k = lo; k<=hi; k++) pux[k] = p[k];
    int i = lo;
    int j = mi+1;
    for(int k = lo; k<=hi; k++){
        if(i > mi) p[k] = pux[j++];
        else if(j > hi) p[k] = pux[i++];
        else if(pux[j] < pux[i]) p[k] = pux[j++];
        else p[k] = pux[i++];
    }
    print_process(p,8);
    assert(isSorted(p, lo, hi));
}


int isSorted(int a[], int i, int j){
    return a[i] <= a[j];
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