
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class RunLengthPlus
{
public:
	string shorter(string s1, string s2){
		if(s1.size() < s2.size()){
			return s1;
		}
		if(s2.size() < s1.size()){
			return s2;
		}
		if(s1 < s2) return s1;
		return s2;
	}
	bool is_num_part(string a){
		return (isdigit(a[0]));
	}
	int num_part(string a){
		char c[a.size()];
		if(int(a.find("(")) <  0){
			int ind = 0;
			while(isdigit(a[ind])){
				c[ind] = a[ind];
				++ind;
			}
			c[ind] = 0;
			return atoi(c);
		}
		a = a.substr(0, a.find("("));
		return atoi(a.c_str());
	}
	string remove_num(string a){
		int ind = 0;
		while(isdigit(a[ind]) && ind < a.size()) ++ind;
		return a.substr(ind);
	}
	bool start_close(string a){
		int cnt = 1;
		int i ;
		for(i = 1; i < a.size() && cnt > 0; ++i){
			if(a[i] == '(') ++cnt;
			if(a[i] == ')') --cnt;
		}
		return (cnt == 0 && i == a.size());
	}
	string string_part(string a){
		if(!is_num_part(a)) return a;
		int ind = 0;
		while((isdigit(a[ind]) || a[ind] == '(') && ind < a.size()){
			if(a[ind] == '('){
				string b = a.substr(ind);
				if(start_close(b))
					return  b.substr(1,b.size()-2);
				return a;
			}
			++ind;
		}
		return a.substr(ind);
	}
	bool compare(string s1, string s2){
		if(s1 == s2) return true;
		if(is_num_part(s1)){
			string s = remove_num(s1);
			if(start_close(s) || s.size() == 1) s1 = string_part(s1);
		}
		if(is_num_part(s2)){
			string s = remove_num(s2);
			if(start_close(s) || s.size() == 1) s2 = string_part(s2);
		}
		return s1 == s2;
	}
	string compress(string s)
	{
		int len = s.size();
		string alg[len][len];
		string small[len][len];
		string MAX_STRING = "";
		for(int i = 0; i < 50; ++i){
			MAX_STRING += 'Z';
		}
		for(int i = 0; i < len; ++i){
			for(int j = 0; j < len; ++j){
				if(i == j){
					alg[i][i] = small[i][i] = s[i];
				}
				else
					alg[i][j] = small[i][j] = MAX_STRING;
			}
		}
		for(int l = 2; l <= len; ++l){
			for(int i = 0; i+l <= len; ++i){
				int j = i+l-1;
				bool best_match = false;
				for(int k = i+1; k < j+1; ++k){
					if(compare(alg[i][k-1], alg[k][j])){
						int x = 1;
						int y = 1;
						string a = alg[i][k-1];
						string b = alg[k][j];
					
						if(is_num_part(a)){
								string s = remove_num(a);
								if(start_close(s) || s.size() == 1){
									x = num_part(a);
									a = string_part(a);
								}
							}
						if(is_num_part(b)){
								string s = remove_num(b);
								if(start_close(s) || s.size() == 1){
									y = num_part(b);
									b = string_part(b);
								}
						}
						assert(a==b);
						best_match =true;
						char num[4];
						sprintf(num, "%d", x+y);
						if(a.size() == 1)
							alg[i][j] = num+a;
						else{
							a = "(" + a + ")";
							alg[i][j] = num+a;
						}
						string match = shorter(alg[i][j], small[i][k-1]+small[k][j]);
						small[i][j] = shorter(match, small[i][j]);
					}
					else{
						if(!best_match)
							alg[i][j] = shorter(alg[i][k-1]+alg[k][j], alg[i][j]);
						small[i][j] = shorter(small[i][j], small[i][k-1]+small[k][j]);
					}
				}
			}
		}
		return small[0][len-1];
	}
};

