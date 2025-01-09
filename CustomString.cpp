#include<iostream>
#include "String.h";
using namespace std;

String::String() {
	length = 0;
	input = NULL;
}
String::String(const char* str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	length = i;
	input = new char[length + 1];
	for (int j = 0; j < length; j++) {
		input[j] = str[j];
	}
	input[length] = '\0';
}
String::String(const String& other) {
	length = other.length;
	input = new char[length + 1];
	int i = 0;
	for (int i = 0; i < length; i++) {
		input[i] = other.input[i];
	}
	input[length] = '\0';

}
String::String(int x) {
	input = new char[x + 1];
	input[0] = '\0';
	length = 0;
}

char* String::getdata() {
	return input;
}

const char String::operator[](int i) const {
	char c = '\0';
	if (i < 0) {
		i = length + i;
	}
	if (i >= 0 && i < length) {
		c = input[i];
	}
	return c;
}
String String::operator+(const String& str) {
	length = length + str.length;
	char* ans = new char[length + 1];
	int i = 0;
	while (input[i] != '\0') {
		ans[i] = input[i];
		i++;
	}
	int j = 0;
	while (str.input[j] != '\0') {
		ans[i++] = str.input[j++];
	}
	delete[] input;
	input = new char[length + 1];
	ans[i] = '\0';
	input = ans;
	return ans;
}


String String::operator+(const char& str) {
	length = length + 1;
	char* ans = new char[length + 1];
	int i = 0;
	while (input[i] != '\0') {
		ans[i] = input[i];
		i++;
	}
	ans[i++] = str;
	ans[i] = '\0';
	delete[] input;
	input = new char[length + 1];
	input = ans;
	return *this;
}

String String::operator+(const char* str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	length = length + i;
	i = 0;
	char* ans = new char[length];
	while (input[i] != '\0') {
		ans[i] = input[i];
		i++;
	}
	int j = 0;
	while (str[j] != '\0') {
		ans[i++] = str[j++];
	}
	delete[] input;

	ans[i] = '\0';
	input = new char[length + 1];
	input = ans;
	return *this;
}

String String::operator-(const String& str) {
	int len = str.length;
	int i = 0;
	int j = 0;
	bool check;
	char* ans = new char[length];

	while (input[i] != '\0') {
		check = true;
		for (int k = 0; k < len; k++) {
			if (input[i + k] != str[k]) {
				check = false;
				break;
			}
		}
		if (check) {
			i += len;
		}
		else {
			ans[j++] = input[i++];
		}
	}
	ans[j] = '\0';
	delete[] input;
	input = new char[length + 1];
	input = ans;
	length = j;
	return *this;
}

String String::operator-(const char& str) {
	int i = 0;
	int j = 0;
	while (input[i] != '\0') {
		if (input[i] != str) {
			input[j++] = input[i];
		}
		i++;
	}
	input[j] = '\0';
	j = 0;
	while (input[j] != '\0')
		j++;
	length = length + 1;
	return *this;
}

String String::operator-(const char* str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	int i = 0;
	int j = 0;
	bool check;
	char* ans = new char[length];

	while (input[i] != '\0') {
		check = true;
		for (int k = 0; k < len; k++) {
			if (input[i + k] != str[k]) {
				check = false;
				break;
			}
		}
		if (check) {
			i += len;
		}
		else {
			ans[j++] = input[i++];
		}
	}
	ans[j] = '\0';
	delete[] input;
	input = new char[length + 1];
	input = ans;
	length = j;
	return *this;
}
String& String::operator=(const String& str) {
	delete[] input;
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	length = str.length;
	len = 0;
	input = new char[length];
	int i;
	for (i = 0; i < length; i++) {
		input[i] = str[i];
	}
	input[i] = '\0';
	return *this;
}
String& String::operator=(char* str) {
	delete[] input;
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	length = len;
	input = new char[length + 1];
	for (int i = 0; i < length; i++) {
		input[i] = str[i];
	}
	input[length] = '\0';
	return *this;
}


bool String::operator==(const String& other) const {
	if (length != other.length) {
		return false;
	}
	else {
		for (int i = 0; i < length; i++) {
			if (other.input[i] != input[i]) {
				return false;
			}
		}
		return true;
	}
}
bool String::operator==(const char* other) const {
	int j = 0;
	while (other[j] != '\0') {
		j++;
	}
	if (j != length) {
		return false;
	}
	else {
		for (int i = 0; i < length; i++) {
			if (other[i] != input[i]) {
				return false;
			}
		}
		return true;
	}
}

bool String::operator!() {
	bool A = false;
	if (length == 0) {
		A = true;
	}
	return A;
}


int String::operator()(char a) const {
	for (int i = 0; i < length + 1; i++) {
		if (input[i] == a) {
			return i;
			break;
		}
	}
	return -1;
}
int String::operator()(const String& str) const {
	int i = 0;
	bool check;
	int j = 0;
	int k = 0;
	int len = str.length;
	while (input[i] != '\0') {
		if (input[i] == str[0]) {
			check = true;
			k = i;
			for (j = 0; j < len; j++) {
				if (input[k] != str[j]) {
					check = false;
					break;
				}
				k++;
			}
			if (check) {
				return i;
			}
			else {

			}
		}
		i++;
	}
	return -1;
}
int String::operator()(const char* str) const {
	int i = 0;
	bool check;
	int j = 0;
	int k = 0;
	int len = 0;
	while (str[i++] != '\0') {
		len++;
	}
	i = 0;
	while (input[i] != '\0') {
		if (input[i] == str[0]) {
			check = true;
			k = i;
			for (j = 0; j < len; j++) {
				if (input[k] != str[j]) {
					check = false;
					break;
				}
				k++;
			}
			if (check) {
				return i;
			}
			else {

			}
		}
		i++;
	}
	return -1;
}
String::operator int() const {
	return length;
}
String::~String() {
	length = 0;
	delete[] input;
	input = nullptr;
}

ostream& operator << (ostream& output, const String& str) {
	if (str.input != nullptr)
		output << str.input;
	return output;
}

istream& operator >> (istream& input, String& str) {
	char temp[100000];
	input >> temp;
	str = temp;
	return input;
}