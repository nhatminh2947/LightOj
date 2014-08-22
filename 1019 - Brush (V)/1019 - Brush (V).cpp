//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1019 - Brush (V)
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

int tcs,n,m;
vector< pair<int,int> > data[105];
int dist[105];

int dij()
{
	set< pair<int,int> > s;
	fill(dist+1,dist+n+1,INF);
	dist[1] = 0;
	s.insert(mp(0,1));
	
	while(!s.empty())
	{
		pair<int,int> tmp = *s.begin();
		int d = tmp.ff;
		int p = tmp.ss;
		if(p == n)
			return d;
		s.erase(tmp);
		int sz = data[p].size();
		for(int i = 0 ; i < sz ; i++)
		{
			int pp = data[p][i].ff;
			int dd = data[p][i].ss;
			
			if(dist[pp] > d + dd)
			{
				if(dist[pp] != INF)
					s.erase(mp(dist[pp],pp));
				dist[pp] = d + dd;
				s.insert(mp(dist[pp],pp));
			}
		}
	}
	
	return INF;
}

void reset()
{
	for(int i = 1 ; i <= n ; i++)
		data[i].clear();
}

int main()
{
	freopen("1019 - Brush (V).INP","r",stdin);
	freopen("1019 - Brush (V).OUT","w",stdout);
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&m);
		reset();
		for(int i = 0 ; i < m ; i++)
		{
			int u,v,w;
			scanf(" %d %d %d ",&u,&v,&w);
			data[u].pb(mp(v,w));
			data[v].pb(mp(u,w));
		}
		printf("Case %d: ",t);
		int ans = dij();
		if(ans == INF)
			puts("Impossible");
		else printf("%d\n",ans);
	}
	return 0;
}

