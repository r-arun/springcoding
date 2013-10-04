//75 Resubmission Penality. Submit OK.
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// }}}

class BadNeighbors
{
public:
	int maxDonations(vector <int> donations)
	{
		int length = donations.size();
		int takeFirst[2][length];
		int takeLast[2][length];
		for(int i = 0; i < 2; ++i){
			for(int j = 0; j < 2; ++j){
				takeFirst[i][j] = takeLast[i][j] = 0;	
			}
		}
		takeFirst[0][0] = donations[0];
		takeFirst[1][0] = 0;
		takeLast[0][0] = 0;
		takeLast[1][0] = 0;
		int takeFirstMax = 0;
		int takeLastMax = 0;
		for(int i = 1; i < donations.size()-1; ++i){
			takeFirst[0][i] = takeFirst[1][i-1]+donations[i];
			takeFirst[1][i] = max(takeFirst[0][i-1], takeFirst[1][i-1]);
		}
		takeFirstMax = max(takeFirst[1][length-2], takeFirst[0][length-2]);
		for(int i = 1; i < donations.size(); ++i){
			takeLast[0][i] = takeLast[1][i-1]+donations[i];
			takeLast[1][i] = max(takeLast[0][i-1], takeLast[1][i-1]);
		}
		takeLastMax = max(takeLast[0][length-1], takeLast[1][length-1]);
		return max(takeFirstMax, takeLastMax);
	}
};

