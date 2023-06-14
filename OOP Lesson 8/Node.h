#pragma once

class Node
{
private:
	int _data;
public:
	Node* next;
	Node* prev;


	Node(int data);

	int GetData();
};