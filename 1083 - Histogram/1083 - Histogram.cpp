//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1083 - Histogram
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

int a[30005];
int Left[30005];
int Right[30005];
int n;

inline void init()
{
	for(int i = 1 ; i <= n ; i++)
	{
		L[i] = i-1;
		while(data[L[i]] <= data[i])
			L[i] = L[L[i]];
	}
	
	for(int i = n ; i >= 1 ; i--)
	{
		R[i] = i+1;
		while(data[R[i]] >= data[i])
			R[i] = R[R[i]];
	}
}

int main()
{
	freopen("1083 - Histogram.INP","r",stdin);
	freopen("1083 - Histogram.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d ",&n);
		for(int i = 1 ; i <= n ; i++)
			scanf(" %d ",&a[i]);
		
		for(int i = 0 ; i < n ; i++)
		{
			
		}
	}
	return 0;
}

