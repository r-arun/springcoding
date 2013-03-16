
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
long long moves[103][103][57];

class ChessMetric
{
public:
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
	{
	//	memset(moves,0L,size*size*numMoves*sizeof(long long));
		vector< vector<long long> > current;
		vector< vector<long long> > next;
		for(int i = 0; i < size; ++i){
			vector<long long> row;
			for(int j = 0; j < size; ++j){
				row.push_back(0L);
			}
			current.push_back(row);
		}
		
		current[start[0]][start[1]] = 1L;
		for(int m=0; m < numMoves; m++){
			for(int i = 0; i < size; ++i){
				vector<long long> row;
				for(int j = 0; j < size; ++j){
					row.push_back(0);
				}
				next.push_back(row);
			}
			/*while(!qin.empty())
				pair<int,int> u = qin.front();
				qin.pop();
				int x = u.first;
				int y = u.second;
				*/
			for(int x = 0; x < size; ++x){
				for(int y = 0; y < size; ++y){
					for(int x1 = x-2; x1 <= x+2; ++x1){
						for(int y1 = y-2; y1 <= y+2; ++y1){
							if(x1 < 0 || x1 >= size || y1 < 0 || y1 >= size ||
							(x1 == x-2 && (y1 == y-2 || y1 == y+2 || y1 == y)) ||
							(x1 == x && (y1 == y-2 || y1 == y+2 || y1 == y)) ||
							(x1 == x+2 && (y1 == y-2 || y1 == y+2 || y1 == y)))
								continue;
							next[x1][y1] += current[x][y];
						}
					}
				}
			}
			current = next;
			next.clear();
		}
		return current[end[0]][end[1]];
	}
};

