#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void reversing1(string s, int N, int idx);
string reversing2(string s, int N, int idx);
bool check_panlindrome(string s, int N, int idx);
int sumDigits1(int n);
int sumDigits2(int n);
int count8(int n );


int main(void){

    cout << count8(888) << endl;

    return EXIT_SUCCESS;
}


void reversing1(string s, int N, int idx){
    if(N == 0) return;

    if(idx == N) {
        return ;
    }
    
    reversing1(s,N,idx+1);
    cout<< s[idx];
    return;
    
}

string reversing2(string s, int N, int idx){
    if(N == 0) return s;

    if(idx == N) return "";

    return reversing2(s,N,idx+1) + s[idx];

}


bool check_panlindrome(string s, int N, int idx){
    if(N == 0 || N == 1) return true;

    if(idx > N/2) return true;

    if(s[idx] == s[N-1-idx]) {
        check_panlindrome(s,N,idx+1);
        return true;
    }
    
    return false;
}


int sumDigits1(int n){

    int digit = 0,num,result;

    while(true){
        num = pow(10,digit);
        if( n / num == 0) break;
        digit ++;
    }
    
    num /= 10;
    result = n / num ;
    n -= result * num;
    

    if(n == 0)  return result;

    return result + sumDigits1(n);

} 

int sumDigits2(int n){
    if(n == 0) return 0;
    return  n%10 + sumDigits2(n/10);
}

int count8(int n ){
    if(n == 0) return 0;

    if(n%10 == 8)
        return 1 + count8(n/10);
    return 0 + count8(n/10);
}