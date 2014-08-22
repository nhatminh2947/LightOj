//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1238 - Power Puff Girls
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

int n,m;
char data[25][25];
int dist[25][25];

inline bool inside(int y, int x)
{
	return (1 <= x && x < m && 1 <= y && y < n);
}

inline int BFS()
{
	queue< pair<int,int> > q;
	pair<int,int> a,b,c;
	for(int i = 1 ; i < n ; i++)
		for(int j = 1 ; j < m ; j++)
		{
			dist[i][j] = INF;
			if(data[i][j] == 'h')
			{
				q.push(mp(i,j));
				dist[i][j] = 0;
			}
			else if(data[i][j] == 'a')
			{
				a.ff = i;
				a.ss = j;
			}
			else if(data[i][j] == 'b')
			{
				b.ff = i;
				b.ss = j;
			}
			else if(data[i][j] == 'c')
			{
				c.ff = i;
				c.ss = j;
			}
		}
	
	int dx[] = {-1, 0, 0, 1};
	int dy[] = { 0,-1, 1, 0};
	int cnt = 0;
	while(!q.empty())
	{
		int y = q.front().ff;
		int x = q.front().ss;
		
		if(data[y][x] == 'a' || data[y][x] == 'b' || data[y][x] == 'c')
			cnt++;
		
		if(cnt == 3)
			break;
		
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++)
		{
			int yy = y + dy[i];
			int xx = x + dx[i];
			
			if(inside(yy,xx) && (data[yy][xx] == '.' 
			|| data[yy][xx] == 'a' 
			|| data[yy][xx] == 'b' 
			|| data[yy][xx] == 'c') && dist[yy][xx] == INF)
			{
				dist[yy][xx] = dist[y][x] + 1;
				q.push(mp(yy,xx));
			}
		}
	}
	
	return max(max(dist[b.ff][b.ss],dist[c.ff][c.ss]),dist[a.ff][a.ss]);
}


int main()
{
	freopen("1238 - Power Puff Girls.INP","r",stdin);
	freopen("1238 - Power Puff Girls.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&m);
		for(int i = 0 ; i < n ; i++)
			scanf(" %s ",&data[i]);
		m--;
		n--;
		
		printf("Case %d: %d\n",t,BFS());
	}
	return 0;
}

