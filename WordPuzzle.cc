//91.53 First submission : ACC
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <string>


using namespace std;

// }}}

class WordPuzzle
{
public:
	int steps[54];
	int next[54];
	int word_diff(string s1, string s2){
		int cnt = 0;
		for(int i = 0; i < s1.size(); ++i){
			if(s1[i] != s2[i]) ++cnt;
		}
		return cnt;
	}
	bool is_anagram(string s1, string s2){
		int a1[26];
		int a2[26];
		memset(a1, 0, 26*sizeof(int));
		memset(a2, 0, 26*sizeof(int));
		for(int i = 0; i < s1.size(); ++i){
			a1[s1[i]-'a']++;
			a2[s2[i]-'a']++;
		}
		for(int i = 0; i < 26; ++i){
			if(a1[i] != a2[i]) return false;
		}
		return true;	
	}
	/*
	int first_diff(string s1, string s2){
		for(int i = 0; i < s1.size(); ++i){
			if(s1[i] != s2[i]) return i;
		}
		return -1;
	}
	int last_diff(string s1, string s2){
		for(int i = s1.size()-1; i >= 0; --i){
			if(s1[i] != s2[i]) return i;
		}
		return -1;
	}
	*/

	pair<int,int> convert(vector <string> dictionary, int src, string target){
		string source = dictionary[src];
		if(steps[src] >= 0) return make_pair(steps[src], next[src]);
		int result = -1;
		int dist = INT_MAX;
		steps[src] = dist;
		next[src] = result;
		int diff = word_diff(source, target);
		if(diff == 1 || (diff == 2 && is_anagram(target, source))){
			steps[src] = 1;
			next[src] = dictionary.size();
			return make_pair(1, dictionary.size());
		}
		for(int i = 1; i < dictionary.size(); ++i){
			int diff = word_diff(dictionary[i], source);
			if(diff == 1 || (diff == 2 && is_anagram(dictionary[i], source))){
				cout << source << " " << dictionary[i] << " " << target << endl;
				pair<int, int> r = convert(dictionary, i, target);
				if(r.first == INT_MAX) continue;
				if(r.first+1 < dist || (r.first+1 == dist && result > 0 && dictionary[i] < dictionary[result])){
					result = i;
					dist = r.first+1;
				}
			}
		}
		steps[src] = dist;
		next[src] = result;
		return make_pair(steps[src], next[src]);
	}

	vector <string> getConversions(vector <string> dictionary, string source, string target)
	{
		for(int i = 0; i < dictionary.size()+1; ++i){
			steps[i] = next[i] = -1;
		}
		vector <string> result;
		vector <string> new_dictionary;
		new_dictionary.push_back(source);
		for(vector<string> :: iterator it = dictionary.begin(); it != dictionary.end(); ++it){
			new_dictionary.push_back(*it);
		}
		cout <<" Start "<<endl;
		pair<int, int> r = convert(new_dictionary, 0, target);
		cout << r.first << " " << r.second <<endl;
		for(int i = 0; i < new_dictionary.size(); ++i){
			cout << i << " " << steps[i] << " " << next[i] << endl;
		}
		if(r.second >= 0){
			result.push_back(source);
			if(r.second < new_dictionary.size()){
				int ind = r.second;
				while(ind != new_dictionary.size()){
					result.push_back(new_dictionary[ind]);	
					ind = next[ind];
				}
			}
			result.push_back(target);
		}
		return result;
	}
};

