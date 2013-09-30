//172.96: Success.
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

class GymTraining
{
public:
	int trainingTime(int needToTrain, int minPulse, int maxPulse, int trainChange, int restChange)
	{
		int cnt = 0;
		int currentPulse = minPulse;
		if(minPulse + trainChange > maxPulse) return -1;
		while(needToTrain > 0){
			++cnt;
			if(currentPulse + trainChange <= maxPulse){
				currentPulse +=trainChange;
				--needToTrain;
			}
			else{
				currentPulse -= restChange;
				if(currentPulse < minPulse) currentPulse = minPulse;
			}
		}
		return cnt;
	}
};

