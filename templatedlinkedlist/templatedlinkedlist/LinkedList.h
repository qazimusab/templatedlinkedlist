// A class template for holding a linked list.
#define LINKEDLIST_H
#include <iostream>     
using namespace std;

template <class T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		struct Node *next;
	};

	Node *head;

public:
	LinkedList()
	{
		head = NULL;
	}
	~LinkedList()
	{
		Node *nodePtr;
		Node *nextNode;
		nodePtr = head;
		while (nodePtr != NULL)
		{
			nextNode = nodePtr->next;
			delete nodePtr;

			// Position nodePtr at the next node.
			nodePtr = nextNode;
		}
	};


	void addNode(T newGenericItem)
	{
		Node *newNode;
		Node *nodePtr;

		newNode = new Node;
		newNode->data = newGenericItem;
		newNode->next = NULL;

		if (!head)
			head = newNode;
		else
		{
			nodePtr = head;

			while (nodePtr->next)
				nodePtr = nodePtr->next;
			nodePtr->next = newNode;
		}
	};

	void deleteNode(T searchValue)
	{
		Node *nodePtr;
		Node *previousNode;

		if (!head)
			return;

		if (head->data == searchValue)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			nodePtr = head;
			while (nodePtr != NULL && nodePtr->data != searchValue)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (nodePtr)
			{
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}
	};

	void showList()
	{
		Node *nodePtr;
		nodePtr = head;

		while (nodePtr)
		{
			cout << nodePtr->data << endl;
			nodePtr = nodePtr->next;
		}
	};

};
