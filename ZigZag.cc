
// {{{ Boilerplate Code <--------------------------------------------------
//
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}

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

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;

// }}}

class ZigZag
{
public:
	int longestZigZag(vector <int> sequence)
	{
		int LEN = sequence.size();
		int zig[LEN]; //Lower Position
		int zag[LEN]; //Higher Position
		for(int i = 0; i < LEN; ++i){
			zig[i] = zag[i] = 1;
		}
		for(int i = 0; i < LEN; ++i){
			int new_zig, new_zag;
			new_zig = new_zag = 1;
			int val = sequence [i];
			for(int j = 0; j < i; ++j){
				if(sequence[j] < val){
					new_zag = (new_zag > zig[j] + 1) ? new_zag : (zig[j]+1);
				}
				if(sequence[j] > val){
					new_zig = (new_zig > zag[j] + 1) ? new_zig : (zag[j]+1);
				}
			}
			zig[i] = new_zig;
			zag[i] = new_zag;
		}
		int slen = 0;
		for(int i = 0; i < LEN; ++i){
			if(slen < zig[i]) slen = zig[i];	
			if(slen < zag[i]) slen = zag[i];	
		}
		return slen;
	}
};

