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
#define maxN 1000000000
#define INF 1000111222

using namespace std;

int64 n;

int64 bSearch(int64 x)
{
	int64 lo = 1;
	int64 hi = maxN;
	int64 mid;
	int64 res = (int64)INF*INF;
	while(lo <= hi)
	{
		mid = (lo+hi)/2;
		int64 tmp = (mid*(mid-1))/2;
		if(tmp == x)
			return tmp;
		else if(tmp > x)
		{
			res = min(res,tmp);
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	
	return res;
}

int main()
{
	freopen("C.INP","r",stdin);
	freopen("C.OUT","w",stdout);
	while(scanf(" %lld ",&n) && n)
	{
		int64 ans = bSearch(n);
		ans -= n;
		if(ans)
			printf("%lld\n",ans);
		else puts("Not bored enough!");
	}
	return 0;
}

