#include <iostream>
#include <stdlib.h>
#include "/Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/stack/Stack.h"
using namespace std;


/*

-----Logic------
1. Stack을 생성하고 초기화(operator를 원소로 저장하는 stack) 한 후, stack에 EOS를 넣고 시작한다.
2.  입력 수식으로부터 token을 한 개씩 취하여 다음을 반복
    해당 token이
        (1) ‘(‘ 이면stack에 넣는다.
        (2) ‘)’ 이면, stack에서 ‘(‘ 이 나올때까지 pop하여 출력한다. 그리고 나서 ‘(‘ 를 stack에서 삭제
        (3) Operator면 stack top 원소의 우선순위가 자신(해당 token)의 우선순위보다 낮아질 때까지pop하여 출력한다. 
            그리고 나서 해당 token을 stack에 넣는다.
        (4)  Operand면 그대로 출력한다.
3.   Stack에 남아 있는 모든 원소를 순서대로 pop하여 출력한다.
*/



int main(void){
    Stack s = Stack();
    string expression;
    cout<<"변환할 식을 입력해주세요. : ";
    cin >> expression;
    cout<<expression[0]<<endl;


    return EXIT_SUCCESS;
}