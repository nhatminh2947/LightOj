//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1123 - Trail Maintenance
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

struct edge
{
	int u,v,w;
};

int n,m;
bool check[205];
int lab[205];
edge e[6005],tmp[6005];
int done;
bool enough;

inline int getRoot(int u)
{
	if(lab[u] == u)
		return u;
	return lab[u] = getRoot(lab[u]);
}

inline int unionset(int u, int v)
{
	return lab[u] = v;
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

inline void MST(int sz)
{
	for(int i = 1 ; i <= n ; i++)
		lab[i] = i;
			
	sort(e,e+sz,cmp);
			
	done = 0;
	int cost = 0;
	for(int i = 0 ; i < sz && (done != n-1) ; i++)
	{
		int u = getRoot(e[i].u);
		int v = getRoot(e[i].v);
		if(u != v)
		{
			lab[u] = v;
			tmp[done]= e[i];
			done++;
			cost += e[i].w;
		}
	}
	
	for(int i = 0 ; i < done ; i++)
		e[i] = tmp[i];
			
	if(done == n-1)
	{
		printf("%d\n",cost);
		enough = true;
	}
	else printf("-1\n");
}

int main()
{
	freopen("1123 - Trail Maintenance.INP","r",stdin);
	freopen("1123 - Trail Maintenance.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&m);
		for(int i = 1 ; i <= n ; i++)
			check[i] = false;
		printf("Case %d:\n",t);
		int cnt = 0;
		int sz = 0;
		done = 0;
		enough = false;
		for(int k = 0 ; k < m ; k++)
		{
			int u,v,w;
			scanf(" %d %d %d ",&u,&v,&w);
			
			if(enough)
			{
				e[n-1].u = u;
				e[n-1].v = v;
				e[n-1].w = w;
				
				MST(n);
			}
			else
			{
				e[done].u = u;
				e[done].v = v;
				e[done].w = w;
				
				MST(done+1);
			}
		}
	}
	return 0;
}

