#pragma once
#include "Node.h"
#include <iostream>

class LinktList
{
private:
	Node* _head;
	Node* _tail;
	int _size;

public:
	LinktList();

	void AddTail(int data);

	void AddHead(int data);

	void ShowList();

	void DeleteElement(int index);

	void DeleteList();

	Node* FindElement(int index);
};