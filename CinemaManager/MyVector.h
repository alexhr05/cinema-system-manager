#pragma once

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
    T& operator[](size_t index);
    T& front();
    T& back();
    bool empty() const;
    size_t getSize() const;
    size_t getCapacity() const;
    void clear();
    int find(const T& element) const;

    void print() const;
};