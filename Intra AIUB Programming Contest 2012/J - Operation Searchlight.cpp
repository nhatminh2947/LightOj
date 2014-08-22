//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: J - Operation Searchlight
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

int p,n,m,r;
vector< pair<int,int> > data[10005];
int dist[10005];



int main()
{
	freopen("J - Operation Searchlight.INP","r",stdin);
	freopen("J - Operation Searchlight.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		scanf(" %d %d %d %d ",&p,&m,&n,&r);
		for(int i = 0 ; i < r ; i++)
		{
			int u,v;
			scanf(" %d %d %d ",&u,&v,&w);
			data[u].pb(mp(v,w));
			data[v].pb(mp(u,w));
		}
	}
	return 0;
}

