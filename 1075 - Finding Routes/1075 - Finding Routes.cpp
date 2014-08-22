//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1075 - Finding Routes
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

map<string,int> id;
int n;

int main()
{
	freopen("1075 - Finding Routes.INP","r",stdin);
	freopen("1075 - Finding Routes.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
	    id.clear();
	    scanf(" %d ",&n);
	    for(int i = 1 ; i <= n ; i++)
            vis[
	    int cnt = 0;
	    for(int i = 0 ; i < n ; i++)
	    {
	        string u,v;
	        cin >> u >> v;
	        if(!id[u])
                id[u] = ++cnt;
            if(!id[v])
                id[v] = ++cnt;
            
            adj[id[u]].pb(id[v]);
	    }
	}

	return 0;
}

