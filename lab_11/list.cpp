#include <iostream>
#include <list.hpp>

using namespace std;

bool comparator (int a, int b) {
    return a > b;
}

List::List() {
        head = new list();
        tail = new list();
        head->next = tail;
        tail->prev = head;
}

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
        New->next = head->next;
        New->prev = head;
        head->next = New;
        return;
    }

    list* current = head->next;

    for (int i = 0; i < index - 1 && current != tail; i++) {
        current = current->next;
    }

    if (current == tail) {
        delete New; 
        return;
    }
    
    New->next = current->next;
    New->prev = current;
    current->next = New;
}

void List::print () {
    list* current = head->next;

    while (current != tail) {
        cout << current->data << " " ;
        current = current->next;
    }
    cout << endl;
}

void List::pop (int index) {
    if (index < 0)
        return;


    list* current = head->next;

    for (int i = 0; i < index && current != tail; i++) {
        current = current->next;
    }

    if (current == tail) 
        return;

    list* tmp = current;
    current->next->prev = current->prev;
    current->prev->next = current->next;
    delete tmp;
}

void List::sort (bool compare(int a, int b)) {
    int count = 1;
    
    while (count != 0) {
        count = 0;
        list* current = head->next;
        while (current->next != tail) {
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

list* List::getTail() const {
    return tail;
}