
// {{{ Boilerplate Code <--------------------------------------------------
//
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}
#include <cmath>
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

class ColumnDiagramPerimeter
{
public:
	int getPerimiter(vector <int> a)
	{
		int len = a.size();
		int perimeter = 2 * len;
		perimeter += a[0]+a[len-1];
		for(int i = 1; i < len ; ++i){
			int diff = a[i]-a[i-1];	
			diff = (diff > 0) ? diff : -diff;
			perimeter += diff;
		}
		return perimeter;
	}
};

