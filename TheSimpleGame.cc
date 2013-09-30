//230.05: Success
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <climits>
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

class TheSimpleGame
{
public:
	int distance(int x1, int y1, int x2, int y2){
		return abs(x1-x2)+abs(y1-y2);
	}
	int count(int n, vector <int> x, vector <int> y)
	{
		int total = 0;
		for(int i = 0; i < x.size(); ++i){
			int dist = INT_MAX;
			dist = min(dist, distance(x[i],y[i],1,1));
			dist = min(dist, distance(x[i],y[i],1,n));
			dist = min(dist, distance(x[i],y[i],n,1));
			dist = min(dist, distance(x[i],y[i],n,n));
			total += dist;
		}
		return total;
	}
};

