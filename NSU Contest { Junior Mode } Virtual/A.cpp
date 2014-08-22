//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 
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

int main()
{
	freopen("A.INP","r",stdin);
	freopen("A.OUT","w",stdout);
	int n;
	scanf(" %d ",&n);
	for(int i = 0 ; i < n ; i++)
	{
		int tcs;
		scanf(" %d ",&tcs);
		int a[15];
		for(int i = 0 ; i < 10 ; i++)
			scanf(" %d ",&a[i]);
		sort(a,a+10);
		printf("%d %d\n",tcs,a[7]);
	}
	return 0;
}

