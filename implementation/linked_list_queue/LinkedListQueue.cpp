#include <iostream>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list_queue/LinkedListQueue.h>

LinkedListQueue::LinkedListQueue(){
    _q = LinkedList();
}
bool LinkedListQueue::Enqueue(struct data indata){
    Node t;
    t.setData(indata);
    _q.add_to_tail(t);
    return true;
}
struct data LinkedListQueue::Dequeue(){
    Node result = _q.delete_from_head();
    return result.getData();
}
bool LinkedListQueue::Queue_empty(){
    if(_q.list_empty()) return true;
    return false;
}
void LinkedListQueue::get_all_dataes(){
    _q.get_all();
}