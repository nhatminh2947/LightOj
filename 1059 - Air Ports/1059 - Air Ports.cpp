//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1059 - Air Ports
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
#define maxN 100000
#define INF 1000111222

using namespace std;

struct edge
{
    int u,v;
    int64 w;
};

int n,m;
int64 a;
edge e[maxN+5];
int lab[10005];

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
	freopen("1059 - Air Ports.INP","r",stdin);
	freopen("1059 - Air Ports.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
	    scanf(" %d %d %lld ",&n,&m,&a);
	    
	    int cnt = 0;
        int64 cost = 0;
	    int ap = 0;
	    for(int i = 0 ; i < m ; i++)
	    {
	        int u,v;
	        int64 w;
	        scanf(" %d %d %lld ",&u,&v,&w);
	        if(w >= a)
	            continue;
	        else
	        {
	            e[cnt].u = u;
	            e[cnt].v = v;
	            e[cnt].w = w;
	            cnt++;
	        }
	    }
	    
	    sort(e,e+cnt,cmp);
	    for(int i = 1 ; i <= n ; i++)
            lab[i] = i;
        
        for(int i = 0 ; i < cnt ; i++)
        {
            int u = getRoot(lab[e[i].u]);
            int v = getRoot(lab[e[i].v]);
            
            if(u != v)
            {
                lab[u] = v;
                cost += e[i].w;
            }
        }
        
        set<int> s;
        for(int i = 2 ; i <= n ; i++)
        {
            int u = getRoot(lab[i]);
            int v = getRoot(lab[i-1]);
            if(u != v)
            {
                s.insert(u);
                s.insert(v);
            }
        }
        
        int r = 0;
        if(s.size() == 0)
            r = 1;
            
        ap += (s.size()+r);
        cost += (s.size()+r)*a;
        
        printf("Case %d: %lld %d\n",t,cost,ap);
	}
	
	return 0;
}

