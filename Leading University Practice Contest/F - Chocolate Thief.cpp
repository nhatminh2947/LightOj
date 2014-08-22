//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: F - Chocolate Thief
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

pair<string, int> data[105];

int main()
{
	freopen("F - Chocolate Thief.INP","r",stdin);
	freopen("F - Chocolate Thief.OUT","w",stdout);
	int tcs,n;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d ",&n);
		int mi = INF;
		int ma = -INF;
		
		int a,b;
		for(int i = 0 ; i < n ; i++)
		{
			int l,w,h;
			cin >> data[i].ff;
			scanf(" %d %d %d ",&l,&w,&h);
			data[i].ss = l*w*h;
			
			if(data[i].ss < mi)
			{
				mi = data[i].ss;
				b = i;
			}
			
			if(data[i].ss > ma)
			{
				ma = data[i].ss;
				a = i;
			}
		}
		
		printf("Case %d: ",t);
		if(a == b)
			puts("no thief");
		else
		{
			cout << data[a].ff;
			printf(" took chocolate from ");
			cout << data[b].ff << endl;
		}
		
	}
	return 0;
}

