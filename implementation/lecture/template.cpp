#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
void sorting(T*p, int n);


int main(void){
    int a[] = {4,2,5,1,3};

    sorting(a,5);

    for(int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

template <typename T>
void sorting(T*p, int n){
    T temp;
    for(int i = 0; i < n-1; i++){
       for(int j = 0; j < n-1-i; j++){
            if(p[j] < p[j+1]){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
       }
    }

}



