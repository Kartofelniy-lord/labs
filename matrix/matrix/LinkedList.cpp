#include <iostream>
using namespace std;

struct Node
{
	char data;
	Node* next;
};

class List
{
	Node* first;
public:
	List() : first() {}
	void add(char x)
	{
		if (!first)
		{
			first = new Node;
			first->data = x;
			first->next = 0;
		}
		else
		{
			Node* current = new Node;
			current->data = x;
			current->next = first;
			first = current;
		}
	}
	void show()
	{
		Node* current = first;
		while (current)
		{
			cout << current->data << ' ';
			current = current->next;
		}
		cout << '\n';
	}
	void deleteDublicate()
	{
		Node* bufi = 0;
		bool firstChang = false;
		for (Node* i = first; i; i = i->next)
		{
			if (firstChang)
			{
				i = first;
				firstChang = false;
			}
			bool isDubl = false;
			Node* bufj = first;
			for (Node* j = first; j; j = j->next)
			{
				if (i->data == j->data && i != j)
				{
					bufj->next = j->next;
					delete j;
					j = bufj;
					isDubl = true;
				}
				bufj = j;
			}
			if (isDubl)
			{
				if (i == first)
				{
					bufi = i->next;
					delete i;
					i = bufi;
					first = i;
					if (!i) return;
					firstChang = true;
				}
				else
				{
					bufi->next = i->next;
					delete i;
					i = bufi;
				}
			}
			bufi = i;
		}
	}
	~List()
	{
		Node* current = first;
		while (first)
		{
			current = first->next;
			delete first;
			first = current;
		}
		first = 0;
	}
};
