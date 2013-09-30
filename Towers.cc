//75/250 pts
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

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}
//The aim is to minimize the number of steps.
//From a given state (T1,T2,..Tn,H) it is possible to go to several states
//We can build a DP with this.
//Greedy approach is to minimize the number of buildings.
//Is the greedy approach sufficient?
class Towers
{
public:
	int attack(int myUnits, int hpT, int attackT, int numT)
	{
		int cnt = 0;
		int arr[numT];
		for(int i = 0; i < numT; ++i)
			arr[i] = hpT;
		int firstTower = 0;
		while(firstTower < numT){
			int ind = firstTower;
			int curUnits = myUnits;
			++cnt;
			while(ind < numT){
				if(curUnits >= arr[ind]){
					curUnits -= arr[ind];
					arr[ind] = 0;
					++firstTower;
					++ind;
				}
				else{
					arr[ind] -= curUnits;
					curUnits = 0;
					break;
				}
			}
			myUnits -= (numT-firstTower)*attackT;
			if(myUnits <= 0) return -1;
		}
		return cnt;
	}
};

