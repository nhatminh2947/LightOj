//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1012 - Guilty Prince
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
int n,m;

inline bool inside(int y, int x)
{
	return (0 <= y && y < n && 0 <= x && x < m);
}

inline void BFS()
{
	int dx[] = {-1, 0, 0, 1};
	int dy[] = { 0,-1, 1, 0};
	
	queue< pair<int,int> > q;
	
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			if(data[i][j] == '@')
			{
				q.push(mp(i,j));
				break;
			}
	
	int cnt = 0;
	while(!q.empty())
	{
		int x = q.front().ss;
		int y = q.front().ff;
		
		q.pop();
		cnt++;
		
		for(int i = 0 ; i < 4 ; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(inside(yy,xx) && data[yy][xx] == '.')
			{
				data[yy][xx] = '@';
				q.push(mp(yy,xx));
			}
		}
	}
	
	printf("%d\n",cnt);
}

int main()
{
	freopen("1012 - Guilty Prince.INP","r",stdin);
	freopen("1012 - Guilty Prince.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&m,&n);
		for(int i = 0 ; i < n ; i++)
			scanf(" %s ",&data[i]);
		printf("Case %d: ",t);
		BFS();
	}
	return 0;
}

