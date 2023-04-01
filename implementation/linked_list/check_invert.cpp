#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list/LinkedList.h>

using namespace std;

int main(void){
    LinkedList a = LinkedList(),b = LinkedList();
    Node temp,tmp;
    struct data indata;


    indata.name = "Ban";
    indata.id = "22200341";
    indata.score = 123;
    temp.setData(indata);
    a.add_to_head(temp);

    indata.name = "Dae";
    indata.id = "22200342";
    indata.score = 123;
    temp.setData(indata);
    a.add_to_head(temp);

    indata.name = "Jun";
    indata.id = "22200343";
    indata.score = 123;
    temp.setData(indata);
    a.add_to_head(temp);


    b.add_to_head(temp);

    indata.name = "Dae";
    indata.id = "22200342";
    indata.score = 123;
    temp.setData(indata);
    b.add_to_head(temp);

    indata.name = "Ban";
    indata.id = "22200341";
    indata.score = 123;
    temp.setData(indata);
    b.add_to_head(temp);


    a.invert();

    if (list_equal(a, b))
        cout << "Yes, the two lists are identical. \n";
    else
        cout << "No, They are not identical.\n";

    tmp = b.delete_from_head();
    cout << tmp.getData().name << " : " << tmp.getData().score<< endl;
    
    return EXIT_SUCCESS;
}