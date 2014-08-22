//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1002 - Country Roads
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

typedef struct 
{
	int u,v,w;
}edge;

edge e[16005];
int n,m,p;
int dist[505];
int lab[505];
vector< pair<int,int> > data[505];

int getRoot(int u)
{
	if(lab[u] == u)
		return lab[u];
	return lab[u] = getRoot(lab[u]);
}

int unionset(int u, int v)
{
	return lab[u] = v;
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

void BFS()
{
	queue<int> q;
	q.push(p);
	dist[p] = 0;
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		int sz = data[u].size();
		for(int i = 0 ; i < sz ; i++)
		{
			int d = data[u][i].ss;
			int v = data[u][i].ff;
			if(dist[v] == -INF)
			{
				dist[v] = max(dist[u],d);
				q.push(v);
			}
		}
	}
}

int main()
{
	freopen("1002 - Country Roads.INP","r",stdin);
	freopen("1002 - Country Roads.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n, &m);
		for(int i = 0 ; i < m ; i++)
			scanf(" %d %d %d ",&e[i].u,&e[i].v,&e[i].w);
		scanf(" %d ",&p);
		
		for(int i = 0 ; i < n ; i++)
		{
			lab[i] = i;
			data[i].clear();
			dist[i] = -INF;
		}
		
		sort(e,e+m,cmp);
		
		int done = 0;
		for(int i = 0 ; i < m ; i++)
		{
			int u = getRoot(e[i].u);
			int v = getRoot(e[i].v);
			int w = e[i].w;
			
			if(u != v)
			{
				data[u].pb(mp(v,w));
				data[v].pb(mp(u,w));
				unionset(u,v);
				done++;
			}
			
			if(done == n-1)
				break;
		}
		
		BFS();
		printf("Case %d:\n",t);
		for(int i = 0 ; i < n ; i++)
		{
			if(dist[i] == -INF)
				puts("Impossible");
			else printf("%d\n",dist[i]);
		}
		
	}
	return 0;
}

