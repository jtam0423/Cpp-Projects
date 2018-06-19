#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
	vector<int> V;
	ifstream in("rand_numbers.txt");
	ofstream odd("odd.txt");
	ofstream even("even.txt");
	copy(istream_iterator<int>(in),
		istream_iterator<int>(),
		back_inserter(V));
	sort(begin(V), end(V));
	for_each(begin(V), end(V), [&](int i) {
		if (i % 2 != 0)
			odd << i << " ";
		else if (i % 2 == 0)
			even << i << "\r\n";
	});
	return 0;
}