//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: G - An Offer You Can’t Refuse
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

int main()
{
	freopen("G - An Offer You Can’t Refuse.INP","r",stdin);
	freopen("G - An Offer You Can’t Refuse.OUT","w",stdout);
	int tcs,a,b;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		printf("Case %d: ",t);
		scanf(" %d %d ",&a,&b);
		int ans = 1;
		int m = a;
		if(m < b)
		{
			m = b;
			ans = 2;
		}
		if(m % 13 != 0 || a == b)
			ans = 3;
			
		if(ans == 1)
			puts("First One");
		else if(ans == 2)
			puts("Second One");
		else puts("Confused");
	}
	
	
	return 0;
}

