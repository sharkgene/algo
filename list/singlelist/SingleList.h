#include <iostream>

template <class T>
class Node
{
  public:
    T data;
    Node<T> *next;
};

template <class T>
class SingleList
{
  private:
    Node<T> *head;

  public:
    SingleList()
    {
        head = new Node<T>;
        head->next = nullptr;
    }
    SingleList(const SingleList<T> &ln)
    {
        SingleList();
        for (auto pre = head, p = ln.head->next; p->next != nullptr;)
        {
            pre->next = new Node<T>;
            pre->next->data = p->data;
            pre = pre->next;
        }
    }
    ~SingleList()
    {
        for (auto p = head; p->next != nullptr;)
        {
            auto tmp = p->next;
            delete p;
            p = tmp;
        }
        //delete head;
        //head = nullptr;
    }
    void tailAdd(T d)
    {
        Node<T> *prep;
        for (auto p = head; p != nullptr; p = p->next)
        {
            prep = p;
        }
        prep->next = new Node<T>;
        prep->next->data = d;
        prep->next->next = nullptr;
    }
    void headAdd(T d)
    {
        Node<T> *tmp = new Node<T>;
        tmp->data = d;
        tmp->next = head->next;
        head->next = tmp;
    }
    Node<T> *findList(T d)
    {
        for (auto p = head->next; p != nullptr; p = p->next)
        {
            if (p->data == d)
            {
                std::cout << "found " << d << std::endl;
                return p;
            }
        }
        std::cout << "not found " << d << std::endl;
        return nullptr;
    }
    void LoopList(T d)
    {
        Node<T> *ptr, *p;
        for (p = head->next; p->next != nullptr; p = p->next)
        {
            if (p->data == d)
            {
                ptr = p;
            }
        }
        p->next = ptr;
    }
    void UnLoopList(Node<T> *node)
    {
        Node<T> *ptr, *p;
        int again = 0;
        for (p = head->next; p->next != nullptr; p = p->next)
        {
            if (p->next == node)
            {
                if (again == 0)
                    again = 1;
                else
                {
                    p->next = nullptr;
                    break;
                }
            }
        }
    }
    Node<T> *EntryNodeofLoop()
    {
        Node<T> *fast, *slow;
        for (fast = head->next, slow = head->next; fast != nullptr && fast->next != nullptr;)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                fast = head->next;
                for (; fast != slow; fast = fast->next, slow = slow->next)
                {
                }
                std::cout << "Entry Node data is " << fast->data << std::endl;
                return fast;
            }
        }
        std::cout << "Not loop list " << std::endl;
        return nullptr;
    }
    void printList()
    {
        std::cout << "printList: ";
        for (auto p = head->next; p != nullptr; p = p->next)
            std::cout << "[" << p->data << "]";
        std::cout << std::endl;
    }
    void reverse()
    {
        if (head->next == nullptr || head->next->next == nullptr)
            return;
        Node<T> *p, *q, *r;
        for (p = head->next, q = p->next, p->next = nullptr; q != nullptr;)
        {
            //std::cout << "p:" << p->data << ", q:" << q->data << std::endl;
            r = q->next;
            q->next = p;
            p = q;
            q = r;
            //std::cout << "p:" << p->data << std::endl;
        }
        head->next = p;
    }
    int lengthOfList()
    {
        int len = 0;
        for (auto p = head->next; p != nullptr; len++, p = p->next)
        {
        }
        return len;
    }
    void sortList()
    {
        for (auto p = head->next; p != nullptr; p = p->next)
        {
            for (auto q = p->next; q != nullptr; q = q->next)
            {
                if (p->data > q->data)
                {
                    auto tmp = p->data;
                    p->data = q->data;
                    q->data = tmp;
                }
            }
        }
    }
    void mergeList(SingleList &ln)
    {
        Node<T> *ptr, *p1, *p2;
        for (ptr = head, p1 = head->next, p2 = ln.head->next; p1 != nullptr && p2 != nullptr; ptr = ptr->next)
        {
            if (p1->data < p2->data)
            {
                ptr->next = p1;
                p1 = p1->next;
            }
            else
            {
                ptr->next = p2;
                p2 = p2->next;
            }
        }
        if (p1 == nullptr)
        {
            ptr->next = p2;
        }
        else
        {
            ptr->next = p1;
        }
        ln.head->next = nullptr;
        delete ln.head;
    }
    Node<T> *middleOfList()
    {
        Node<T> *fast, *slow;
        for (fast = head, slow = head; fast != nullptr && fast->next != nullptr; slow = slow->next, fast = fast->next->next)
        {
        }
        //if (fast != nullptr)
        //    slow = slow->next;
        std::cout << "middle node data is " << slow->data << std::endl;
        return slow;
    }
};