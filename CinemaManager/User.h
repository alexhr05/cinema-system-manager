#pragma once
#include "Mystring.h"

class User {
private:
	MyString name;
	MyString password;
	double balance;

public:
	User();
	User(MyString& name,MyString& password,double balance);

	void setName(MyString& name);
	void setPassword(MyString& password);
	void setBalance(double balance);

	MyString getName() const;
	MyString getPassword() const;
	double getBalance() const;
};