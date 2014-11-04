// templatedlinkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list;

	for (int i = 0; i < 100; i += 5){
		list.addNode(i);
	}

	list.showList();

	system("pause");
	return 0;
}
