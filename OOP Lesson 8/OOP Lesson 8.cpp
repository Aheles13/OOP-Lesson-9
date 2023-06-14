#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "LinktList.h"




int main()
{
	setlocale(LC_ALL, "Ru");

	LinktList list;
	list.AddHead(10);
	
	list.ShowList();
	std::cout << "\n\n";
	list.DeleteElement(5);
	list.ShowList();




	return 0;
}
