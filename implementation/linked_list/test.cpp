#include <iostream>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list/LinkedList.h>
using namespace std;



int main(){

    LinkedList  a;
    Node   tmp;
    tmp.setData("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.setData("Lee", 58.2);
    a.add_to_head(tmp);
    tmp.setData("Park", 91.3);
    a.add_to_head(tmp);
    tmp.setData("Choi", 55.1);
    a.add_to_head(tmp);
    tmp.setData("Ryu", 77.1);
    a.add_to_head(tmp);
    tmp.setData("Yang", 41.3);
    a.add_to_head(tmp);
    tmp.setData("Hong", 78.2);
    a.add_to_head(tmp);
    cout << " --- The contents of the list A ---\n";
    a.get_all();




    double max;
    Node *s_array;
    int n;
    n = a.num_nodes();
    s_array = new Node[n];
    make_array_from_list(s_array, a);
    cout << "\n --- The contents of the array --- \n";
    for (int k = 0;k < n ;k++)
    cout <<  k << " : " << s_array[k].getData().name << " : " << s_array[k].getData().score << endl;

    LinkedList b;
    tmp.setData("Bae", 88.4);
    b.add_to_head(tmp);
    tmp.setData("Son", 67.2);
    b.add_to_head(tmp);
    tmp.setData("Cho", 97.5);
    b.add_to_head(tmp);
    tmp.setData("Kwon", 77.4);
    b.add_to_head(tmp);

    b.get_all();

    a.list_merge(b);   
    cout << "\n\n --- The contents of the list A --- \n";
    a.get_all();
    max = a.score_max();
    cout << "\n\n The max. score  = " << max << "\n\n";

    return 0;


}