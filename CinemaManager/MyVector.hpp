#pragma once

#include <iostream>

using namespace std;

template<typename T>
class MyVector {
private:
	T* data;
	size_t capacity;
	size_t size;
public:
	MyVector();
	MyVector(size_t initialCapacity);

	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	~MyVector();

	void add(const T& element);
	void removeAt(int index);
	void remove(const T& element);
	T& operator[](size_t index);
	bool empty() const;
	size_t getSize() const;
	size_t getCapacity() const;
	void clear();
	int find(const T& element) const;

	void resize();
	void print() const;
};

template <typename T>
MyVector<T>::MyVector() : data(new T[4]), capacity(4), size(0) {}

template <typename T>
MyVector<T>::MyVector(size_t initialCapacity) : capacity(initialCapacity), size(0) {
	data = new T[capacity];
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) : capacity(other.capacity), size(other.size) {
	data = new T[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
	if (this != &other) {
		delete[] data;

		capacity = other.capacity;
		size = other.size;
		data = new T[capacity];
		for (size_t i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}


template <typename T>
MyVector<T>::~MyVector() {
	delete[] data;
}

template <typename T>
void MyVector<T>::add(const T& element) {
	if (size >= capacity) {
		resize();
	}
	data[size++] = element;
}
template <typename T>
void MyVector<T>::removeAt(int index) {
	if (index < 0 || index >= size) {
		cerr << "Invalid index in removeAt: " << index << std::endl;
		return;
	}

	for (size_t i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

template<typename T>
void MyVector<T>::remove(const T& element)
{
	for (size_t i = 0; i < size; i++)
	{
		if(data[i] == element) {
			removeAt(i);
		}
	}
}

template <typename T>
void MyVector<T>::resize() {
	size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
	T* newData = new T[newCapacity];

	for (size_t i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCapacity;
}

template <typename T>
T& MyVector<T>::operator[](size_t index) {
	return data[index];
}

template <typename T>
bool MyVector<T>::empty() const {
	return size == 0;
}

template <typename T>
size_t MyVector<T>::getSize() const {
	return size;
}

template <typename T>
size_t MyVector<T>::getCapacity() const {
	return capacity;
}

template <typename T>
void MyVector<T>::clear() {
	size = 0;
}

template <typename T>
int MyVector<T>::find(const T& element) const {
	for (size_t i = 0; i < size; i++) {
		if (data[i] == element) {
			return static_cast<int>(i);
		}
	}
	return -1;
}

template <typename T>
void MyVector<T>::print() const {
	cout << "Vector contents: ";
	for (size_t i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	cout << "Size: " << size << ", Capacity: " << capacity << endl;

}