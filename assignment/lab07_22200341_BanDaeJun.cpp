#include <iostream>
#define HSIZE 100
using namespace std;

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
        void adjust(int t_root);
};

int main()

{

   my_heap   h1;

   element   temp;

   temp.set_data("Kim", 88);

   h1.insert_heap(temp);

   temp.set_data("Lee", 77);

   h1.insert_heap(temp);

   temp.set_data("Park", 98);

   h1.insert_heap(temp);

   temp.set_data("Choi", 74);

   h1.insert_heap(temp);

   temp.set_data("Ryu", 94);

   h1.insert_heap(temp);

   temp.set_data("Cho", 85);

   h1.insert_heap(temp);

   while (h1.h_size() > 0) {

        temp = h1.delete_heap();

        cout << temp.name << " : " << temp.score << "\n";

   }

   return 0;

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


void   my_heap::adjust(int t_root)
{
    double   tmpkey;
    int   child;
    element tmp;
    tmp = h[t_root];
    tmpkey = h[t_root].score;
    child = 2 * t_root;
    while (child <= csize) 
    {
        if ((child < csize) && (h[child].score < h[child + 1].score))
            child++;
        if (tmpkey > h[child].score)
            break;
        else 
        {
            h[child / 2] = h[child];
            child *= 2;
        }
    }
    h[child / 2] = tmp;
}