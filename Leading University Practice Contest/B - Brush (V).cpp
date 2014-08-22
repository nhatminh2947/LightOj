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

vector< pair<int,int> > data[200];
int dist[200];
int n,m;

int dij()
{
	for(int i = 0 ; i <= n ; i++)
		dist[i] = INF;
	set< pair<int,int> > s;
	
	s.insert(mp(0,1));
	dist[1] = 0;
	
	while(!s.empty())
	{
		pair<int,int> tmp = *s.begin();
		int dis = tmp.ff;
		int pos = tmp.ss;
		
		s.erase(tmp);
		if(pos == n)
			return dis;
		
		int sz = data[pos].size();
		
		for(int i = 0 ;i < sz ; i++)
		{
			int p = data[pos][i].ff;
			int d = data[pos][i].ss;
			
			if(dist[p] > dis + d)
			{
				if(dist[p] != INF)
					s.erase(mp(dist[p],p));
				dist[p] = dis+ d;
				s.insert(mp(dist[p],p));
			}
		}
	}
	
	return -1;
}

int main()
{
	freopen("B - Brush (V).INP","r",stdin);
	freopen("B - Brush (V).OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&m);
		for(int i = 1 ; i <= n ; i++)
			data[i].clear();
		
		for(int i = 0 ; i < m ; i++)
		{
			int u,v,w;
			scanf(" %d %d %d ",&u,&v,&w);
			data[u].pb(mp(v,w));
			data[v].pb(mp(u,w));
		}
		
		printf("Case %d: ",t);
		int ans = dij();
		if(ans == -1)
			puts("Impossible");
		else printf("%d\n",ans);
	}
	return 0;
}

