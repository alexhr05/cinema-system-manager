#include "MyString.h"
#include <cstring>
#include <fstream>
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

    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
}

MyString MyString::operator+(char c) const {
    char* newData = new char[length + 2];

    for (int i = 0; i < length; i++) {
        newData[i] = data[i];
    }

    newData[length] = c;

    newData[length + 1] = '\0';

    MyString result(newData);

    delete[] newData;

    return result;
}


bool getline(istream& is, MyString & str, char delimiter) {
    str = MyString("");

    char ch;
    bool foundDelimiter = false;
    bool readAnyChar = false;

    while (is.get(ch)) {
        readAnyChar = true;

        if (ch == delimiter) {
            foundDelimiter = true;
            break;
        }

        str = str + ch; 
    }

    return readAnyChar || foundDelimiter;
}

MyString& MyString::operator+=(char c) {
    MyString result = this->data + c;

    return result;
}
