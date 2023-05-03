#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/stack/Stack.h>

using namespace std;


void hex_in_data(int indata, Stack &stack);

string make_result(Stack &stack);

int main(void){

    Stack stack;

    string result;

    hex_in_data(330,stack);

    result = make_result(stack);

    cout << result << endl;

    return EXIT_SUCCESS;
}


void hex_in_data(int indata, Stack &stack){
    
    while( indata != 0 ){

        stack.push(indata%16); 

        indata = indata / 16;    

    }

    stack.push(indata); 

}


string make_result(Stack &stack){

    string result;

    char token;

    int r,idx = 0;

    while(!(stack.stack_empty())){

        r = stack.pop() ;

        if(idx == 0) {

            idx++;

            continue;
        }
        

        if( r <  10)
            token =  r + 48 ;
        else
            token =  r + 55 ;

        result += token;

    }

    return result;
}