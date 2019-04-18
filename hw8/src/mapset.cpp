#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main(){
	ifstream in_stop("stopwords.txt");
	set<string> S;
	copy(istream_iterator<string>(in_stop),
		istream_iterator<string>(),
		inserter(S, end(S))
	);

	cout << ">>>>>>>> Start printing set of stopwords >>>>>>>> " << endl;
	for(auto E_s : S){
		cout << E_s << endl;
	}

	ifstream in_sample("sample_doc.txt");
	ofstream out("frequency.txt");
	map<string, int> M;
	for_each(istream_iterator<string>(in_sample),
			istream_iterator<string>(),
			[&](string s){
		string s_new(s);
		transform(s.begin(), s.end(), s_new.begin(), ::tolower);
		auto stopword = S.find(s_new);
		if(stopword == S.end()){
			M[s]++;}
	}
	);

	cout << "->Start printing map of word count: " << endl;
	for(auto E_m : M){
		cout << E_m.first << ":" << E_m.second << endl;
		out << E_m.first << ":" << E_m.second << endl;
	}
	out.close();
	return 0;
}
