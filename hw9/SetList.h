#ifndef SETLIST_H
#define SETLIST_H
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
using namespace std;

template
	<typename T>
class SetList
{
private:
	struct ListNode
	{
		T info;
		ListNode * next;
		ListNode(T newInfo, ListNode * newNext)
			: info(newInfo), next(newNext)
		{
		}
	};
	ListNode * head;
	static ListNode * copy(ListNode * L)
	{
		return L == nullptr ? nullptr : new ListNode(L->info, copy(L->next));
	}
	static ListNode * append(ListNode * L1, ListNode * L2)
	{
		return L1 == nullptr ? copy(L2) : new ListNode(L1->info, append(L1->next, L2));
	}
	static int length(ListNode * L)
	{
		return L == nullptr ? 0 : 1 + length(L->next);
	}
public:
	struct iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef ptrdiff_t difference_type;
	private:
		ListNode * ibuf;
	public:
		iterator(ListNode * ptr) : ibuf(ptr) {}
		self_type operator++ () { ibuf = ibuf->next; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; ibuf = ibuf->next; return cpy; }
		reference operator*() { return ibuf->info; }
		pointer operator->() { return ibuf; }
		bool operator == (const self_type& rhs) const { return ibuf == rhs.ibuf; }
		bool operator != (const self_type& rhs) const { return ibuf != rhs.ibuf; }
	};

	struct const_iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef ptrdiff_t difference_type;
	private:
		ListNode * buf;
	public:
		const_iterator(ListNode * ptr) : buf(ptr) { }
		self_type operator++() { buf=buf->next; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; buf = buf->next; return cpy; }
		const reference operator*() { return buf->info; }
		const pointer operator->() { return buf; }
		bool operator == (const self_type& rhs) const { return buf == rhs.buf; }
		bool operator != (const self_type& rhs) const { return buf != rhs.buf; }
	};

	SetList() : head (nullptr) { }
	iterator insert(const T & e) { head = new ListNode(e, head); }
	iterator find(const T & e)
	{
		for (ListNode * p = head; p != nullptr; p = p->next)
		{
			if (p->info == e)
				return iterator(p);
		}
		return nullptr;
	}
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
	const_iterator begin() const { return const_iterator(head); }
	const_iterator end() const { return const_iterator(nullptr); }
	~SetList()
	{
		ListNode * temp;
		for (ListNode * p = head; p != nullptr; )
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
};
#endif //SETLIST_H