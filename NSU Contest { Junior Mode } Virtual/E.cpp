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

bool palind(int n, int b)
{
	vector<int> v;
	while(n)
	{
		v.pb(n%b);
		n/=b;
	}
	int sz = v.size();
	int lim = sz/2;
	for(int i = 0 ; i <= lim ; i++)
		if(v[i] != v[sz-i-1])
			return false;
	return true;
}

int main()
{
	freopen("E.INP","r",stdin);
	freopen("E.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		int n,s;
		scanf(" %d %d ",&n,&s);
		printf("Case %d:\n",t);
		while(n)
		{
			s++;
			int cnt = 0;
			for(int i = 2 ; i <= 10 && cnt < 2; i++)
				if(palind(s,i))
					cnt++;
			if(cnt == 2)
			{
				printf("%d\n",s);
				n--;
			}
		}
	}
	return 0;
}

