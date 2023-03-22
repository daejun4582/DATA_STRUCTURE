#include <iostream>
#include <cstdlib>
#define SIZE 100;
using namespace std;

struct indata{
    string name;
    int pages;
    int price;
};

class Queue{
    private:
        int _front;
        int _rear;
        int _size;
        int _N;
        indata* _que;
    public:
        Queue();
        bool Enqueue(indata que);
        indata Dequeue();
        bool Queue_full();
        bool Queue_empty();
        indata get_front();
};

enum Menus{
    IN,
    OUT,
    PRINT_FRONT,
    EXIT
};


void data_in(Queue *queue);
void data_out(Queue *queue);
void data_print(Queue *queue);

int main(void){
    Queue queue = Queue();

    int com;
    bool status;
    
    indata data;

    while(true){
        cout << "사용할 명령어를 입력하세요. ( insert : 0 | delete : 1 | print_front : 2 | exit : 3 ) : ";
        cin >> com;

        status = false;

        switch(com){
            case Menus::IN :
                data_in(&queue);
                break;
            case Menus::OUT :
                data_out(&queue);
                break;
            case Menus::PRINT_FRONT :
                data_print(&queue);
                break;
            case Menus::EXIT:
                cout << "프로그램을 종료합니다." << endl;
                status = true;
                break;
            default :
                cout << "잘못된 명령어 입니다. 다시 입력해주세요." <<endl;
                break;
        }
        if(status == true) break;
    }

    return EXIT_SUCCESS;
}

void data_in(Queue *queue){
    struct indata data;
    cout << "입력할 데이터를 입력하세요" <<endl;
    cout << "책 이름 : ";
    cin >> data.name ;
    cout << "책 전체 페이지 수 : ";
    cin >> data.pages ;
    cout << "책 가격 : ";
    cin >> data.price ;
    cout << ((*queue).Enqueue(data)? "입력 되었습니다." :"데이터가 모두 찼습니다.") << endl;
}

void data_out(Queue *queue){
    struct indata result;

    if(!((*queue).Queue_empty())){
        result = (*queue).Dequeue();
        cout << "현재 삭제한 데이터의 정보입니다. " << endl;
        cout << "------------------------" << endl;
        cout << "책의 이름 : " ;
        cout << result.name << endl;
        cout << "책의 페이지 수 : " ;
        cout << result.pages << endl;
        cout << "책의 가격 : " ;
        cout << result.price << endl;
    }
    else
        cout << "데이터가 존재하지 않습니다." << endl;
}

void data_print(Queue *queue){

    struct indata result;
    if(!((*queue).Queue_empty())){
        result = (*queue).get_front();

        cout << "현재 front에 있는 데이터의 정보입니다. " << endl;
        cout << "------------------------" << endl;
        cout << "책의 이름 : " ;
        cout << result.name << endl;
        cout << "책의 페이지 수 : " ;
        cout << result.pages << endl;
        cout << "책의 가격 : " ;
        cout << result.price << endl;
    }
    else{
        cout << "데이터가 존재하지 않습니다." << endl;
    }
}



Queue::Queue(){
    _front = 0;
    _rear = 0;
    _size = SIZE;
    _N = 0;
    _que = new indata[_size];
}

bool Queue::Enqueue(indata que){
    if(!(Queue_full())){
        _que[_rear] = que;
        _rear = (_rear+1)%_size;
        _N ++;
        return true;
    }

    return false;
}

indata Queue::Dequeue(){
    _N--;
    indata temp = _que[_front];
    _front = (_front+1) % _size ;
    return temp;
}
bool Queue::Queue_full(){
    if((_rear+1)%_size == _front) return true;
    return false;

}
bool Queue::Queue_empty(){
    if(_rear == _front) return true;
    return false;

}
indata Queue::get_front(){
    return _que[_front];
}
