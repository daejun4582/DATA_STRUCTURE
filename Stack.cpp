#include <iostream>

using namespace std;


namespace data{
    int top = 0;
    int size = 5;
    int* arr = new int[size];
}

int push(int a);
int pop();
int top();

bool empty();
bool full();

void getAll();

int main(){
    string command;
    int p,con=0;
    while(true){

        cout<<"사용할 명령어를 입력하세요. ";
        cin >> command;

        if(command == "push"){
            if(full()){
                cout<<"데이터가 다 찼습니다.\n"<<endl;
            }
            else{
                cout<<"넣을 숫자를 입력하세요. ";
                cin >> p;
                push(p);
                cout<<"완료되었습니다.\n"<<endl;
            }
        }
        else if(command == "pop"){
            if(empty()){
                cout<<"데이터가 없습니다.\n"<<endl;
            }
            else{
                pop();
                cout<<"완료되었습니다.\n"<<endl;
            }
        }
        else if(command == "top"){
            cout<<"현재 top은 "<< top() <<" 입니다."<<endl;
        }
        else if(command == "getAll"){
            getAll();
            cout<<"\n\n";
        }
        else if(command == "done"){
            cout<<"프로그램을 종료하겠습니다."<<endl;
            break;
        }

    }


    return 0;
}



int push(int a){
    data::arr[data::top++] = a;
    return data::arr[data::top-1];
}

int pop(){
    return data::arr[--data::top];
}

int top(){
    return data::top;
}

void getAll(){
    
    for (int i = 0; i<data::size; i++){
        cout<<(data::arr[i])<<" ";
    }
    cout<<"\n";
}

bool empty(){
    if(data::top == 0) return 1;
    else return 0;
}

bool full(){
    if(data::top == data::size) return 1;
    else return 0;
}