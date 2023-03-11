#ifndef __STACK_H__
#define __STACK_H__


class Stack{
    private:
        int* p;
        int top;
        int size;
        int count;
    public:
        Stack();
        void push(int x);
        int pop();
        int get_top();
        bool stack_full();
        bool stack_empty();

};


#endif