#pragma once
#include <iostream>


class MyString {
private:
	char* data;
	size_t length;

public:
	friend std::istream& operator>>(std::istream& in, MyString& str);
	friend std::istream& getline(std::istream& is, MyString& str);

	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	size_t size() const;
	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	MyString operator+(const MyString& other) const;
	const char* c_str() const;

	bool equals(const MyString& other) const;
	MyString fromDouble(double number);
	static MyString fromSizeT(size_t number);

	static MyString fromInt(int number);

	void set(const char* str);
	static void intToCharArray(int number, char* buffer);
};
