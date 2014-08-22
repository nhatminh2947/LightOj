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

int tcs;
char a[505][505];
int dist[505][505];
int n,m;

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool inside(int y, int x)
{
	return (0 <= y && y < n && 0 <= x && x < m);
}

int BFS()
{
	queue< pair<int,int> > q;
	
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			dist[i][j] = INF;
	
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			if(a[i][j] == 'S')
			{
				q.push(mp(i,j));
				dist[i][j] = 0;
				break;
			}
	int ans = 0;
	while(!q.empty())
	{
		int x = q.front().ss;
		int y = q.front().ff;
		int d = dist[y][x];
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if(inside(yy,xx) && dist[yy][xx] == INF)
			{
				dist[yy][xx] = d + 1;
				if(a[yy][xx] == 'B')
					ans += dist[yy][xx];
				q.push(mp(yy,xx));
			}
		}
	}
	return 2*ans;
}

int main()
{
	freopen("A.INP","r",stdin);
	freopen("A.OUT","w",stdout);
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&n,&m);
		bool check = false;
		for(int i = 0 ; i < n ; i++)
			scanf(" %s ",&a[i]);
		
		int ans = BFS();
		printf("%d seconds to blocks get!\n",ans);
	}
	return 0;
}

