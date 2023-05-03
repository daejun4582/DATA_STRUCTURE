#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/binary_tree/BinaryTree.h>
using namespace std;

string menu[] = {
    "INSERT_ROOT          ",
    "INSERT_LEFT          ",
    "INSERT_RIGHT         ",
    "SCORE_SUM            ",
    "SCORE_AVERAGE        ",
    "SCORE_MAX            ",
    "PRINT_DATA_INORDER   ",
    "PRINT_DATA_PREORDER  ",
    "PRINT_DATA_POSTORDER ",
    "PRINT_NODE_INFO      ",
    "BREAK                "
    };

enum Menus
{
    INSERT_ROOT          ,
    INSERT_LEFT          ,
    INSERT_RIGHT         ,
    SCORE_SUM            ,
    SCORE_AVERAGE        ,
    SCORE_MAX            ,
    PRINT_DATA_INORDER   ,
    PRINT_DATA_PREORDER  ,
    PRINT_DATA_POSTORDER ,
    PRINT_NODE_INFO      ,
    BREAK                ,
    COUNT
};


void print_menu                     (string *menu);
void run_program                    (BinaryTree &tree);

void call_insert_root               (BinaryTree &tree);
void call_insert_left               (BinaryTree &tree);
void call_insert_right              (BinaryTree &tree);

void call_score_sum                 (BinaryTree &tree);
void call_score_average             (BinaryTree &tree);
void call_score_max                 (BinaryTree &tree);

void call_print_data_inorder        (BinaryTree &tree);
void call_print_data_preorder       (BinaryTree &tree);
void call_print_data_postorder      (BinaryTree &tree);

void call_node_info                 (BinaryTree &tree);



int main(void){

    BinaryTree tree;

    run_program(tree);

    return EXIT_SUCCESS;
}



void print_menu(string *menu){

    cout << "\n사용할 명령어를 입력하세요. \n" << endl;
    cout << "--------------------------" << endl;
    cout << "         Menu List" << endl;
    cout << "--------------------------" << endl;


    for(int i = 0; i < Menus::COUNT; i++){
       cout << menu[i] << " [" << i << "]"<<endl;
    }
    cout << "--------------------------" << endl;
    
    cout << "\nCommand : " ;
}

void run_program                    (BinaryTree &tree){
    int command;
    bool flag;

    while(true){
        print_menu(menu);
        cin >> command;
        flag = false;

        switch (command)
        {
        case INSERT_ROOT:
            call_insert_root(tree);
            break;
        case INSERT_LEFT:
            call_insert_left(tree);
            break;
        case INSERT_RIGHT:
            call_insert_right(tree);
            break;
        case SCORE_SUM:
            call_score_sum(tree);
            break;
        case SCORE_AVERAGE:
            call_score_average(tree);
            break;
        case SCORE_MAX:
            call_score_max(tree);
            break;
        case PRINT_DATA_INORDER:
            call_print_data_inorder(tree);
            break;
        case PRINT_DATA_PREORDER:
            call_print_data_preorder(tree);
            break;
        case PRINT_DATA_POSTORDER:
            call_print_data_postorder(tree);
            break;
        case PRINT_NODE_INFO:
            call_node_info(tree);
            break;
        case BREAK:
            cout << "프로그램을 종료하겠습니다" << endl;
            flag = true;
            break;
        default:
            cout << "[ " << command << "]" << "는 지원하지 않는 명령어 입니다." << endl;
            break;
        }

        if(flag) return;
    }
}

void call_insert_root               (BinaryTree &tree){
    Node t;

    struct data indata;

    int result;

    cout << "입력할 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "점수  : ";
    cin >> indata.score;
    
    t.set_data(indata);

    result = tree.insert_root(t);

    if(result == 0){
         cout << "\n이미 root가 존재하여 삽입에 실패 하였습니다." << endl;
         return;
    }

    cout << "입력에 성공 하였습니다." << endl;

}

void call_insert_left               (BinaryTree &tree){
    Node t;

    struct data indata;

    string s_name;

    int result;

    cout << "데이터를 삽입할 노드의 이름을 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> s_name;

    cout << "삽입할 노드의 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "점수  : ";
    cin >> indata.score;
    
    t.set_data(indata);
    
    result = tree.insert_left(s_name, t);

    if(result == 1 ) 
        cout << "\n성공 하였습니다." << endl;
    else if(result == 0)
        cout << "\n해당 노드가 존재하지 않습니다." << endl;
    else
        cout << "\n해당 노드의 왼쪽에는 삽입할 공간이 존재하지 않습니다." << endl;

}
void call_insert_right              (BinaryTree &tree){
    Node t;

    struct data indata;

    string s_name;

    int result;

    cout << "데이터를 삽입할 노드의 이름을 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> s_name;

    cout << "\n삽입할 노드의 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "점수  : ";
    cin >> indata.score;
    
    t.set_data(indata);
    
    result = tree.insert_right(s_name, t);

    if(result == 1 ) 
        cout << "\n성공 하였습니다." << endl;
    else if(result == 0)
        cout << "\n해당 노드가 존재하지 않습니다." << endl;
    else
        cout << "\n해당 노드의 오른쪽에는 삽입할 공간이 존재하지 않습니다." << endl;

}

void call_score_sum                 (BinaryTree &tree){
    
    if(tree._node_num == 0){
        cout << "데이터가 존재하지 않습니다." << endl;
        return;
    }
    else{
        cout << "\n총 데이터에서 score의 합은 다음과 같습니다 : [ " << tree.score_sum() << " ]" << endl;
        return;
    }

    
}
void call_score_max                 (BinaryTree &tree){
    if(tree._node_num == 0){
        cout << "데이터가 존재하지 않습니다." << endl;
        return;
    }
    
    cout << "\n총 데이터에서 score의 max는 다음과 같습니다 : [ " << tree.score_max() << " ]" << endl;
    return;
}
void call_score_average             (BinaryTree &tree){
    if(tree._node_num == 0){
        cout << "데이터가 존재하지 않습니다." << endl;
        return;
    }
    
    cout << "\n총 데이터에서 score의 평균은 다음과 같습니다 : [ " << tree.score_average() << " ]" << endl;
    return;

}

void call_print_data_inorder        (BinaryTree &tree){
    if(tree._node_num == 0){
        cout << "데이터가 존재하지 않습니다." << endl;
        return;
    }

    cout << "[ inorder ]  탐색을 진행하겠습니다.\n" << endl;

    tree.print_data_inorder();

    cout << "\n 탐새을 완료하였습니다." << endl;
}
void call_print_data_preorder       (BinaryTree &tree){
    if(tree._node_num == 0){
        cout << "데이터가 존재하지 않습니다." << endl;
        return;
    }

    cout << "[ preorder ]  탐색을 진행하겠습니다.\n" << endl;

    tree.print_data_preorder();

    cout << "\n 탐새을 완료하였습니다." << endl;
}
void call_print_data_postorder      (BinaryTree &tree){
    if(tree._node_num == 0){
        cout << "데이터가 존재하지 않습니다." << endl;
        return;
    }

    cout << "[ postorder ]  탐색을 진행하겠습니다.\n" << endl;

    tree.print_data_postorder();

    cout << "\n 탐새을 완료하였습니다." << endl;
}

void call_node_info                 (BinaryTree &tree){
    if(tree._node_num == 0){
            cout << "데이터가 존재하지 않습니다." << endl;
            return;
        }
    
    cout << "\n----------[INFO OF NODES]---------\n" << endl;
    cout  << "The number of degree-2 nodes : [" << tree.n_d1_nodes() << "]\n" << endl;
    cout  << "The number of degree-1 nodes : [" << tree.n_d2_nodes() << "]\n" << endl;
    cout  << "The number of leaf nodes     : [" << tree.n_leaf_nodes() << "]\n" << endl;

}