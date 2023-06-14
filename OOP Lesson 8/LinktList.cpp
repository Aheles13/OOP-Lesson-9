#include "LinktList.h"

LinktList::LinktList() : _head(nullptr), _tail(nullptr), _size(0){}

void LinktList::AddTail(int data)
{
	Node* newTeil = new Node(data);
	_size++;

	if (_head == nullptr)
	{
		_head = newTeil;
		_tail = newTeil;
		return;
	}

	_tail->prev = newTeil;
	newTeil->next = _tail;
	_head->next = newTeil;
	_tail = newTeil;
	_tail->prev = _head;
}

void LinktList::AddHead(int data)
{
	Node* newHead = new Node(data);
	_size++;

	if (_head == nullptr)
	{
		_tail = newHead;
		_head = newHead;
		return;
	}
	_head->next = newHead;
	newHead->prev = _head;
	newHead->next = _tail;
	_head = newHead;
}

void LinktList::ShowList()
{
	if (_size == 0)
	{
		std::cout << "NO!";
		return;
	}

	int index = 0;
	for (Node *nodePtr = _head; index != _size; nodePtr = nodePtr->prev, index++)
		std::cout << "Data:" << nodePtr->GetData() << "\n";
}

void LinktList::DeleteElement(int index)
{
	/*if (deleted == _head )
	{
		_head->prev->next = _head->next;
	}

	if (_size < 3)
	{
		Node* deleted = FindElement();
		deleted->next->next = nullptr;
		deleted->next->prev = nullptr;
		_size--;
		return;
		
	}*/
	
	if (_size == 1)
	{
		_size--;
		delete(_head);
		return;
	}

	Node* deleted = FindElement(index);
	Node* prevDeleted = deleted->prev;
	Node* nextDeleted = deleted->next;
	prevDeleted->next = nextDeleted;
	prevDeleted->prev = prevDeleted;
	
	if (deleted == _head)
		_head = deleted->prev;

	else if (deleted == _tail)
		_tail = deleted->next;

	_size--;

	delete(deleted);
}

Node* LinktList::FindElement(int index)
{
	if (index < 0 || index > _size) return nullptr;

	if (index == 1) return _head;

	else
		if (index == _size) return _tail;

	Node* nodePtr = _head;
	index--;
	while (index != 0)
	{
		nodePtr = nodePtr->prev;
		index--;
	}

	return nodePtr;
}


void LinktList::DeleteList()
{
	Node* nodePtr = _tail;

	while (_size > 0)
	{
		nodePtr = nodePtr->next;
		delete(_tail);
		_tail = nodePtr;
		_size--;
	}
}