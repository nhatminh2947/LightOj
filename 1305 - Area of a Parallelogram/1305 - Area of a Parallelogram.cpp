//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1305 - Area of a Parallelogram
// Verdict: Accepted
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
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

struct point
{
    int x,y;
};

point a,b,c,d;

inline int len(point u, point v)
{
    return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}

int main()
{
	freopen("1305 - Area of a Parallelogram.INP","r",stdin);
	freopen("1305 - Area of a Parallelogram.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
	    scanf(" %d %d %d %d %d %d ",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	    
	    d.x = c.x - (b.x-a.x);
	    d.y = a.y + (c.y-b.y);
	    
	    int S = abs (0.5 * ( (a.x-b.x)*(a.y+b.y) + (b.x-c.x)*(b.y+c.y) + (c.x-d.x)*(c.y+d.y) + (d.x-a.x)*(d.y+a.y) ));
	    
	    printf("Case %d: %d %d %d\n",t,d.x,d.y,S);
	}

	return 0;
}

