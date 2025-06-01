#include "User.h"
#include "Mystring.h"


User::User() : name(""), password(""), balance(0) {}

User::User(MyString& name, MyString& password, double balance) : name(name), password(password), balance(balance) {

}

void User::setName(MyString& name) {
	this->name = name;
}

void User::setPassword(MyString& password) {
	this->password = password;
}

void User::setBalance(double balance) {
	this->balance = balance;
}

MyString User::getName() const {
	return name;
}

MyString User::getPassword() const {
	return password;
}

double User::getBalance() const {
	return balance;
}

int User::id = 0;

int User::getId() const {
	return id;
}