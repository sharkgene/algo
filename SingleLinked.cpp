#include <iostream>

class Node {
	public:
	char data;
	Node *next;
};

class LinkList {
	private:
		Node *Head;
	public:
		LinkList();
		void CreateList();
		void Display();
		//void CreateList1(char d);
		//void CreateList2(char d);
		bool isPalindrome();
};

LinkList::LinkList() {
	Head = new Node;
 	Head->next = NULL;
}

void LinkList::CreateList() {
	Node *p;
	Node *temp;
	std::string datastr;
	p = Head;
	std::cout << "Pls input string " << std::endl;
	std::cin >> datastr;
	for (auto  i = 0; i < int(datastr.length()); i++) {
		temp = new Node;
		temp->data = datastr[i];
		temp->next = NULL;
		p->next = temp;
		p = temp;
	}
}

void LinkList::Display() {
	for (auto p = Head->next; p != NULL; p = p->next){
		std::cout << "data is " << p->data << std::endl;
	}
}

bool LinkList::isPalindrome() {
	Node *fast;
	Node *slow;
	for (fast = Head->next, slow = Head->next; ;) {
		if (fast->next != NULL)
			fast = fast->next;

		fast = 
	}
}

int main()
{
	LinkList ll;
	ll.CreateList();
	std::cout << "go throught the link" << std::endl;
	ll.Display();

}

