//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1174 - Commandos
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
#define maxN 123456
#define INF 1000111222

using namespace std;

int n,r;
int path[105][105];

inline void floyd()
{
	for(int k = 0 ; k < n ; k++)
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
}

int main()
{
	freopen("1174 - Commandos.INP","r",stdin);
	freopen("1174 - Commandos.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&r);
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				if(i == j)
					path[i][j] = 0;
				else path[i][j] = INF;
		for(int i = 0 ; i < r ; i++)
		{
			int u,v;
			scanf(" %d %d ",&u,&v);
			path[u][v] = 1;
			path[v][u] = 1;
		}
		floyd();
		int s,d;
		scanf(" %d %d ",&s,&d);
		
		int dist = -INF;
		for(int i = 0 ; i < n ; i++)
			dist = max(dist,path[s][i] + path[i][d]);
		
		printf("Case %d: %d\n",t,dist);
	}
	return 0;
}

