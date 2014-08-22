//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: F - Exotic Foods
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
#define maxN 50000
#define INF 1000111222

using namespace std;

int a[50005];

int main()
{
	freopen("F - Exotic Foods.INP","r",stdin);
	freopen("F - Exotic Foods.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		int n;
		scanf(" %d ",&n);
		int sum = 0;
		for(int i = 0 ; i < n ; i++)
		{
			scanf(" %d ",&a[i]);
			sum += a[i];
		}
		
		sort(a,a+n);
		n--;
		int ans = 0;
		for(int i = n ; i >= 0 ; i--)
		{
			if(ans > sum)
				break;
			
			ans += a[i];
			sum -= a[i];
		}
		
		printf("Data Set %d: %d\n\n",t,ans);
	}
	return 0;
}

