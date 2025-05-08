#include "deque.h"
#include "stack.h"

bool Deque::empty() const {
    return list.empty();
}
int Deque::size() const {
    return list.size();
}
const std::string &Deque::front() const {
    return list.front();
}
const std::string &Deque::back() const {
    return list.back();
}
void Deque::push_front(const std::string &e) {
    list.add_front(e);
}
void Deque::push_back(const std::string &e) {
    list.add_back(e);
}
void Deque::pop_front() {
    list.remove_front();
}
void Deque::pop_back() {
    list.remove_back();
}
void Deque::reverse() {
    Stack stack(size());
    while (!empty()) {
        stack.push(front());
        pop_front();
    }
    while (!stack.empty()) {
        push_back(stack.top());
        stack.pop();
    }
}








