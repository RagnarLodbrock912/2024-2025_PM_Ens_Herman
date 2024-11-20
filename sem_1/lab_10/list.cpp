#include <iostream>
#include <list.hpp>

using namespace std;

bool comparator (int a, int b) {
    return a > b;
}

List::List() : head(nullptr) {}

List::~List () {
    list* current = head;
    while (current) {
        list* next = current->next;
        delete current;
        current = next;
    }
}

void List::insert (int index, int value) {
    if (index < 0)
        return;

    list* New = new list(value);

    if (index == 0) {
        New->next = head;
        head = New;
        return;
    }

    list* current = head;

    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        delete New; 
        return;
    }
    
    New->next = current->next;
    current->next = New;
}

void List::print () {
    list* current = head;

    while (current != nullptr) {
        cout << current->data << " " ;
        current = current->next;
    }
    cout << endl;
}

void List::pop (int index) {
    if (index < 0 || head == nullptr)
        return;

    if (index == 0) {
        list* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    list* current = head;

    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) 
        return;

    list* tmp = current->next;
    current->next = current->next->next;
    delete tmp;
}

void List::sort (bool compare(int a, int b)) {
    int count = 1;
    
    while (count != 0) {
        count = 0;
        list* current = head;
        while (current->next != nullptr) {
            if (compare(current->data, current->next->data)) {
                int tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;
                count++;
            }
            current = current->next;
        }
    }
}

list* List::getHead() const {
        return head;
    }

