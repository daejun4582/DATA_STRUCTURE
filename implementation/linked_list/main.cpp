#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list/LinkedList.h>

using namespace std;

string menu[] = {
    "in_head              ",
    "in_tail              ",
    "delete_from_head     ",
    "delete_from_tail     ",
    "delete_from_middle   ",
    "get_sum_of_score     ",
    "get_min_of_score     ",
    "get_max_of_score     ",
    "get_mean_of_score    ",
    "empty_check          ",
    "get_num              ",
    "get_statics          ",
    "get_score            ",
    "get_all              ",
    "break                "
    };

enum Menus
{
    IN_HEAD,
    IN_TAIL,
    DELETE_FROM_HEAD,
    DELETE_FROM_TAIL,
    DELETE_FROM_MIDDLE,
    GET_SUM_OF_SCORE,
    GET_MIN_OF_SCORE,
    GET_MAX_OF_SCORE,
    GET_MEAN_OF_SCORE,
    EMPTY_CHECK,
    GET_NUM,
    GET_STACTICS,
    GET_SCORE,
    GET_ALL,
    BREAK
};

void print_menu(string *menu);
void call_in_head            (LinkedList &mylist);
void call_in_tail            (LinkedList &mylist);
void call_delete_from_head   (LinkedList &mylist);
void call_delete_from_tail   (LinkedList &mylist);
void call_delete_from_middle (LinkedList &mylist);
void call_get_sum_of_score   (LinkedList &mylist);
void call_get_min_of_score   (LinkedList &mylist);
void call_get_max_of_score   (LinkedList &mylist);
void call_get_mean_of_score  (LinkedList &mylist);
void call_empty_check        (LinkedList &mylist);
void call_get_num            (LinkedList &mylist);
void call_get_statics        (LinkedList &mylist);
void call_get_score          (LinkedList &mylist);
void call_get_all            (LinkedList &mylist);
void run_program             (LinkedList &mylist);

int main(void){
    LinkedList mylist;
    
    run_program(mylist);
    
    return EXIT_SUCCESS;
}

void print_menu(string *menu){
    cout << "\n사용할 명령어를 입력하세요. \n" << endl;
    cout << "--------------------------" << endl;
    cout << "         Menu List" << endl;
    cout << "--------------------------" << endl;


    for(int i = 0; i < 15; i++){
       cout << menu[i] << " [" << i << "]"<<endl;
    }
    cout << "--------------------------" << endl;
    
    cout << "\nCommand : " ;
}

void call_in_head            (LinkedList &mylist){
    Node t;
    struct data indata;

    cout << "입력할 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "학번  : ";
    cin >>indata.id ;

    cout << "점수  : ";
    cin >> indata.score;
    
    t.setData(indata);
    mylist.add_to_head(t);

    cout << "완료되었습니다." << endl;
}
void call_in_tail            (LinkedList &mylist){
    Node t;
    struct data indata;
    cout << "입력할 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "학번  : ";
    cin >>indata.id ;

    cout << "점수  : ";
    cin >> indata.score;
    
    t.setData(indata);
    mylist.add_to_tail(t);

    cout << "완료되었습니다." << endl;
}

void call_delete_from_head   (LinkedList &mylist){
    Node result;

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
}

void call_delete_from_tail   (LinkedList &mylist){
    Node result;

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
}
void call_delete_from_middle (LinkedList &mylist){
    string find;
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
}
void call_get_sum_of_score   (LinkedList &mylist){
    if(mylist.list_empty() == false){
        cout << "전체 데이터에서 점수의 합은 : " << mylist.score_sum() << endl;
    }
    else{
        cout << "데이터가 존재하지 않습니다" << endl;
    }
}

void call_get_min_of_score   (LinkedList &mylist){
    if(mylist.list_empty() == false){
        cout << "현 데이터에서 가장 낮은 score는 : " << mylist.score_min() << endl;
    }
    else{
        cout << "데이터가 존재하지 않습니다" << endl;
    }
}

void call_get_max_of_score   (LinkedList &mylist){
    if(mylist.list_empty() == false){
        cout << "전체 데이터에서 가장 높은 score는 : " << mylist.score_max() << endl;
    }
    else{
        cout << "데이터가 존재하지 않습니다" << endl;
    }
}

void call_get_mean_of_score  (LinkedList &mylist){
    if(mylist.list_empty() == false){
        cout << "전체 데이터에서의 평균은 : " << mylist.score_mean() << endl;
    }
    else{
        cout << "데이터가 존재하지 않습니다" << endl;
    }
}
void call_empty_check        (LinkedList &mylist){
    cout << "현재 상태는 다음과 같습니다. : " << (mylist.list_empty()? "EMPTY" : "NOT EMPTY") << endl;
}
void call_get_num            (LinkedList &mylist){
    cout << "현재 노드의 수는 다음과 같습니다. : " << mylist.num_nodes() << endl;
}
void call_get_statics        (LinkedList &mylist){
    if(mylist.list_empty() == false){
        mylist.get_statics();
    }
    else{
        cout << "데이터가 존재하지 않습니다" << endl;
    }
}
void call_get_score          (LinkedList &mylist){
    string find;
    double finding_result;
    cout << "찾을 데이터의 이름을 입력해주세요."<< endl;
    cin >> find;
    finding_result = mylist.get_score(find);
    
    if(finding_result == -1)
        cout << "검색하신 데이터는 존재하지 않습니다." << endl;
    else {
        cout  << "검색하신 데이터의 결과는 다음과 같습니다. : " << finding_result << endl;
    }
}
void call_get_all            (LinkedList &mylist){
    if(mylist.list_empty() == false){
        cout << "\n-----------------------" << endl;
        cout << "현재의 데이터를 출력하겠습니다." << endl;
        cout << "-----------------------" << endl;
        mylist.get_all();
    }
    else {
        cout << "출력할 데이터가 존재하지 않습니다." << endl;
    }
}


void run_program             (LinkedList &mylist){
    int command;
    bool check;

    while(true){
        print_menu(menu);
        cin >> command;
        check = false;
        
        
        switch(command){
            case Menus::IN_HEAD :
                call_in_head(mylist);
                break;
            case Menus::IN_TAIL :
                call_in_tail(mylist);
                break;

            case Menus::DELETE_FROM_HEAD :
                call_delete_from_head(mylist);
                break;

            case Menus::DELETE_FROM_TAIL :
                call_delete_from_tail(mylist);
                break;

            case Menus::DELETE_FROM_MIDDLE :
                call_delete_from_middle(mylist);
                break;

            case Menus::GET_SUM_OF_SCORE :
                call_get_sum_of_score(mylist);
                break;

            case Menus::GET_MIN_OF_SCORE :
                call_get_min_of_score(mylist);
                break;

            case Menus::GET_MAX_OF_SCORE :
                call_get_max_of_score(mylist);
                break;

            case Menus::GET_MEAN_OF_SCORE :
                call_get_mean_of_score(mylist);
                break;

            case Menus::EMPTY_CHECK :
                call_empty_check(mylist);
                break;

            case Menus::GET_NUM :
                call_get_num(mylist);
                break;
            case Menus::GET_STACTICS :
                call_get_score(mylist);
                break;
            case Menus::GET_SCORE:
                call_get_score(mylist);

                break;

            case Menus::GET_ALL :
                call_get_all(mylist);
                
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


}