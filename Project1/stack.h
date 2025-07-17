#ifndef STACK_H_
#define STACK_H_	


#include <iostream>
#include <cassert>
#include <exception>

template <typename T>
class Stack
{
private:
	using const
	T* data;
	size_t size;
	size_t capacity;


	void resize(size_t newCapacity)
	{
		T* newData = new T[newCapacity];
		for (int i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData; // 临时变量，resize结束后也随之销毁了
		capacity = newCapacity;
	}
public:
	Stack() : data(nullptr), size(0), capacity(0) {}

	Stack(const Stack& other) :data(nullptr), size(other.size), capacity(other.capacity)
	{
		if (capacity > 0)
		{
			data = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				data[i] = other.data[i];// 为什么 这里能访问other的私有属性data?: 所有同类型变量都是friend（友元），friends share secrets
			}
		}
	}
	~Stack()
	{
		// 释放内存
		delete[] data;
		//不要试图访问析构之后的对象！
		//size = 0;
		//capacity = 0;
	}

	void push(const T& value)
	{
		if (size == capacity)
		{
			size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
			resize(newCapacity);
		}
		data[size++] = value;
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
			throw std::out_of_range("Stack is empty");
		}
		return data[size - 1];
	}

	bool empty() const
	{
		return (size == 0);
	}

	size_t getSize() const
	{
		return size;
	}

	class StackIterator
	{
	private:
		T* ptr;
	public:
		StackIterator(T* p) : ptr(p) {}
		T& operator*() { return *ptr; }
		StackIterator& operator++() { ++ptr; return *this; }
		bool operator != (const StackIterator& other) { return ptr != other.ptr; }
		bool operator == (const StackIterator& other) { return ptr == other.ptr; }
	};

	
	StackIterator begin() const
	{
		return StackIterator(data); // 值类型，如果是引用，就会出现悬空引用，因为原来的临时变量已经销毁，而引用任然指向原有的临时变量
	}

	StackIterator end() const
	{
		return StackIterator(data + size);  // 指向数组后一位
	} 

};



#endif
