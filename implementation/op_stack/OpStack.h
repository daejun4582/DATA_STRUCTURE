#ifndef __OPSTACK_H__
#define __OPSTACK_H__


class OpStack{
    private:
        char* p;
        int top;
        int size;
        int count;
    public:
        OpStack();
        void get_all();
        void push(char x);
        char pop();
        char get_top();
        bool stack_full();
        bool stack_empty();

};


#endif