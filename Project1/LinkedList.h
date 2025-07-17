#ifndef LINKED_LIST_
#define LINKED_LIST_

#include<iostream>
#include<stdexcept>
#include<exception>

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node() :data(T()),next(nullptr){}
};


template<typename T>
class LinkedList
{
private:
	Node<T>* head;

public:
	// default constructor

	LinkedList()
	{
		std::cout << "defualt constructor called\n";
		head = new Node<T>();
	}

	~LinkedList()
	{
		clear();
		delete head;
	}

	void clear()
	{
		Node<T>* ptr = head->next;
		while (ptr)
		{
			head->next = ptr->next;
			delete ptr;
			ptr = head->next;
		}
	}

	void display()
	{
		Node<T>* ptr = head;

		while (ptr != nullptr)
		{
			std::cout << ptr->data << "->";
			ptr = ptr->next;
		}
		std::cout << "\n";
	}

	// copy constructor
	LinkedList(const LinkedList& other)
	{
		std::cout << "copy constructor called,ref version\n";
		head = new Node<T>();

		Node<T>* ptrOther = other.head->next;
		Node<T>* ptrLocal = head;

		while (ptrOther != nullptr)
		{
			ptrLocal->next = new Node<T>();
			ptrLocal = ptrLocal->next;

			ptrLocal->data = ptrOther->data;
			ptrLocal->next = nullptr;
			ptrOther = ptrOther->next;
		}
	}

	void swap(Node<T>* other)
	{
		std::swap(head,other); // ����ͷ
	}

	LinkedList& operator=(const LinkedList& other)
	{
		if (this == &other)
		{
			return *this;
		}

		LinkedList temp(other); // �������
		swap(temp.head);

		return *this;
	}

	

	// move constructor
	LinkedList(LinkedList&& other)
	{
		head = new Node<T>();
		// �ӹܿ���Ȩ
		head->next = other.head->next;

		other.head->next = nullptr; // keep the head
	}

	LinkedList& operator=(LinkedList&& other)
	{
		if (this != &other) // ע�� other������������ֵ(��ֵ�����Ƕ���ֵ�ġ����á� ������ֵ����)
		{
			clear();
			head = other.head;
			other.head = nullptr;
		}

		return *this;
	}


	bool isEmpty() const
	{
		size_t size = getSize();
		return size == 0;
	}


	size_t getSize() const
	{
		Node<T>* ptr = head;
		size_t size = 0;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
			++size;
		}
		return size;
	}

	void insertAtFront(T value)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = value;
		newNode->next = nullptr;

		newNode->next = head->next;
		head->next = newNode;
	}

	void insertAtEnd(T value)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = value;
		newNode->next = nullptr;

		Node<T>* ptr = head;

		// find tail
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}

	void InsertAtIndex(T value, size_t index) //[0......n-1]
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = value;
		newNode->next = nullptr;

		size_t size = getSize();

		// find correct position
		Node<T>* ptr = head;
		while (index > 0 && index < size)
		{
			ptr = ptr->next;
			index--;
		}
		if (index > size)
		{
			std::cout << "index is too big, inserted at the end of the array bu default\n";
			insertAtEnd(value);
		}

		newNode->next = ptr->next;
		ptr->next = newNode;
	}

	T deleteAtFront()
	{
		if (isEmpty())
		{
			std::cout << "the linkedList is now empty\n";
			return -1;
		}
		Node<T>* curr = head->next;
		head->next = curr->next;
		T temp = curr->data;
		curr->next = nullptr;
		delete curr;
		return temp;
	}

	T deleteAtEnd()
	{
		Node<T>* prev = head;
		Node<T>* curr = head;
		if (isEmpty())
		{
			std::cout << "the linkedList is now empty\n";
			return -1;
		}

		// go to the end
		while (curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}

		T temp = curr->data;
		delete curr;

		prev->next = nullptr;
		return temp;
	}

	T deleteAtIndex(size_t index)
	{
		if (isEmpty())
		{
			std::cout << "the linkedList is now empty\n";
			return -1;
		}
		Node<T>* prev = head;
		Node<T>* curr = head;

		size_t size = getSize();

		// go to the right position
		while (index > 0 && index < size)
		{
			prev = curr;
			curr = curr->next;
			--index;
		}

		if (index > size)
		{
			std::cout << "index is too big, delete the element at of the array bu default\n";
			T temp = deleteAtEnd();
			return temp;
		}

		prev->next = curr->next;

		T temp = curr->data;
		curr->next = nullptr;

		delete curr;
		return temp;
	}

	void modify(T value, size_t index)
	{
		Node<T>* ptr = head;

		// go to the right position
		while (index > 0)
		{
			ptr = ptr->next;
		}

		ptr->data = value;
	}

	T search(size_t index)
	{
		Node<T>* ptr = head;
		T temp = T();

		// go to the right position
		while (index > 0)
		{
			ptr = ptr->next;
		}

		temp = ptr->data;
		return temp;
	}


};

#endif