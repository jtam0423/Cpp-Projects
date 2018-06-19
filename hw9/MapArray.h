#ifndef MAPARRAY_H
#define MAPARRAY_H
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
using namespace std;

template
	< typename Key, typename T >
class MapArray
{
	int sz;
	pair<Key, T>* buf;
public:
	struct iterator
	{
		typedef std::random_access_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<Key, T> value_type;
		typedef value_type& reference;
		typedef value_type* pointer;
	private:
		pointer ibuf;
	public:
		iterator(pointer ptr) : ibuf(ptr) { }
		self_type operator++() { ++ibuf; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; ibuf++; return cpy; }
		self_type operator--() { --ibuf; return *this; }
		self_type operator--(int postfix) { self_type cpy = *this; ibuf--; return cpy; }
		reference operator*() { return *ibuf; }
		pointer operator->() { return ibuf; }
		bool operator==(const self_type& rhs) const { return ibuf == rhs.ibuf; }
		bool operator!=(const self_type& rhs) const { return ibuf != rhs.ibuf; }
	};
	struct const_iterator
	{
		typedef std::random_access_iterator_tag iterator_category;
		typedef const_iterator self_type;
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<Key, T> value_type;
		typedef value_type& reference;
		typedef value_type* pointer;
	private:
		pointer buf;
	public:
		const_iterator(pointer ptr) : buf(ptr) { }
		self_type operator++() { ++buf; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; buf++; return cpy; }
		const reference operator*() { return *buf; }
		const pointer operator->() { return buf; }
		bool operator==(const self_type& rhs) const { return buf == rhs.buf; }
		bool operator!=(const self_type& rhs) const { return buf != rhs.buf; }
	};

	MapArray() : sz(0),  buf( new pair< Key, T >[sz] ) { }

	MapArray(initializer_list < pair<Key, T> > s) : sz(s.size()), buf(new pair<Key, T>[sz]) {
		uninitialized_copy(s.begin(), s.end(), buf);
	}

	int size() { return sz; }

	T& insert(pair<Key, T> s) {
		pair<Key, T> * temp = new pair<Key, T>[++sz];
		int end = sz - 1;

		for (int i = 0; i < end; i++) {

			if (s.first < buf[i].first) {
				end = i;
			}
			else {
				temp[i].first = buf[i].first;
				temp[i].second = buf[i].second;
			}
		}

		temp[end].first = s.first;
		temp[end].second = s.second;

		for (int i = end + 1; i < sz; i++) {
			temp[i].first = buf[i - 1].first;
			temp[i].second = buf[i - 1].second;
		}

		delete[] buf;
		buf = temp;
		return buf[end].second;
	}

	T& operator[](const Key& key) {

		for (int i = 0; i < sz; i++) {

			if (buf[i].first == key) {
				return buf[i].second;
			}
		}
		return insert(make_pair(key, T()));
	}
	iterator begin() { return iterator(buf); }

	iterator end() { return iterator(buf + sz); }

	const_iterator begin() const { return const_iterator(buf); }

	const_iterator end() const { return const_iterator(buf + sz); }

	~MapArray() { delete[] buf; }
};
#endif //MAPARRAY_H