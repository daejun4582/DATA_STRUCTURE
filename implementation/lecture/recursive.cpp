#include <iostream>
#include <cstdlib>

using namespace std;


void reversing1(string s, int N, int idx);
string reversing2(string s, int N, int idx);
bool check_panlindrome(string s, int N, int idx);


int main(void){

    string s = "helkleh";

    cout << (check_panlindrome(s,s.size(),0)? "회문입니다":"회문이 아닙니다.") << endl;

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