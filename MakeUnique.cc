// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}
//82.00/275 System test passed
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
// }}}
class MakeUnique
{
public:
	string eliminated(string original)
	{
		bool arr[26];
		int next[original.size()];
		int length[original.size()];
		string result = "";
		vector <char> valid;
		for(int i = 0; i < 26;++i)
			arr[i] = false;
		for(int i = 0; i < original.size(); ++i){
			length[i] = INT_MAX;next[i] = -2;
			arr[original[i]-'A'] = true;
			result += ".";
		}
		for(int i = 0; i < 26;++i){
			if(arr[i]){
				valid.push_back((char)('A'+i));
			}
		}
		for(vector<char>::iterator it = valid.begin(); it != valid.end(); ++it){
			cout << *it << endl;
		}
		for(int i = 0; i < original.size(); ++i){
			if(original[i] == valid[valid.size()-1]){
				next[i] = -1;
				length[i] = 1;
			}
		}
		for(int i = valid.size()-2; i >= 0; --i){
			char match = valid[i+1];	
			for(int j = original.size()-1; j >=0; --j){
				if(original[j] != valid[i]) continue;
				int best_length = INT_MAX;
				int best_next = -2;
				for(int k = original.size()-1; k >= j+1; --k){
					if(original[k]==match){
						if(length[k] != INT_MAX){
							int new_length = length[k]+k-j+1;
							if(new_length < best_length){
								best_length = new_length;
								best_next = k;
							}
						}
					}
				}
				length[j] = best_length;
				next[j] = best_next;
			}
		}
		int best_length = INT_MAX;
		int best_start = -2;
		for(int j = original.size()-1; j >=0; --j){
			if(original[j] == valid[0]){
				if(length[j] != INT_MAX){
					if(length[j] < best_length){
						best_length = length[j];
						best_start = j;
					}
				}
			}
		}
		if(best_length == INT_MAX) return "";
		while(best_start != -1){
			result[best_start] = original[best_start];
			best_start = next[best_start];
		}
		return result;
	}
};

