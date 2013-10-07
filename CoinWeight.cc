//Submitted: 82.00 Ok.
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cassert>
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

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class CoinWeight
{
public:
	pair<int, int> get_range(string str){
		int first_space = str.find(" ", 0);
		int second_space = str.find(" ", first_space+1);
		int third_space = str.find(" ", second_space+1);
		string num1 = str.substr(first_space+1, second_space);
		string num2 = str.substr(second_space+1, third_space);
		return make_pair(atoi(num1.c_str()), atoi(num2.c_str()));
	}

	int get_denomination(string str){
		int first_space = str.find(" ", 0);
		string den = str.substr(0, first_space);
		return atoi(den.c_str());
	}
/*	int ispossible(int denom, int weight){
		if(denom == 0 && weight == 0)
			return 1;
		if(denom < 0 || weight < 0) return 0;
		if(p[denom][weight] != -1) return p[denom][weight];
		
	}*/
	int possibleValues(int weight, vector <string> coins)
	{
		int MAX = 2509;
		int p[MAX][weight+1];
		map <pair<int, int>, bool> m;
		for(int i = 0; i < MAX; ++i){
			for(int j = 0; j < weight+1; ++j){
				p[i][j] = 0;
			}
		}
		for(int i =0; i < coins.size(); ++i){
			pair<int,int> range = get_range(coins[i]);
			int denom = get_denomination(coins[i]);
			for(int j = range.first; j <= range.second; ++j){
				m[make_pair(denom,j)]= true;
			}
		}
		cout <<"SAFE 1" << endl;
		for(int d = 1; d < MAX; ++d){
			for(int i = 0; i <= weight; ++i){
				if(m[make_pair(d, i)]){
					p[d][i] = 1;
				}
			}
		}
		for(int k = 2; k < MAX; ++k){
			for(int w = 2; w <= weight; ++w){
				bool found = 0;
				for(int i = 0; i < coins.size(); ++i){ //denom search
					pair<int,int> range = get_range(coins[i]);
					int denom = get_denomination(coins[i]);
					if(denom > k) continue;
					for(int j = range.first; j <= range.second; ++j){
						if(w < j) break;
						if(p[k-denom][w-j]){
							p[k][w]= 1;
							found = 1;
							break;
						}
					}
					if(found)
						break;
				}
			}
		}
		int cnt = 0;
		for(int d = 1; d < MAX; ++d){
			if(p[d][weight])
				++cnt;
		}
		return cnt;
	}
};
