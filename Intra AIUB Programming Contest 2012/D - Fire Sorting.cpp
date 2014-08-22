//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: D - Fire Sorting
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

char data[25][25];
bool vis[25][25];
int r,c;

bool inside(int y, int x)
{
	return (0 <= y && y < r && 0 <= x && x < c);
}

int BFS(int y, int x)
{
	int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
	int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
	vis[y][x] = true;
	queue< pair<int,int> > q;
	q.push(mp(y,x));
	
	int sz = 0;
	while(!q.empty())
	{
		int yy = q.front().ff;
		int xx = q.front().ss;
		sz++;
		q.pop();
		
		for(int i = 0 ; i < 8 ; i++)
		{
			int xxx = xx + dx[i];
			int yyy = yy + dy[i];
			
			if(inside(yyy,xxx) && !vis[yyy][xxx] && data[yyy][xxx] == '#')
			{
				q.push(mp(yyy,xxx));
				vis[yyy][xxx] = true;
			}
		}
	}
	
	return sz;
}

int main()
{
	freopen("D - Fire Sorting.INP","r",stdin);
	freopen("D - Fire Sorting.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&r,&c);
		for(int i = 0 ; i < r ; i++)
			scanf(" %s ",&data[i]);
		
		for(int i = 0 ; i < r ; i++)
			for(int j = 0 ; j < c ; j++)
				vis[i][j] = false;
		
		int m = -INF;
		int cnt = 0;
		for(int i = 0 ; i < r ; i++)
			for(int j = 0 ; j < c ; j++)
			{
				if(data[i][j] == '#' && !vis[i][j])
				{
					m = max(m,BFS(i,j));
					cnt++;
				}
			}
		
		printf("Case %d: %d %d\n",t,cnt,m);
	}
	return 0;
}

