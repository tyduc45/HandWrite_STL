#include "LinkedList.h"

int main()
{
	LinkedList<int>* list1 = new LinkedList<int>();
	delete list1;

	LinkedList<int>* list2 = new LinkedList<int>();
	list2->insertAtFront(1);
	list2->insertAtFront(2);
	list2->insertAtFront(3);

	list2->insertAtEnd(5);
	list2->insertAtEnd(6);
	list2->insertAtEnd(7);

	list2->InsertAtIndex(87, 2);
	list2->InsertAtIndex(23, 1);
	list2->InsertAtIndex(855, 4);
	list2->InsertAtIndex(86, 6);

	list2->display();


	list2->deleteAtFront();
	list2->deleteAtFront();
	list2->deleteAtFront();


	list2->deleteAtEnd();
	list2->deleteAtEnd();
	list2->deleteAtEnd();
	


	list2->deleteAtIndex(45);
	list2->deleteAtIndex(2);
	list2->deleteAtIndex(1);
	list2->deleteAtIndex(45); 
	list2->deleteAtIndex(45);
	


	list2->display();

	std::cout << list2->getSize()<<"\n";

	std::cout << "copy function test\n";
	LinkedList<int> list3 = *list2;
	list3.display();

	LinkedList<int> list4 = std::move(list3);
	LinkedList<int> list5 = std::move(*list2);
	std::cout << "after move function called\n";
	list4.display();
	list3.display();
	list2->display();

	std::cout << list2->getSize() << "\n";
	std::cout << list3.getSize() << "\n";
	std::cout << list4.getSize() << "\n";

	delete list2;
	return 0;
}