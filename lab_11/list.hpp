#ifndef LIST_HPP
#define LIST_HPP

bool comparator (int a, int b);

struct list {
    int data;
    list* next;
    list* prev;

    list(int value = 0): data(value), prev(nullptr), next(nullptr) {}
};

class List {
private:
    list* head;
    list* tail;
public:
    List();
    ~List();

    void insert (int index, int value);
    void print ();
    void pop (int index);
    void sort (bool compare(int a, int b) = comparator);
    list* getHead() const;
    list* getTail() const;
};

#endif