//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1041 - Road Construction
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
#define pf push_front
#define maxN 50
#define INF 1000111222

using namespace std;

struct edge
{
    int u,v,w;
};

map<string,int> c;
edge e[maxN+5];
int lab[500];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int getRoot(int u)
{
    if(lab[u] == u)
        return u;
    return lab[u] = getRoot(lab[u]);
}

int main()
{
	freopen("1041 - Road Construction.INP","r",stdin);
	freopen("1041 - Road Construction.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
	    int m;
	    scanf(" %d ",&m);
	    int n = 0;
	    c.clear();
	    for(int i = 0 ; i < m ; i++)
	    {
	        string u,v;
	        cin >> u >> v;
	        scanf(" %d ",&e[i].w);
	        if(!c[u])
                c[u] = ++n;
            if(!c[v])
                c[v] = ++n;
            
            e[i].u = c[u];
            e[i].v = c[v];
	    }
	    
	    sort(e,e+m,cmp);
	    for(int i = 1 ; i <= n ; i++)
            lab[i] = i;
        
        int done = 0;
        int cost = 0;
        for(int i = 0 ; i < m ; i++)
        {
            int u = getRoot(lab[e[i].u]);
            int v = getRoot(lab[e[i].v]);
            
            if(u != v)
            {
                cost += e[i].w;
                lab[u] = v;
                done++;
                
                if(done == n-1)
                    break;
            }
        }
        
        printf("Case %d: ",t);
        if(done == n-1)
            printf("%d\n",cost);
        else printf("Impossible\n");
	}

	return 0;
}

