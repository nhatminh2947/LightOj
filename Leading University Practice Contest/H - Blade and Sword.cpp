//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: H - Blade and Sword
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

int n,m;
char data[205][205];
int dist[205][205];
bool vis[205][205];

bool inside(int y, int x)
{
	return (0 <= y && y < n && 0 <= x && x < m);
}

int BFS()
{
	pair<int,int> st,ed;
	vector< pair<int,int> > tele;
	tele.clear();
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
		{
			if(data[i][j] == 'P')
			{
				st.ff = i;
				st.ss = j;
			}
			else if(data[i][j] == 'D')
			{
				ed.ff = i;
				ed.ss = j;
			}
			else if(data[i][j] == '*')
				tele.pb(mp(i,j));
			dist[i][j] = INF;
			vis[i][j] = false;
		}
		
	int sz = tele.size();
	set< pair<int,pair<int,int> > > s;
	
	s.insert(mp(0,st));
	dist[st.ff][st.ss] = 0;
	
	int dx[] = {-1, 0, 0, 1};
	int dy[] = { 0,-1, 1, 0};
	
	while(!s.empty())
	{
		pair<int,pair<int,int> > tmp = *s.begin();
		int y = tmp.ss.ff;
		int x = tmp.ss.ss;
		int d = tmp.ff;
		s.erase(tmp);
		if(y == ed.ff && x == ed.ss)
			return d;
		
		vis[y][x] = true;
		for(int i = 0 ; i < 4 ; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if(inside(yy,xx) && !vis[yy][xx])
			{
				if(data[yy][xx] == '.' || data[yy][xx] == 'D' && dist[yy][xx] > d + 1)
				{
					if(dist[yy][xx] != INF)
						s.erase(mp(dist[yy][xx],mp(yy,xx)));
					dist[yy][xx] = d + 1;
					s.insert(mp(dist[yy][xx],mp(yy,xx)));
				}
				else if(data[yy][xx] == '*')
				{
					if(dist[yy][xx] > d + 1)
					{
						if(dist[yy][xx] != INF)
							s.erase(mp(dist[yy][xx],mp(yy,xx)));
						dist[yy][xx] = d + 1;
						s.insert(mp(dist[yy][xx],mp(yy,xx)));
					}
					for(int i = 0 ; i < sz ; i++)
					{
						int xxx = tele[i].ss;
						int yyy = tele[i].ff;
						
						if(data[yyy][xxx] == '*' && dist[yy][xx] > d + 2)
						{
							if(dist[yy][xx] != INF)
								s.erase(mp(dist[yyy][xxx],mp(yyy,xxx)));
							dist[yyy][xxx] = d + 2;
							s.insert(mp(dist[yyy][xxx],mp(yyy,xxx)));
						}
					}
				}
			}
		}
	}
	
	return -1;
}

int main()
{
	freopen("H - Blade and Sword.INP","r",stdin);
	freopen("H - Blade and Sword.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&m);
		for(int i = 0 ; i < n ; i++)
			gets(data[i]);
			
		printf("Case %d: ",t);
		
		int ans = BFS();
		
		if(ans == -1)
			puts("impossible");
		else printf("%d\n",ans);
	}
	
	return 0;
}

