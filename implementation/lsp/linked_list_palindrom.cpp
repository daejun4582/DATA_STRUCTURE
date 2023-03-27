#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/lsp/LinkedListStack.h>

using namespace std;

bool check_panlindrome(string s,LinkedListStack stack);

string preprocess_string(string str);

int main(void){

    string s;

    LinkedListStack stack = LinkedListStack();

    cout << " 문장을 입력해주세요. :  " ;

    getline(cin,s);

    s = preprocess_string(s);

    cout <<  s << endl;

    cout << "본 문장은 회문이 " << (check_panlindrome(s,stack)? "맞습니다." : "아닙니다.") << endl;

    return EXIT_SUCCESS;
}

string preprocess_string(string str){

    string result;

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    
    for(int i =0; i<str.size(); i++){
        if(isalpha(str[i])!=0)
            result += tolower(str[i]);
    
    }

    return result;
}

bool check_panlindrome(string s, LinkedListStack stack){

    int str_len = s.size();    
    struct data indata;
    char out;

    for(int i = 0; i< (str_len)/2 ; i++) {
        
        indata.token = s[i];
        stack.push(indata);
    }
    
    for(int i = ((str_len % 2 ==0)? str_len/2 : str_len/2 +1);  i < s.size();  i++){

        if(stack.pop().token != s[i]) return false;
        
    }

    return true;

}
