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
#define maxN 400000
#define INF 1000111222

using namespace std;

int a[maxN+5];
int maxL[maxN+5],maxR[maxN+5];
int minL[maxN+5],minR[maxN+5];
int n;

int main()
{
	freopen("B.INP","r",stdin);
	freopen("B.OUT","w",stdout);
	while(scanf(" %d ",&n) && n!=1)
	{
		maxL[0] = -INF;
		minL[0] = INF;
		
		maxR[n+1] = -INF;
		minR[n+1] = INF;
		for(int i = 1 ; i <= n ; i++)
		{
			scanf(" %d ",&a[i]);
			maxL[i] = max(a[i],maxL[i-1]);
			minL[i] = min(a[i],minL[i-1]);
		}
		
		for(int i = n ; i >= 1 ; i--)
		{
			maxR[i] = max(a[i],maxR[i+1]);
			minR[i] = min(a[i],minR[i+1]);
		}
		
		int x;
		int m = INF;
		for(int i = 1 ; i < n ; i++)
		{
			int L = maxL[i] - minL[i];
			int R = maxR[i+1] - minR[i+1];
			int k = max(L,R);
			if(k < m)
			{
				m = k;
				x = i;
			}
		}
		printf("%d\n",x);
	}
	return 0;
}

