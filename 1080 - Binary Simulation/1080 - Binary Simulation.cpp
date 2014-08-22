//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1080 - Binary Simulation
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

char bit[100005];
int IT[500005];

int build(int node, int l, int r)
{
	if(l == r)
		return IT[node] = 1;
	
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	IT[node] = 1;
}

int update(int node, int l, int r, int a, int b)
{
	if(a <= l && r <= b)
		return IT[node] *= -1;
		
	if(r < a || b < l)
		return 0;
	
	update(node*2, l, (l+r)/2, a, b);
	update(node*2+1, (l+r)/2+1, r, a, b);
}

int answer(int node, int l, int r, int x)
{
	int sign = IT[node];
	while(l < r)
	{
		int mid = (l+r)/2;
		if(l <= x && x <= mid)
		{
			node *= 2;
			sign *= IT[node];
			r = mid;
		}
		else if(mid+1 <= x && x <= r)
		{
			node = node*2 + 1;
			sign *= IT[node];
			l = mid + 1;
		}
	}
	
	if(sign == -1)
	{
		if(bit[l] == '0')
			return 1;
		else return 0;
	}
	else return bit[l] - '0';
	
}

int main()
{
	freopen("1080 - Binary Simulation.INP","r",stdin);
	freopen("1080 - Binary Simulation.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		printf("Case %d:\n",t);
		scanf(" %s ",&bit);
		int n = strlen(bit);
		build(1,0,n-1);
		int q;
		scanf(" %d ",&q);
		for(int i = 0 ; i < q ; i++)
		{
			char cmd;
			scanf(" %c ",&cmd);
			if(cmd == 'I')
			{
				int a,b;
				scanf(" %d %d ",&a,&b);
				update(1,0,n-1,a-1,b-1);
			}
			else
			{
				int x;
				scanf(" %d ",&x);
				int ans = answer(1,0,n-1,x-1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}

