#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list_queue/LinkedListQueue.h>

using namespace std;


enum Menus{
    INSERT,
    DELETE,
    CHECK_EMPTY,
    GET_ALL,
    BREAK,
    COUNT
};

string menu[]
{
    "INSERT     ",
    "DELETE     ",
    "CHECK_EMPTY",
    "GET_ALL    ",
    "BREAK      "
};


void run_program(LinkedListQueue &queue);
void print_menu();
void call_insert(LinkedListQueue &queue);
void call_delete(LinkedListQueue &queue);
void call_check_empty(LinkedListQueue &queue);
void call_get_all(LinkedListQueue &queue);

int main(void){

    LinkedListQueue queue = LinkedListQueue();

    run_program(queue);

    return EXIT_SUCCESS;
}

void print_menu(){
    Menus k = COUNT;

    cout << "\n사용할 명령어를 입력하세요. \n" << endl;
    cout << "--------------------------" << endl;
    cout << "         Menu List" << endl;
    cout << "--------------------------" << endl;


    for(int i = 0; i < k; i++){
       cout << menu[i] << " [" << i << "]"<<endl;
    }
    cout << "--------------------------" << endl;
    
    cout << "\nCommand : " ;
}

void run_program(LinkedListQueue &queue){
    int command;
    bool status;

    while(true){
        
        status = false;
        print_menu();

        cin >> command;

        switch(command){
            case Menus::INSERT :
                call_insert(queue);
                break;
            case Menus::DELETE :
                call_delete(queue);
                
                break;
            case Menus::CHECK_EMPTY :
                call_check_empty(queue);
                
                break;
            case Menus::GET_ALL :
                call_get_all(queue);
                break;
            case Menus::BREAK :
                status = true;

                break;

            default :
                cout  <<"잘못된 명령어 입니다. 다시 입력해주세요" << endl;
                break;
        }

        if(status == true) break;

    }
}

void call_insert(LinkedListQueue &queue){
    struct data indata;

    cout << "입력할 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "학번  : ";
    cin >>indata.id ;

    cout << "점수  : ";
    cin >> indata.score;
    
    queue.Enqueue(indata);

    cout << "완료되었습니다." << endl;

}
void call_delete(LinkedListQueue &queue){
    struct data result;

    if(queue.Queue_empty() == false){
        result = queue.Dequeue();
        cout << "삭제한 학생의 자료는 다음과 같습니다." << endl;
        cout << "----------------------------" << endl;
        cout << "이름 : " << result.name << endl;
        cout << "학번 : " << result.id << endl;
        cout << "완료되었습니다." << endl;
    }
    else{
        cout << "데이터가 존재하지 않습니다." << endl;
    }
}
void call_check_empty(LinkedListQueue &queue){
    cout << "현재 큐에 원소가 " << (queue.Queue_empty()? "존재 하지 않습니다." : "존재 합니다.") << endl;
}
void call_get_all(LinkedListQueue &queue){
    if(queue.Queue_empty() == false){
        cout << "\n--------------------------------" << endl;
        cout << "현재의 데이터를 출력하겠습니다." << endl;
        cout << "--------------------------------\n" << endl;
        queue.get_all_dataes();
    }
    else {
        cout << "출력할 데이터가 존재하지 않습니다." << endl;
    }
}

