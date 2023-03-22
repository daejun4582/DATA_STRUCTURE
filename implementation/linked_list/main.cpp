#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list/LinkedList.h>

using namespace std;

enum Menus
{
    IN_HEAD,
    IN_TAIL,
    DELETE_FROM_HEAD,
    DELETE_FROM_TAIL,
    DELETE_FROM_MIDDLE,
    GET_SUM_OF_SCORE,
    EMPTY_CHECK,
    GET_NUM,
    GET_SCORE,
    GET_ALL,
    BREAK
};

int main(void){
    int command;
    struct data indata;
    bool check;
    double finding_result;
    string find;

    Node t;
    Node result;
    LinkedList mylist;
    
    
    while(true){
        cout << "사용할 명령어를 입력하세요. ( in_head : 0 | in_tail : 1 | delete_from_head : 2 | delete_from_tail : 3 | delete_from_middle : 4 | get_sum_of_score : 5 | empty_check : 6 | get_num : 7 | get_score : 8 | get_all : 9 | break : 10) " << endl;
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

            case Menus::DELETE_FROM_HEAD :
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

            case Menus::DELETE_FROM_TAIL :
                if(mylist.list_empty() == false){
                    result = mylist.delete_from_tail();
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

            case Menus::DELETE_FROM_MIDDLE :
                if(mylist.list_empty() == false){
                    cout << "삭제할 데이터의 이름을 입력해주세요." << endl;
                    cin >> find;
                    if(mylist.delete_from_middle(find) == true){
                        cout << "완료하였습니다." << endl;
                    }
                    else{
                        cout << "실패하였습니다." << endl;
                    }
                }
                else{
                    cout << "더이상 삭제할 데이터가 존재하지 않습니다." << endl;
                }
                break;

            case Menus::GET_SUM_OF_SCORE :
                if(mylist.list_empty() == false){
                    cout << "전체 데이터에서 점수의 합은 : " << mylist.score_sum() << endl;
                }
                else{
                    cout << "데이터가 존재하지 않습니다" << endl;
                }
                break;
            case Menus::EMPTY_CHECK :
                cout << "현재 상태는 다음과 같습니다. : " << (mylist.list_empty()? "EMPTY" : "NOT EMPTY") << endl;
                break;

            case Menus::GET_NUM :
                cout << "현재 노드의 수는 다음과 같습니다. : " << mylist.num_nodes() << endl;
                break;
            case Menus::GET_SCORE:
                cout << "찾을 데이터의 이름을 입력해주세요."<< endl;
                cin >> find;
                finding_result = mylist.get_score(find);
                
                if(finding_result == -1)
                    cout << "검색하신 데이터는 존재하지 않습니다." << endl;
                else {
                    cout  << "검색하신 데이터의 결과는 다음과 같습니다. : " << finding_result << endl;
                }

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