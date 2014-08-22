//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1214 - Large Division
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
#define i64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

inline bool mod(char *a, i64 b)
{
    int sz = strlen(a);
    i64 d = 0;
    for(int i = 0 ; i < sz ; i++)
    {
        d = d*10 + (a[i] - '0');
        d %= b;
    }
    
    return d;
}

int main()
{
	freopen("1214 - Large Division.INP","r",stdin);
	freopen("1214 - Large Division.OUT","w",stdout);
	
	char a[205];
	i64 b;
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
	    scanf(" %s %lld ",&a,&b);
	    if(a[0] == '-')
            a[0] = '0';
	    printf("Case %d: ",t);
	    if(!mod(a,abs(b)))
            printf("divisible\n");
        else printf("not divisible\n");
	}

	return 0;
}

