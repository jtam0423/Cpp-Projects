#include <iostream>
using namespace std;

class String
{
public:
	/// Both constructors should construct
	/// this String from the parameter s
	explicit String(const char * s = "");
	String(const String & s);
	String operator = (const String & s);
	char & operator [] (const int index);
	int size() const;
	int indexOf(char c) const;
	bool operator == (const String & s) const;
	bool operator < (const String & s) const;
	/// concatenates this and s
	String operator + (const String & s) const;
	/// concatenates s onto end of this
	String operator += (const String & s);
	String reverse() const; // does not modify this String
	void print(ostream & out) const;
	void read(istream & in);
	~String();
private:
	bool inBounds(int i)
	{
		return i >= 0 && i < size();
	}
	struct ListNode
	{
		char info;
		ListNode * next;
		ListNode(char newInfo, ListNode * newNext)
			: info(newInfo), next(newNext)
		{
		}// Below: primitives you *must* write and use (try recursion)
		static ListNode * stringToList(const char *s);
		static ListNode * copy(ListNode * L);
		static ListNode * reverse(ListNode * L, ListNode * R = 0);
		static ListNode * append(ListNode * L1, ListNode * L2);
		static int compare(ListNode * L1, ListNode * L2);//like strcmp
		static void deleteList(ListNode * L);
		static int length(ListNode * L); // O(N) so call rarely
	};
	ListNode * head; // no other data members!! - especially no len!
};
ostream & operator << (ostream & out, String str);
istream & operator >> (istream & in, String & str);