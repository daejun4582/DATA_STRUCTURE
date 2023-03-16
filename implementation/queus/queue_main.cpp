#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/queus/Queue.h>

using namespace std;


/*
command:
cd "/Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/queus/" && g++ -std=c++2a -g queue_main.cpp Queue.cpp -o a.out  && "/Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/queus/"/a.out
*/

int main(void){

    Queue queue = Queue();

    int com;
    
    indata data;

    while(true){
        cout << "원하는 명령어를 입력하세요(0 : in, 1 : out, 2 : print, 3 : exit) " << endl;
        cin >> com;

        if(com == 0){
            cout << "입력할 데이터를 입력하세요" <<endl;
            cin >> data.a ;
            cout << (queue.Enqueue(data)? "입력 되었습니다." :"데이터가 모두 찼습니다.") << endl;
        }
        else if(com == 1){
            queue.get_data();
            if(!(queue.Queue_empty()))
                cout << queue.Dequeue().a << endl;
            else
                cout << "데이터가 존재하지 않습니다." << endl;

        }
        else if(com == 2){
            queue.get_all();
        }
        else if(com == 3){
            cout << "종료 합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 명령어 입니다. 다시 입력해주세요" << endl;
        }
    }
    
    return EXIT_SUCCESS;
}