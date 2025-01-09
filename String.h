#pragma once
#include <iostream>
using namespace std;
class String {
	int length;
	char* input;
public:

	String();
	String(const char* str);
	String(const String&);
	String(int x);
	char* getdata();
	const char operator[](int i) const;
	String operator+(const String& str);
	String operator+(const char& str);
	String operator+(const char* str);
	String operator-(const String& substr);
	String operator-(const char& str);
	String operator-(const char* str);
	String& operator=(const String&);
	String& operator=(char*);
	bool operator==(const String&) const;
	bool operator==(const char*) const;
	bool operator!();
	int operator()(char) const;
	int operator()(const String&) const;
	int operator()(const char*) const;
	operator int() const;
	~String();
	friend ostream& operator<<(ostream& output, const String& str);
	friend istream& operator>>(istream& input, String& str);
};
