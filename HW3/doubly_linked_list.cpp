#include "doubly_linked_list.h"
#include "container_exception.h"

DoublyLinkedList::DoublyLinkedList() {
    header = new Node();
    trailer = new Node();
    header->prev = nullptr;
    header->next = trailer;
    trailer->prev = header;
    trailer->next = nullptr;
}
bool DoublyLinkedList::empty() const {
    if (header == nullptr) throw ContainerException("Attempted to access an object after its destructor was executed.");
    return header->next==trailer;
}
const std::string& DoublyLinkedList::front() const {
    if (empty()) throw ContainerEmpty("Attempted to access the front element of an empty list.");
    return header->next->ele;
}
const std::string& DoublyLinkedList::back() const {
    if (empty()) throw ContainerEmpty("Attempted to access the back element of an empty list.");
    return trailer->prev->ele;
}
void DoublyLinkedList::add_front(const std::string& e) {
    if (header == nullptr) throw ContainerException("Attempted to access an object after its destructor was executed.");
    Node* node = new Node();
    node->ele = e;
    node->next = header->next;
    node->prev = header;
    header->next->prev = node;
    header->next = node;
}
void DoublyLinkedList::add_back(const std::string& e) {
    if (header == nullptr) throw ContainerException("Attempted to access an object after its destructor was executed.");
    Node* node = new Node();
    node->ele = e;
    node->next = trailer;
    node->prev = trailer->prev;
    trailer->prev->next = node;
    trailer->prev = node;
}
void DoublyLinkedList::remove_front() {
    if (empty()) throw ContainerEmpty("Attempted to remove an element from an empty list.");
    header->next = header->next->next;
    delete header->next->prev;
    header->next->prev = header;
}
void DoublyLinkedList::remove_back() {
    if (empty()) throw ContainerEmpty("Attempted to remove an element from an empty list.");
    trailer->prev = trailer->prev->prev;
    delete trailer->prev->next;
    trailer->prev->next = trailer;
}
int DoublyLinkedList::size() const {
    if (header == nullptr) throw ContainerException("Attempted to access an object after its destructor was executed.");
    int cnt = 0;
    Node* cur = header->next;
    while (cur != trailer) {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}
DoublyLinkedList::~DoublyLinkedList() {
    if (header != nullptr) {
        while (header->next != trailer) {
            remove_front();
        }
        delete header;
        delete trailer;
        header = nullptr;
        trailer = nullptr;
    }
}
