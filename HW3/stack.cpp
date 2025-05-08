#include "stack.h"

#include "container_exception.h"

Stack::Stack(int size): capacity(size), top_index(-1), data(new std::string[size]) {}
bool Stack::empty() const {
    if (top_index == -2) throw ContainerException("Attempted to access an object after its destructor was executed.");
    return top_index == -1;
}
const std::string &Stack::top() const {
    if (empty()) throw ContainerEmpty("Attempted to access the top element of an empty stack.");
    return data[top_index];
}
void Stack::push(const std::string &e) {
    if (top_index == -2) throw ContainerException("Attempted to access an object after its destructor was executed.");
    if (top_index == capacity-1) throw ContainerOverflow("Attempted to push an element onto a full stack.");
    data[++top_index] = e;
}
void Stack::pop() {
    if (empty()) throw ContainerEmpty("Attempted to pop an element from an empty stack.");
    --top_index;
}
int Stack::size() const {
    if (top_index == -2) throw ContainerException("Attempted to access an object after its destructor was executed.");
    return top_index + 1;
}
Stack::~Stack() {
    if (top_index != -2) {  // -2는 객체가 소멸됐음을 의미.
        top_index = -2;
        delete [] data;
    }
}