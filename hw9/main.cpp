#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include "SetList.h"
#include "MapArray.h"
using namespace std;

int main()
{
	SetList <string> S;
	MapArray <string, int> M;

	ifstream in("sample_doc.txt");
	ifstream in2("stopwords.txt");
	ofstream out("frequency.txt");

	for_each(istream_iterator<string>(in), 
		istream_iterator<string>(),
		[&](string s) {
			std::transform(begin(s), end(s), begin(s), ::tolower);
			if (S.find(s) == S.end()) {
				M[s]++;
			}
	});

	for_each(istream_iterator<string>(in2), istream_iterator<string>(), [&](string s) {
			S.insert(s);
	});
	
	
	for_each(begin(M), end(M), [&](pair<string, int> p) {
		out << p.first << " : " << p.second << endl;
	});
	return 0;
}