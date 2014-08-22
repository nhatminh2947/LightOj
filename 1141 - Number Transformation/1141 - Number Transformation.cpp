//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1141 - Number Transformation
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

int s,e;
vector<int> primes[1005];
bool check[1005];
bool num[1005];

inline void sieve()
{
	for(int i = 0 ; i <= 1000 ; i++)
		check[i] = true;
	
	for(int i = 2 ; i <= 1000 ; i++)
	{
		if(check[i])
		{
			for(int j = i ; i*j <= 1000 ; j++)
				check[i*j] = false;
			for(int k = 2 ; k <= 1000 ; k++)
				if(k % i == 0 && k != i)
					primes[k].pb(i);
		}
	}
}

inline int BFS()
{
	queue< pair<int,int> > q;
	for(int i = 1 ; i <= e ; i++)
		num[i] = false;
	
	q.push(mp(s,0));
	num[s] = true;
	while(!q.empty())
	{
		int a = q.front().ff;
		int d = q.front().ss;
		
		q.pop();
		if(a == e)
			return d;
		
		int sz = primes[a].size();
		for(int i = 0 ; i < sz ; i++)
		{
			int n = primes[a][i];
			if(a+n <= e && !num[a+n])
			{
				num[a+n] = true;
				q.push(mp(a+n,d+1));
			}
		}
	}
	
	return -1;
}

int main()
{
	freopen("1141 - Number Transformation.INP","r",stdin);
	freopen("1141 - Number Transformation.OUT","w",stdout);
	sieve();
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d ",&s,&e);
		printf("Case %d: %d\n",t,BFS());
	}
	return 0;
}

