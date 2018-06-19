#include "String.h"
#include <iostream>

String::String (const char * s)
{
	strcpy(buf, s);
}	

String::String (const String & s)
{
	strcpy(buf, s.buf);
}

String String::operator = (const String & s)
{
	strcpy(buf, s.buf);
}

char & String::operator [](int index)
{
	if (!inBounds(index)) 
	{
		cout << "Error: Out of Bounds " << index << endl;
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
	char max[MAXLEN];
	for (int i = strlen(buf) - 1; i >= 0; i--)
	{
		max[count] = buf[i];
		count++;
	}
	max[count] = '\0';
	return String(max);
}

int String::indexOf(const char c)
{
	for ( int i = 0; buf[i] != '\0'; i++)
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
	for ( int i = 0; buf[i] != '\0'; i++)
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

String String::operator + (const String s)
{
	return strcat(buf, s.buf);
}

String String::operator += (const String s)
{
	return strcat(buf, s.buf);
}

void String::print(ostream & out)
{
	out << buf;
}

void String::read(istream & in)
{
	in >> buf;
}

String::~String()
{
	//str
}

bool String::inBounds(int i)
{
	return i >= 0 && i < strlen(buf);
}

int String::strlen(const char * s)
{
	int count = 0;
	for ( int i = 0; s[i] != '\0' && i < MAXLEN - 1; i++)
	{
		count += 1;
	}
	return count;
}

char * String::strcpy(char *dest, const char *src)
{
	int i;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

char * String::strcat( char *dest, const char *src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}

int String::strcmp( const char *left, const char *right)
{
	for ( int i = 0; left[i] != '\0'; i++)
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

int String::strncmp( const char *left, const char *right, int n )
{	
	for ( int i = 0; left[i] != '\0' && i <= n; i++)
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
const char * String::strchr( const char *str, int c)
{
	for ( int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
		{
			return str + i;
		}
	}
	return 0;
}

char * String::strstr( const char *haystack, const char *needle)
{
	for (int i = 0; i < strlen(haystack); i++)
	{
		if (haystack[i] == needle[0])
		{
			int x;
			int n = 0;
			for (x = i; n <= strlen(needle); n++, x++)
			{
				if (haystack[x] != needle[n])
					break;
			}
			if (haystack[x] == needle[n])
			{
				const char *ptr;
				ptr = &haystack[x];
				return (char*)ptr;
			}
		}
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
