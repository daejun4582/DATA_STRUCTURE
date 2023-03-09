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
        bool stack_full();
        bool stack_empty();

};


#endif