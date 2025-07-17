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
		data = newData; // ��ʱ������resize������Ҳ��֮������
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
				data[i] = other.data[i];// Ϊʲô �����ܷ���other��˽������data?: ����ͬ���ͱ�������friend����Ԫ����friends share secrets
			}
		}
	}
	~Stack()
	{
		// �ͷ��ڴ�
		delete[] data;
		//��Ҫ��ͼ��������֮��Ķ���
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
		return StackIterator(data); // ֵ���ͣ���������ã��ͻ�����������ã���Ϊԭ������ʱ�����Ѿ����٣���������Ȼָ��ԭ�е���ʱ����
	}

	StackIterator end() const
	{
		return StackIterator(data + size);  // ָ�������һλ
	} 

};



#endif
