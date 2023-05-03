#include <iostream>
#define HSIZE 100
using namespace std;

string menu[] = {
    "INSERT                 ",
    "DELETE                 ",
    "ROOT_AND_NOW_ELEMENT   ",
    "BREAK                  "
    };

enum Menus
{
    INSERT              ,
    DELETE              ,
    ROOT_AND_NOW_ELEMENT,
    BREAK,
    COUNT
};

class element 
{
    public:
    string       name;
    double       score;  // Key
    void   set_data(string n, double s);
};

class my_heap {
    public:
        element   h[HSIZE];
        int      csize;
        my_heap();
        int h_size();
        void      insert_heap(element  t);
        element   delete_heap();
        bool heap_full();
        bool heap_empty();
};

void run_program                    (my_heap &heap);
void print_menu                     (string *menu);
void call_insert                    (my_heap &heap);
void call_delete                    (my_heap &heap);
void call_root_and_now_element      (my_heap &heap);

int main(void){
    my_heap heap = my_heap();
    
    run_program(heap);
    
    return EXIT_SUCCESS;
}






void   element::set_data(string n, double s)
{   
    name = n;
    score = s;
}


my_heap::my_heap()
{
    csize = 0;
}
bool    my_heap::heap_empty()
{
    return (csize == 0);
}
bool    my_heap::heap_full()
{
    return (csize >= HSIZE-1);
}
int my_heap::h_size()
{
    return csize;
}

void   my_heap::insert_heap(element   t) 
{
    int   k;
    csize++;
    k = csize;
    while ((k != 1) && (t.score > h[k / 2].score)) 
    {
        h[k] = h[k / 2];
        k /= 2;
    }
    h[k] = t;
}

element      my_heap::delete_heap() 
{
    element   t;
    element   tmp;
    int      parent, child;
    t = h[1]; // for return value
    tmp = h[csize]; // 끝원소
    csize--;
    parent = 1;// root
    child = 2;// root의 left child
    while (child <= csize) 
    {
        if ((child < csize) && (h[child].score < h[child + 1].score))
            child++; // right child를 선택
        if (tmp.score >= h[child].score)break;
            h[parent] = h[child];
        parent = child;// 한단계 아래로
        child *= 2;
    }
    h[parent] = tmp;
    return t;
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


void run_program             (my_heap &heap){
    int command;
    bool check;

    while(true){
        print_menu(menu);
        cin >> command;
        check = false;
        
        
        switch(command){
            case Menus::INSERT :
                call_insert(heap);
                break;
            case Menus::DELETE :
                call_delete(heap);
                break;

            case Menus::ROOT_AND_NOW_ELEMENT :
                call_root_and_now_element(heap);
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

void call_insert                    (my_heap &heap)
{
    element t;
    string name;
    double score;

    if(!heap.heap_full())
    {
        cout << "입력할 데이터를 입력해주세요 : " << endl;

        cout << "이름  : ";
        cin >> t.name;

        cout << "점수  : ";
        cin >> t.score;
        
        
        heap.insert_heap(t);

        cout << "완료되었습니다." << endl;
    }
    else
    {
        cout << "HEAP이 모두 찼습니다." << endl;
    }
    
    
}
void call_delete                    (my_heap &heap)
{
    element result;

    if(heap.heap_empty() == false){
        result = heap.delete_heap();
        cout << "삭제한 학생의 자료는 다음과 같습니다." << endl;
        cout << "----------------------------" << endl;
        cout << "이름 : " << result.name << endl;
        cout << "점수 : " << result.score << endl;
        cout << "완료되었습니다." << endl;
    }
    else{
        cout << "더이상 삭제할 데이터가 존재하지 않습니다." << endl;
    }
}
void call_root_and_now_element      (my_heap &heap)
{
    if(heap.heap_empty() == false){
        cout << "\n-----------------------" << endl;
        cout << "현재의 root와 element를 출력하겠습니다." << endl;
        cout << "-----------------------" << endl;
        cout << "[root]  " << endl;
        cout << "이름 : " << heap.h[1].name << endl;
        cout << "점수 : " << heap.h[1].score << endl;
        cout << endl; 
        cout << "[element] " << endl;
        cout << "이름 : " << heap.h[heap.csize].name << endl;
        cout << "점수 : " << heap.h[heap.csize].score << endl;

    }
    else {
        cout << "출력할 데이터가 존재하지 않습니다." << endl;
    }
}