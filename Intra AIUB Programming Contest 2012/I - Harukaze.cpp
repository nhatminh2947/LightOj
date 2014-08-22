//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: I - Harukaze
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

char inp[100005];

int main()
{
	freopen("I - Harukaze.INP","r",stdin);
	freopen("I - Harukaze.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		printf("Case %d:\n",t);
		scanf(" %s ",&inp);
		int q;
		scanf(" %d ",&q);
		int sz = strlen(inp);
		for(int i = 0 ; i < q ; i++)
		{
			char s[5005];
			scanf(" %s ",&s);
			
			int len = strlen(s);
			int p = 0;
			for(int k = 0 ; k < sz && p < len ; k++)
				if(s[p] == inp[k])
					p++;
			
			if(p == len)
				puts("Yes");
			else puts("No");
		}
	}
	return 0;
}

