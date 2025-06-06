#include "MyString.h"
#include <iostream>
#include <cstring>
#include <cmath>  

using namespace std;
const int BUFFER_SIZE = 1024;

MyString::MyString() : length(0) {
    this->data = new char[1];
    this->data[0] = '\0';
}

MyString::MyString(const char* str) {
    this->length = strlen(str);
    this->data = new char[length + 1];
    strcpy_s(data, length + 1, str);
}

MyString::MyString(const MyString& other) {
    this->length = other.length;
    this->data = new char[length + 1];
    strcpy_s(this->data, length + 1, other.data);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] this->data;
        this->length = other.length;
        this->data = new char[length + 1];
        strcpy_s(this->data, length + 1, other.data);
    }
    return *this;
}


MyString::~MyString() {
    delete[] this->data;
}

size_t MyString::size() const {
    return this->length;
}

char& MyString::operator[](size_t index) {
    return this->data[index];
}

const char& MyString::operator[](size_t index) const {
    return this->data[index];
}

MyString MyString::operator+(const MyString& other) const {
    MyString result;
    delete[] result.data;
    result.length = length + other.length;
    result.data = new char[result.length + 1];

    strcpy_s(result.data, this->length + 1, this->data);
    strcat_s(result.data, result.length + 1, other.data);

    return result;
}

const char* MyString::c_str() const {
    return this->data;
}

bool MyString::equals(const MyString& other) const {
    if (length != other.length) {
        return false;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (data[i] != other.data[i]) {
            return false;

        }
    }
    return true;
}
std::istream& operator>>(std::istream& is, MyString& str) {
    char buffer[BUFFER_SIZE];
    is >> buffer;
    str = buffer;
    return is;
}

MyString MyString::fromSizeT(size_t number) {
    if (number == 0) return MyString("0");

    char buffer[101];
    size_t index = 100;
    buffer[index] = '\0';

    while (number > 0) {
        buffer[--index] = '0' + (number % 10);
        number /= 10;
    }

    return MyString(buffer + index);
}

MyString MyString::fromInt(int number) {
    if (number == 0) return MyString("0");

    char buffer[101];
    int index = 100;
    buffer[index] = '\0';

    while (number > 0) {
        buffer[--index] = '0' + (number % 10);
        number /= 10;
    }

    return MyString(buffer + index);
}

void MyString::set(const char* str) {
    delete[] data;
    length = strlen(str);
    data = new char[length + 1];
    strcpy_s(data,length+1, str);
}

std::istream& getline(std::istream& is, MyString& str) {
    char buffer[BUFFER_SIZE];
    is.getline(buffer, BUFFER_SIZE);
    str.set(buffer); 
    return is;
}

void MyString::intToCharArray(int number, char* buffer) {
    bool isNegative = false;
    int i = 0;

    if (number == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return;
    }

    if (number < 0) {
        isNegative = true;
        number = -number;
    }

    while (number > 0) {
        buffer[i++] = (number % 10) + '0';
        number /= 10;
    }

    if (isNegative) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0';

    // Обръщане на символите
    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
}



//void MyString::readFromStream(std::istream& in) {
//    char buffer[1024];
//    in.getline(buffer, 1024);
//    *this = buffer;
//}