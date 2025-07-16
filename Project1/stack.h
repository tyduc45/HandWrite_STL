#ifndef _STACK_H
#define _STACK_H	


#include <iostream>
#include <cassert>

template <typename T>
class Stack
{
private:
	T* data;
	size_t size;
	size_t capacity;


	void resize(size_t newCapacity)
	{
		T* newData = new T[newCapacity];
		for (int i = 0; i < size; i++)
		{
			newData = data[i];
		}
		delete[] data;
		data = newdata; // ��ʱ������resize������Ҳ��֮������
		capacity = newCapacity;
	}
public:
	Stack() : data(nullptr), size(0), capacity(0) {}

	Stack(const Stack& other):data(nullptr),size(other.size),capacity(other.capacity)
	{
		if (capacity > 0)
		{
			data = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				data[i] = other.data[i];// Ϊʲô �����ܷ���other��˽������data
			}
		}
	}
	~Stack()
	{
		// �ͷ��ڴ�
		delete[] data;
		// Ϊʲôcapacity��size����Ҫ���ó�Ϊ0��
		size = 0;
		capacity = 0;
	}

	void push(const T& value)
	{
		++size;
		if (size == capacity)
		{
			resize(capacity * 2);
		}
		data[size - 1] = data;
	}

	void pop()
	{
		if (size > 0)
		{
			--size;
		}
	}

	const T& top() const
	{
		if (size == 0)
		{
			throw std::out_of_range("Stack is empty")
		}
		return data[size-1];
	}

	bool empty() const
	{
		return (size == 0);
	}

	size_t getSize() const
	{
		return size;
	}

};

template <typename T>
class StackIterator
{
private:
	T* ptr;
public:
	StackIterator(T* p) : ptr(p) {}
	T& operator*() { return *ptr; }
	StackIterator& operator++() { ++ptr; return *this }
	bool operator != (const Iterator& other) { return ptr != other.ptr; }
};

#endif
