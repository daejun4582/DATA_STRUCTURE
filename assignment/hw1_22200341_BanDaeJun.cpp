#include <iostream>
#include <stdlib.h>
using namespace std;

class Weight{
    private:

    int kg,g,total;

    public:


    void set_weight(int a, int b){
        kg = a;
        g = b;
    }

    int get_weight(){
        total = kg*1000+g;
        return total;
    }
    
};

Weight add_weight(Weight a, Weight b){
    Weight w3;
    int all = a.get_weight()+b.get_weight();
    int kg = all/1000;
    int g = all%1000;
    
    w3.set_weight(kg,g);
        return w3;
    }

bool less_than(Weight a,Weight b){
    if(a.get_weight() < b.get_weight()) return true;
    else return false;
}


int main(void){

    Weight  w1, w2, w3;  // weight라는 class object 3개 생성

    w1.set_weight(3, 400);  // w1을 3kg 400 g으로 
    
    w2.set_weight(2, 700);  // w2을 2kg 700 g으로 

    w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 6kg 100g

    cout<< w3.get_weight( ) << "grams\n"; // w3의 값 ‘6100 grams’ 출력

    if ( less_than(w1, w2) ) // w1이 w2보다 작은 값인가 판단

        cout<< "yes.\n"; 

    else

        cout<< "no.\n";   // 작지 않으므로 ‘no’ 출력
    return EXIT_SUCCESS;
}