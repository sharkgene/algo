#ifndef SLINK_H
#define SLINK_H
#include "Node.h"
#include <iostream>
template <class T>
class Slist
{
public:
	Slist();//默认构造函数
	Slist(const Slist& ln);//拷贝构造函数
	~Slist();//析构函数
	void add(T e);//向链表添加数据
	void ascSort();//升序排序
	void remove(T index);//移除某个结点
	T find(int index);//查找结点
	bool isEmpty();//判断是否为空
	int size();//链表长度
	void show();//显示链表
	void resShow();//链表反向显示
	void removeAll();//删除全部结点
	void reverse();//反转链表
private:
	Node<T> *head;
	Node<T> *tail;
	int length;
};
 
//////////////////////////////////////////////////////////////////////////////////
//默认构造函数
template <typename T>
Slist<T>::Slist()
{
	head = new Node<T>;
	tail = new Node<T>;
	head->next = tail;
	tail->next = nullptr;
	length = 0;
}

//拷贝构造函数
template <typename T>
Slist<T>::Slist(const Slist &ln)
{
	head = new Node<T>;
	tail = new Node<T>;
	head->next = tail;
	tail->next = nullptr;
	length = 0;
	Node<T>* temp = ln.head;
	while(temp->next != ln.tail)
	{
		temp = temp->next;
		tail->data = temp->data;
		Node<T> *p = new Node<T>;
		tail->next = p;
		tail  = p;
		length++;
	}
	tail->next = nullptr;
}

//向链表添加数据
template <typename T>
void Slist<T>::add(T e)
{
	Node<T>* temp = this->tail;
	tail->data = e;
	tail->next = new Node<T>;
	tail = tail->next;
	tail->next = nullptr;
	length++;
}
//查找结点
template <typename T>
T Slist<T>::find(int index)
{
	if(length == 0)
	{
		std::cout << "Slist is empty";
		return NULL;
	}
	if(index >= length)
	{
		std::cout << "Out of bounds";
		return NULL;
	}
	int x = 0;
	T data;
	Node<T> *p;
	p = head->next;
	while (p->next != nullptr && x++ != index)
	{
		p=p->next;
	}
	return p->data;
}
//删除结点
template <typename T>
void Slist<T>::remove(T index)
{
	if(length == 0)
	{
		std::cout << "Slist is empty";
		return ;
	}
	Node<T> *p = head;
	Node<T> *prep;
	while(p->next!=nullptr)
	{
		prep = p;
		p = p->next;
		if(p->data == index)
		{
			prep->next = p->next;
			delete p;
			length--;
			return ;
		}
	}
}
//删除所有结点
template <typename T>
void Slist<T>::removeAll()
{
	if(length == 0)
	{
		return ;
	}
	Node<T> *p = head->next;
	while(p != tail)
	{
		Node<T>* temp = p;
		p = p->next;
		delete temp;
	}
	head->next = tail;
	length = 0;
}
//升序排序
template <typename T>
void Slist<T>::ascSort()
{
	if(length <= 1) return;
	Node<T> *p = head->next;
	for (int i = 0; i < length-1; i++)
	{
		Node<T> *q = p->next;
		for (int j = i+1; j < length; j++)
		{
			if(p->data > q->data)
			{
				T temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
			q=q->next;
		}
		p = p->next;
	}
}
//判断是否为空
template <typename T>
bool Slist<T>::isEmpty()
{
	if(length == 0)
	{
		return true;
	} else {
		return false;
	}
}
//链表长度
template <typename T>
int Slist<T>::size()
{
	return length;
}
//输出链表
template <typename T>
void Slist<T>::show()
{
	if(length == 0)
	{
		std::cout << "Slist is empty" << std::endl;
		return;
	}
	Node<T> *p = head->next;
	while (p != tail)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
//反转链表
template <typename T>
void Slist<T>::reverse()
{
	if(length <= 1 )
		return;
	Node<T> *prep = head->next;
	Node<T> *p = prep->next;
	prep->next = tail;
	Node<T> *next;
	while (p != tail)
	{
		//std::cout << "prep & p data is " << prep->data  <<", " << p->data << std::endl;
		next = p->next;
		p->next = prep;
		prep = p;
		p = next;
	}
	head->next = prep;
}


template <typename T>
Slist<T> resOut(Slist<T> link, T p) {
   if (p->next != link.tail)
	   return p->data;
   else 
	   return resOut(link, p->next);
}
//反向输出链表
template <typename T>
void Slist<T>::resShow()
{
	std::cout << resOut(this, head) << std::endl;
}
//析构函数
template <typename T>
Slist<T>::~Slist()
{
	if(length == 0)
	{
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return;
	}
	while(head->next != nullptr)
	{
		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	head = nullptr;
}
 
#endif 

