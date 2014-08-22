//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 
// Verdict:
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define int64 long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

int main()
{
	freopen("D.INP","r",stdin);
	freopen("D.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		int64 x,y;
		scanf(" %lld %lld ",&x,&y);
		int64 k = y - x;
		
		int64 ans = (k+1)*x*x + k*(k+1)*(2*k+1)/6 + x*k*(k+1);
		printf("Case %d: %lld\n",t,ans);
	}
	return 0;
}

