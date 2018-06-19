#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	vector<string> V;
	set<string> S;
	map<string, int> M;
	ifstream in("sample_doc.txt");
	ifstream in2("stopwords.txt");
	ofstream out("frequency.txt");
	copy(istream_iterator<string>(in),
		istream_iterator<string>(),
		back_inserter(V));
	copy(istream_iterator<string>(in2),
		istream_iterator<string>(),
		inserter(S, begin(S)));
	for_each(begin(V), end(V), [&](string & s){
		std::transform(begin(s), end(s), begin(s), ::tolower);
	});
	for_each(begin(V), end(V), [&](string s) {
		M[s]++;
	});
	for_each(begin(M), end(M), [&](pair<string, int> p) {
		out << p.first << " : " << p.second << endl;
	});
	return 0;
}