#include <iostream>
#include "String.h"
using namespace std;

String::String(const char * s)
{
	head = ListNode::stringToList(s);
}

String::String(const String & s)
{
	head = ListNode::copy(s.head);
}

String String::operator = (const String & s)
{
	head = ListNode::copy(s.head);
	return *this;
}

char & String::operator [] (const int index)
{
	if (!String::inBounds(index))
	{
		cout << "Error: Index out of Bounds!" << endl;
		static char x = '\0';
		return x;
	}
	else
	{
		ListNode * ptr = head;
		for (int i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}
		return ptr->info;
	}
}

int String::size() const
{
	return ListNode::length(head);
}

int String::indexOf(char c) const
{
	ListNode * p = head;
	for (int i = 0; p != nullptr; i++)
	{
		if (p->info == c)
		{
			return i;
		}
		p = p->next;
	}
	return -1;
}

bool String::operator == (const String & s) const
{
	return ListNode::compare(head, s.head) == 0;
}

bool String::operator < (const String & s) const
{
	return ListNode::compare(head, s.head) < 0;
}

/// concatenates this and s
String String::operator + (const String & s) const
{
	String ptr;
	ptr.head = ListNode::append(head, s.head);
	return ptr;
}

/// concatenates s onto end of this
String String::operator += (const String & s)
{
	head = ListNode::append(head, s.head);
	return *this;
}

String String::reverse() const // does not modify this String
{
	String rev;
	ListNode::reverse(head, rev.head);
	return rev;
}

void String::print(ostream & out) const
{
	for (ListNode * p = head; p != nullptr; p = p->next)
	{
		out << p->info;
	}
}

void String::read(istream & in)
{
	/*char *new_head = new char[1000];
	in.getline(new_head, 1000);
	head = ListNode::stringToList(new_head);*/
	char buf[1024];
	in.getline(buf, 1024);
	ListNode::deleteList(head);
	head = ListNode::stringToList(buf);
}

String::~String()
{
	ListNode::deleteList(head);
}

//****************PRIVATE******************//

String::ListNode * String::ListNode::stringToList(const char *s)
{
	return *s == '\0' ? NULL : new ListNode(*s, stringToList(s + 1));
}

String::ListNode * String::ListNode::copy(ListNode * L)
{
	return L == nullptr ? nullptr : new ListNode(L->info, copy(L->next));
}

String::ListNode * String::ListNode::reverse(ListNode * L, ListNode * R)
{
	return !L ? R : reverse(L->next, new ListNode(L->info, R));
}

String::ListNode * String::ListNode::append(ListNode * L1, ListNode * L2)
{
	return L1 == nullptr ? copy(L2) : new ListNode(L1->info, append(L1->next, L2));
}

int String::ListNode::compare(ListNode * L1, ListNode * L2)//like strcmp
{
	if (L1 == nullptr & L2 != nullptr)
	{
		return 0 - L2->info;
	}
	else if (L2 == nullptr & L1 != nullptr)
	{
		return L1->info - 0;
	}
	else if (L1 == nullptr && L2 == nullptr)
	{
		return 0;
	}
	else if (L1->info == L2->info)
	{
		return compare(L1->next, L2->next);
	}
	else
	{
		return L1->info - L2->info;
	}
}

void String::ListNode::deleteList(ListNode * L)
{
	if (L != '\0')
	{
		deleteList(L->next);
		delete L;
	}
}

int String::ListNode::length(ListNode * L) // O(N) so call rarely
{
	return L == nullptr ? 0 : 1 + length(L->next);
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