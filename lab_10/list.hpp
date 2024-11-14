#ifndef LIST_HPP
#define LIST_HPP

bool comparator (int a, int b);

struct list {
    int data;
    list* next;

    list(int value): data(value), next(nullptr) {}
};

class List {
private:
    list* head;
public:
    List();

    void insert (int index, int value);
    void print ();
    void pop (int index);
    void sort (bool compare(int a, int b) = comparator);
    list* getHead() const;
};

#endif