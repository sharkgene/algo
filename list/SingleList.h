#include <iostream>

template <class T>
class Node {
    public:
    T data;
    Node<T> *next;    
};

template <class T>
class SingleList{
    private:
    Node<T> *head;
    Node<T> *tail;

    public:
    SingleList(){
        head = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        tail->next = nullptr;
    }
    SingleList(const SingleList &ln){
        head = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        tail->next = nullptr;
        for (auto p = ln.head->next; p->next != nullptr; p = p->next) {
            tail->data = p->data;
            tail->next = new Node<T>;
            tail = tail->next;
            tail->next = nullptr;
        }
    }
    ~SingleList(){
        Node<T> *next;
        for (auto p = head->next; p->next != nullptr; ) {
           next = p->next;
           delete p;
           p = next; 
        }
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    Node<T>* getHead() {
        return head->next;
    }
    void PrintList() {
        //if (head->next == tail)  {
        //    std::cout << "The list is empty" << std::endl;
        //    return;
        //}
        std::cout << "Print the list: ";
        for (auto p = head->next; p->next != nullptr; p = p->next) {
            std::cout << "[" << p->data << "] ";
        }
        std::cout << std::endl;
    }
    void ReversePrintList(Node<T>* &node) {
        //std::cout << "Print the list: ";
        if (node->next != tail)
            ReversePrintList(node->next);
        std::cout << node->data;
        //std::cout << std::endl;
    }
    void append(T d) {
        tail->data = d;
        tail->next = new Node<T>;
        tail = tail->next;
        tail->next = nullptr;
    }
    void headAdd(T d) {
        Node<T> *data = new Node<T>;
        data->data = d;
        data->next = head->next;
        head->next = data;
    }
    void insert(T d, T e) {
        Node<T> *p = head->next;
        for (; p != tail; p = p->next) {
            if (p->data == d) {
                Node<T> *tmp = new Node<T>;
                tmp->data = e;
                tmp->next = p->next;
                p->next = tmp;
                return;
            }
        }
        append(e);
    }
    void tailDelete() {
        if (head->next == tail)
            return;
        Node<T> *prep = head;
        Node<T> *p;
        for (p = head->next; p->next != tail; p = p->next) {
            prep = p;
        }
        prep->next = p->next;
        delete p;
    }
    void remove(T d) {
        if (head->next == tail)
            return;
        Node<T> *prep = head;
        Node<T> *p;
        for (p = head->next; p->next != tail; p = p->next) {
            if (p->data == d)
                break;
            prep = p;
        }
        if (p->next != tail) {
            prep->next = p->next;
            delete p;
        }
    }
    void headDelete() {
        if (head->next == tail)
            return;
        Node<T> *p = head->next;
        head->next = p->next;
        delete p;
    }
    void reverse() {
        Node<T> *prep = head->next;
        Node<T> *p = prep->next;
        if (p == tail || p == nullptr) 
            return;

        Node<T> *next;
        for (; p != tail; ) {
            //std::cout << "prep & p " << prep->data << ", " << p->data << std::endl;
            next = p->next;
            p->next = prep;
            prep = p;
            p = next;
        }
        head->next->next = tail;
        head->next = prep;
    }
    bool compare(const SingleList &ln) {
        Node<T> *p1, *p2;
        for(p1 = head->next, p2 = ln.head->next; p1 != tail && p2 != ln.tail;) {
            if (p1->data == p2->data) {
                p1 = p1->next;
                p2 = p2->next;
                continue;
            }
            return false;
        }
        if (p1 == tail && p2 == ln.tail)  {
            return true;
        } else
            return false;
    }
};