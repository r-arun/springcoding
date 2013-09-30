//213.24 : Succes
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

class MultiNumber
{
public:
	string check(int number)
	{
		if(number < 10) return "NO";
		int n = number;
		long product  = 1;
		int digits = 0;
		int cnt_zero = 0;
		while(n){
			product *= n%10;
			if(n%10 == 0) ++cnt_zero;
			n/=10;
			++digits;
		}
		if(product == 0){
			if(cnt_zero > 1) return "YES";
			return "NO";
		}
		long rightHalf = product/(number%10);
		long leftHalf = number % 10;
		n = number/10;
		while(--digits){
			if(rightHalf == leftHalf) return "YES";
			rightHalf /= (n%10);
			leftHalf *= (n%10);
			n/=10;
		}
		return "NO";
	}
};

