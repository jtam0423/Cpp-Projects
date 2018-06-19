#include "String.h"
#include <iostream>
using namespace std;

String::String(const char * s)
{
	buf = strdup(s);
}

String::String(const String & s)
{
	buf = strdup(s.buf);
}

String String::operator = (const String & s)
{
	delete_char_array(buf);
	buf = strdup(s.buf);
	return *this;
}

char & String::operator [] (int index)
{
	if (!inBounds(index))
	{
		cout << "Error: Out of Bounds: " << index << endl;
	}
	else
	{
		return buf[index];
	}
}

int String::size()
{
	return strlen(buf);
}

String String::reverse()
{
	int count = 0;
	char arr[strlen(buf)];
	for (int i = strlen(buf)-1; i >= 0; i--)
	{
		arr[count] = buf[i];
		count++;
	}
	arr[count] = '\0';
	return String(arr);
}

int String::indexOf(const char c)
{
	for (int i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int String::indexOf(const String pattern)
{
	int index;
	int x = 0;
	for (int i = 0; buf[i] != '\0'; i++)
	{
		index = i;
		while (buf[i] == pattern.buf[x])
		{
			return index;
		}
	}
	return -1;
}

bool String::operator == (const String s)
{
	return strcmp(buf, s.buf) == 0;
}

bool String::operator != (const String s)
{
	if (strcmp(buf, s.buf) == 0)
	{
		return false;
	}
	return true;
}

bool String::operator > (const String s)
{
	return strcmp(buf, s.buf) == 1;
}

bool String::operator < (const String s)
{
	return strcmp(buf, s.buf) == -1;
}

bool String::operator <= (const String s)
{
	return strcmp(buf, s.buf) == -1;
}

bool String::operator >= (const String s)
{
	return strcmp(buf, s.buf) == 1;
}

/// concatenates this and s to return result
String String::operator + (const String s)
{
	char result[strlen(buf) + strlen(s.buf) + 1];
	strcpy(result, buf);
	return strcat(result, s.buf);
}

/// concatenates s onto end of this
String String::operator += (const String s)
{
	*this = *this + s;
	return *this;
}

void String::print(ostream & out)
{
	out << buf;
}

void String::read(istream & in)
{
	char *new_buf = new_char_array(1000);
	in.getline(new_buf, 1000);
	buf = strdup(new_buf);
}

void String::final_report_on_allocations()
{
	if (allocations > 0) 
		error("Memory Leak in class String");
	if (allocations < 0) 
		error("Too many delete[]s in class String");
	if (allocations == 0)
		cout << "Allocations & deallocations match\n" << endl;
}

String::~String()
{
	delete_char_array(buf);
}
//Private Functions

int String::allocations = 0;

char * String::new_char_array(int n_bytes)
{
	++allocations;
	return new char[n_bytes];
}

void String::delete_char_array(char *p)
{
	--allocations;
	if (allocations < 0) error("more delete[] than new[]");
	delete[] p;
}

void String::error(const char *p)
{
	--allocations;
	if (allocations < 0) error("more delete[] than new[]");
	delete[] p;
}

bool String::inBounds(int i)
{
	return i >= 0 && i < strlen(buf);
}

int String::strlen(const char *src)
{
	int count = 0;
	for (int i = 0; src[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}

char * String::strdup(const char *src)
{
	char *buf = new_char_array(strlen(src) + 1);
	return strcpy(buf, src);
}

char * String::strcpy(char *dest, const char *src)
{
	int copy;
	for (copy = 0; src[copy] != '\0'; copy++)
	{
		dest[copy] = src[copy];
	}
	dest[copy] = '\0';
	return dest;
}

char * String::strcat(char *dest, const char *src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}

int String::strcmp(const char *left, const char *right)
{
	for (int i = 0; left[i] != '\0'; i++)
	{
		if (right[i] == '\0')
			return 1;
		if (left[i] > right[i])
			return 1;
		if (right[i] > left[i])
			return -1;
	}
	return 0;
}

ostream & operator << (ostream & out, String str)
{
	str.print(out);
	return out;
}

istream & operator >> (istream & in, String & str)
{
	str.read(in);
	return in;
}
