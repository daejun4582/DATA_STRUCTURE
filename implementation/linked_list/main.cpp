#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list/LinkedList.h>

using namespace std;

enum Menus
{
    IN_HEAD,
    IN_TAIL,
    DELETE,
    EMPTY_CHECK,
    GET_NUM,
    GET_ALL,
    BREAK
};

int main(void){
    int command;
    struct data indata;
    bool check;

    Node t;
    Node result;
    LinkedList mylist;
    
    
    while(true){
        cout << "사용할 명령어를 입력하세요. ( in_head : 0 | in_tail : 1 | delete : 2 | empty_check : 3 | get_num : 4 | get_all : 5 | break : 6) " << endl;
        cin >> command;
        check = false;
        
        switch(command){
            case Menus::IN_HEAD :

                cout << "입력할 데이터를 입력해주세요 : " << endl;

                cout << "이름  : ";
                cin >> indata.name;

                cout << "학번  : ";
                cin >>indata.id ;

                cout << "점수 : ";
                cin >> indata.score;
                
                t.setData(indata);
                mylist.add_to_head(t);

                cout << "완료되었습니다." << endl;
                break;
            case Menus::IN_TAIL :

                cout << "입력할 데이터를 입력해주세요 : " << endl;

                cout << "이름  : ";
                cin >> indata.name;

                cout << "학번  : ";
                cin >>indata.id ;

                cout << "점수 : ";
                cin >> indata.score;
                
                t.setData(indata);
                mylist.add_to_tail(t);

                cout << "완료되었습니다." << endl;
                break;
            case Menus::DELETE :
                if(mylist.list_empty() == false){
                    result = mylist.delete_from_head();
                    cout << "삭제한 학생의 자료는 다음과 같습니다." << endl;
                    cout << "----------------------------" << endl;
                    cout << "이름 : " << result.getData().name << endl;
                    cout << "학번 : " << result.getData().id << endl;
                    cout << "완료되었습니다." << endl;
                }
                else{
                    cout << "더이상 삭제할 데이터가 존재하지 않습니다." << endl;
                }
                break;
            case Menus::EMPTY_CHECK :
                cout << "현재 상태는 다음과 같습니다. : " << (mylist.list_empty()? "EMPTY" : "NOT EMPTY") << endl;
                break;
            case Menus::GET_NUM :
                cout << "현재 노드의 수는 다음과 같습니다. : " << mylist.num_nodes() << endl;
                break;
            case Menus::GET_ALL :
                if(mylist.list_empty() == false){
                    cout << "현재의 데이터를 출력하겠습니다." << endl;
                    cout << "-----------------------" << endl;
                    mylist.get_all();
                }
                else {
                    cout << "출력할 데이터가 존재하지 않습니다." << endl;
                }
                
                break;
            case Menus::BREAK :
                cout << "프로그램을 종료하겠습니다" << endl;
                check = true;
                break;
            default :
                cout << "잘못된 명령어 입니다." << endl;
                break;
        }

        if(check == true) break;
    }
    return EXIT_SUCCESS;
}