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

vector<int> lucky;

void sieve()
{
	vector<int> v;
	
	for(int i = 1 ; i <= 2000000 ; i += 2)
		lucky.pb(i);
	
	int sz = lucky.size();
	for(int i = 0 ; i < sz ; i++)
		if((i+1)%3 != 0)
			v.pb(lucky[i]); 
	
	sz = v.size();
	lucky.clear();
	for(int i = 0 ; i < sz ; i++)
		if((i+1)%7 != 0)
			lucky.pb(v[i]);
		
}

int main()
{
	freopen("1097 - Lucky Number.INP","r",stdin);
	freopen("1097 - Lucky Number.OUT","w",stdout);
	sieve();
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		int n;
		scanf(" %d ",&n);
		printf("Case %d: %d\n",t,lucky[n-1]);
	}
	return 0;
}

