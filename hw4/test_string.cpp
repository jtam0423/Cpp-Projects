#include "String.h"
#include <iostream>
using namespace std;

void test_constructor_and_print()
{
	cout << "TEST: Constructor and Print" << endl;
	String s1("Test 1");
	cout << s1 << " --> 'Test 1'" << endl;
}

void test_assign()
{
	cout << "TEST: =" << endl;
	String s1("First");
	String s2("Second");
	s1 = s2;
	cout << s1 << " --> 'Second'" << endl;
}

void test_index()
{
	cout << "TEST: []" << endl;
	String s1("String");
	cout << "Index 0 of s1 is " << s1[0] << " --> 'S'" << endl;
	cout << "Index 1 of s1 is " << s1[1] << " --> 't'" << endl;
	cout << "Index 2 of s1 is " << s1[2] << " --> 'r'" << endl;
}

void test_size()
{
	cout << "TEST: size()" << endl;
	String s1("Size");
	cout << "s1 is : " << s1 << endl;
	cout << "Size: " << s1.size() << " --> 4" << endl;
}

void test_reverse()
{
	cout << "TEST: reverse()" << endl;
	String s1("Hello World");
	cout << "Reverse of : " << s1 << endl;
	cout << s1.reverse() << " --> 'dlroW olleH'" << endl;
}

void test_indexOf_char()
{
	cout << "TEST: indexOf(const char c)" << endl;
	String s1("String");
	cout << s1 << " is s1 so answer is " << s1.indexOf("n") << " --> 4" << endl;
}

void test_indexOf_str()
{
	cout << "TEST: indexOf(const String pattern)" << endl;
	String s1("Index");
	cout << s1 << " is s1 so answer is " << s1.indexOf("dex") << " --> 2" << endl;
}

void test_eq()
{
	cout << "TEST: ==" << endl;
	String s1("equal");
	String s2("equal");
	bool eq(s1 == s2);
	cout << eq << " --> 1" << endl;
}

void test_not_eq()
{
	cout << "TEST: !=" << endl;
	String s1("Hello");
	String s2("Hello");
	cout << (s1 != s2) << " --> 0" << endl;
}

void test_gt()
{
	cout << "TEST: >" << endl;
	String s1("a");
	String s2("A");
	cout << (s1 > s2) << " --> 1" << endl;
}
void test_lt()
{
	cout << "TEST: <" << endl;
	String s1("A");
	String s2("A");
	cout << (s1 < s2) << " --> 0" << endl;
}

void test_le()
{
	cout << "TEST: <=" << endl;
	String s1("test");
	String s2("test");
	cout << (s1 <= s2) << " --> 0" << endl;
	String s3("test");
	String s4("TEST");
	cout << (s3 <= s4) << " --> 0" << endl;
}

void test_ge()
{
	cout << "TEST: >=" << endl;
	String s1("test");
	String s2("test");
	cout << (s1 >= s2) << " --> 0" << endl;
	String s3("TEST");
	String s4("test");
	cout << (s3 >= s4) << " --> 0" << endl;
}

void test_add()
{
	cout << "TEST: +" << endl;
	String s1("Hello");
	String s2(" World");
	cout << s1 + s2 << " --> 'Hello World'" << endl;
}


void test_add_eq()
{
	cout << "TEST: +=" << endl;
	String s1(" World");
	String s2("Hello");
	s2 += s1;
	cout << s2 << " --> 'Hello World'" << endl;
}

int main()
{
	test_constructor_and_print();
	cout << "" << endl;
	test_assign();
	cout << "" << endl;
	test_index();
	cout << "" << endl;
	test_size();
	cout << "" << endl;
	test_reverse();
	cout << "" << endl;
	test_indexOf_char();
	cout << "" << endl;
	test_indexOf_str();
	cout << "" << endl;
	test_eq();
	cout << "" << endl;
	test_not_eq();
	cout << "" << endl;
	test_gt();
	cout << "" << endl;
	test_lt();
	cout << "" << endl;
	test_le();
	cout << "" << endl;
	test_ge();
	cout << "" << endl;
	test_add();
	cout << "" << endl;
	test_add_eq();
	cout << "" << endl;
	String::final_report_on_allocations();
	return 0;
}
