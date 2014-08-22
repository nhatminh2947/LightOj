//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1101 - A Secret Mission
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
#include <cctype>
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
	edge() {}
};

edge e[100005];
bool check[100005];

int getRoot(int u)
{
	if(lab[u] == u)
		return u;
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

void Kruskal()
{
	int done = 0;
	for(int i = 1 ; i <= n ; i++)
		lab[i] = i;
	
	for(int i = 0 ; i < m ; i++)
		check[i] = false;
	
	for(int i = 0 ; i < m ; i++)
	{
		int u = getRoot(e[i].u);
		int v = getRoot(e[i].v);
		int w = e[i].w;
		
		if(u != v)
		{
			done++;
			unionset(u,v);
			check[i] = true;
		}
		
		if(done == (n-1))
			return;
	}
}

int main()
{
	freopen("1101 - A Secret Mission.INP","r",stdin);
	freopen("1101 - A Secret Mission.OUT","w",stdout);
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		printf("Case %d: ",t);
		scanf(" %d %d ",&n,&m);
		for(int i = 0 ; i < m ; i++)
			scanf(" %d %d %d ",&e[i].u,&e[i].v,&e[i].w);
		
		scanf(" %d ",&q);
		for(int i = 0 ; i < q ; i++)
		{
			scanf(" %d %d ",&st,&ed);
			
		}
	}
	return 0;
}

