
// {{{ Boilerplate Code <--------------------------------------------------
//
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
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

class DeckRearranging
{
public:
	string rearrange(string deck, vector <int> above)
	{
		vector <char> ndeck;
		ndeck.push_back(deck[0]);
		for(int i = 1; i < deck.size(); ++i){
			char c = deck[i];
			int pos = above[i];
			ndeck.insert(ndeck.begin()+pos, c);	
		}
		string s = "";
		for(int i = 0; i < ndeck.size(); ++i)
			s+=ndeck[i];
		return s;
	}
};

