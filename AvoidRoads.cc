//82.63 Submit OK
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

class AvoidRoads
{
public:
	string construct_string(int a, int b, int c, int d){
		char str[20];
		sprintf(str, "%d %d %d %d", a, b, c, d);
		string result = str;
		return result;
	}
	long long numWays(int width, int height, vector <string> bad)
	{
		++height;
		++width;
		long long arr[width][height];
		for(int i = 0; i < height; ++i){
			for(int j = 0; j < width; ++j){
				arr[j][i] = 0;
			}
		}
		cout << "DONE" << endl;
		arr[0][0] = 1;
		for(int i = 1; i < height; ++i){
			if((find(bad.begin(), bad.end(), construct_string(0,i-1,0,i)) == bad.end())
			&& (find(bad.begin(), bad.end(), construct_string(0,i,0,i-1)) == bad.end()))
				arr[0][i] += arr[0][i-1];
		}
		cout << "DONE 1" << endl;
		for(int j = 1; j < width; ++j){
			if((find(bad.begin(), bad.end(), construct_string(j-1,0,j,0)) == bad.end())
			&& (find(bad.begin(), bad.end(), construct_string(j,0,j-1,0)) == bad.end()))
				arr[j][0] += arr[j-1][0];
		}
		cout << "DONE 2" << endl;
		for(int i = 1; i < height; ++i){
			for(int j = 1; j < width; ++j){
			if((find(bad.begin(), bad.end(), construct_string(j-1,i,j,i)) == bad.end()) 
			&& (find(bad.begin(), bad.end(), construct_string(j,i,j-1,i)) == bad.end()))
				arr[j][i] += arr[j-1][i];
			if((find(bad.begin(), bad.end(), construct_string(j,i-1,j,i)) == bad.end())
			&& find(bad.begin(), bad.end(), construct_string(j,i,j,i-1)) == bad.end())
				arr[j][i] += arr[j][i-1];
			}
		}
		cout << "DONE 3" << endl;
		return arr[width-1][height-1];
	}
};

