//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1094 - Farthest Nodes in a Tree
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

int n;
vector< pair<int,int> > data[30005];
int dist[30005];

inline int BFS(int st)
{
	for(int i = 0 ; i < n ; i++)
		dist[i] = INF;
	
	queue<int> q;
	q.push(st);
	dist[st] = 0;
	int len = -INF;
	int pos;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		
		if(len < dist[p])
		{
			len = dist[p];
			pos = p;
		}
		
		int sz = data[p].size();
		
		for(int i = 0 ; i < sz ; i++)
		{
			int tmp = data[p][i].ff;
			int d = data[p][i].ss;
			if(dist[tmp] == INF)
			{
				dist[tmp] = dist[p] + d;
				q.push(tmp);
			}
		}
	}
	
	return pos;
}

int main()
{
	freopen("1094 - Farthest Nodes in a Tree.INP","r",stdin);
	freopen("1094 - Farthest Nodes in a Tree.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d ",&n);
		for(int i = 0 ; i < n ; i++)
			data[i].clear();
		
		for(int i = 1 ; i < n ; i++)
		{
			int u,v,w;
			scanf(" %d %d %d ",&u,&v,&w);
			data[u].pb(mp(v,w));
			data[v].pb(mp(u,w));
		}
		
		printf("Case %d: %d\n",t,dist[BFS(BFS(0))]);
	}
	return 0;
}

