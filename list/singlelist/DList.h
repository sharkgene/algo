#include <iostream>

template <class T>
class Node {
    public:
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template <class T>
class DList {
    private:
    Node<T> *head;
    Node<T> *tail;

    public: 
    DList() {
        head = new Node<T>;
        tail = new Node<T>;
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
    }
    DList(const DList &ln) {
        DList();
        Node<T> *ptr, *p;
        for (ptr = head, p = ln.head->next; p != ln.tail; p = p->next) {
            Node<T> *tmp = new Node<T>;
            tmp->data = p->data;
            tmp->prev = ptr;
            tmp->next = ptr->next;
            ptr->next = tmp;
            ptr = ptr->next;
        }
        tail->prev = ptr;
    }
    void PrintList() {
        std::cout << "PrintList: " << std::endl;
        for (auto p = head->next; p != tail; p = p->next) {
            std::cout << "[" << p->data << "]";
        }
        std::cout << std::endl;
    }
    void ReversePrintList() {
        std::cout << "PrintList: " << std::endl;
        for (auto p = tail->prev; p != head; p = p->prev) {
            std::cout << "[" << p->data << "]";
        }
        std::cout << std::endl;
    }
    void TailAdd(T d) {
        Node<T> *tmp = new Node<T>;
        tmp->data = d;
        tmp->prev = tail->prev;
        tmp->next = tail;
        tail->prev->next = tmp;
        tail->prev = tmp;
    }
    void HeadAdd(T d) {
        Node<T> *tmp = new Node<T>;
        tmp->data = d;
        tmp->prev = head;
        tmp->next = head->next;
        head->next->prev = tmp;
        head->next = tmp;
    }
    Node<T> *LastN(int n) {
        Node<T> *p;
        int i = 0;
        for (p = tail->prev, i = 0; p != head && i < n-1; i++, p = p->prev) {}
        if (p == head) {
            std::cout << "Not found " << n << " Node" << std::endl;
            return nullptr;
        }
        std::cout << "Last " << n << " data is " << p->data << std::endl;
        return p;
    }

};