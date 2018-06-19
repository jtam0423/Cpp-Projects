#include <iostream>
using namespace std;

class String
{
public:
	/// Both constructors should construct
	/// this String from the parameter s
	String(const char * s = "");
	String(const String & s);
	String operator = (const String & s);
	char & operator [] (int index);
	int size();
	String reverse(); // does not modify this String
	int indexOf(const char c);
	int indexOf(const String pattern);
	bool operator == (const String s);
	bool operator != (const String s);
	bool operator > (const String s);
	bool operator < (const String s);
	bool operator <= (const String s);
	bool operator >= (const String s);
	/// concatenates this and s to return result
	String operator + (const String s);
	/// concatenates s onto end of this
	String operator += (const String s);
	void print(ostream & out);
	void read(istream & in);
	static void final_report_on_allocations();
	~String();
private:
	static int allocations;
	static char * new_char_array(int n_bytes);
	static void delete_char_array(char * p);
	static void error(const char * p);
	bool inBounds(int i);
	static int strlen(const char *src);
	static char * strdup(const char *src); // notice this new function
										  // … and any other auxilliary static methods you need
	static char * strcpy(char *dest, const char *src);
	static char * strcat(char *dest, const char *src);
	static int strcmp(const char *left, const char *right);
	char * buf; // base of array for the characters in this string
				// DO NOT add a length data member!! use the null terminator
};
ostream & operator << (ostream & out, String str);
istream & operator >> (istream & in, String & str);
