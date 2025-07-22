#include "LinkedList.h"
#include "rb_tree.h"
//#define L_LIST
//#define RB_TREE
//#define STACK
//#define QUEUE
//#define MAP
#define QUICKSORT

#ifdef L_LIST
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

#ifdef RB_TREE

	int even_num = 3;

	// asserts the value of even_num must be even
	assert((even_num % 2 == 0));
	std::cout << "program will run this code\n";

	return 0;

#endif 


}
#endif

#ifdef QUICKSORT
#include<iostream>
#include<vector>

int partition(std::vector<int>& vec, int lo, int hi)
{
	int pivot = vec[hi];
	
	int i = lo;

	for (int j = lo; j < hi; j++)
	{
		if (vec[j] < pivot)
		{
			std::swap(vec[i], vec[j]);
			i++;
		}
	}
	std::swap(vec[i], vec[hi]);
	return i;
}

void quicksort(std::vector<int>& vec, int lo, int hi)
{
	if (lo >= hi || lo < 0)
	{
		return;
	}

	int p = partition(vec, lo, hi);

	quicksort(vec, lo, p-1);
	quicksort(vec, p + 1, hi);
}


int main()
{
	std::vector<int> test = { 3,2,1 };

	quicksort(test, 0, test.size() - 1);

	for (auto& elem : test)
	{
		std::cout << elem << " ";
	}
	return 0;
}
#endif