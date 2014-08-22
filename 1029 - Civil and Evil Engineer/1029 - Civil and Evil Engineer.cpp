//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1029 - Civil and Evil Engineer
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
#define pf push_front
#define maxN 12000
#define INF 1000111222

using namespace std;

struct edge
{
    int u,v,w;
};

edge e[maxN+5];
int lab[105];
int n;

inline bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int getRoot(int u)
{
    if(lab[u] == u)
        return u;
    return lab[u] = getRoot(lab[u]);
}

inline int unionset(int u, int v)
{
    return lab[u] = v;
}

int main()
{
	freopen("1029 - Civil and Evil Engineer.INP","r",stdin);
	freopen("1029 - Civil and Evil Engineer.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
	    scanf(" %d ",&n);
	    int cnt = 0;
	    int u,v,w;
	    while(scanf(" %d %d %d ",&u,&v,&w))
	    {
	        if(u == 0 && v == 0 && w == 0)
                break;
            e[cnt].u = u;
            e[cnt].v = v;
            e[cnt].w = w;
            cnt++;
	    }
	    
	    for(int i = 0 ; i <= n ; i++)
            lab[i] = i;
        sort(e,e+cnt,cmp);
        
        int done = 0;
        int best = 0,worst = 0;
        for(int i = 0 ; i < cnt ; i++)
        {
            int u = getRoot(e[i].u);
            int v = getRoot(e[i].v);
            
            if(u != v)
            {
                best += e[i].w;
                done++;
                lab[u] = v;
                
                if(done == n)
                    break;
            }
        }
        
        for(int i = 0 ; i <= n ; i++)
            lab[i] = i;
        for(int i = cnt-1 ; i >= 0 ; i--)
        {
            int u = getRoot(e[i].u);
            int v = getRoot(e[i].v);
            
            if(u != v)
            {
                worst += e[i].w;
                done++;
                lab[u] = v;
                if(done == n)
                    break;
            }
        }
        
        //DEBUG(best);
        //DEBUG(worst);
        int total = best+worst;
        printf("Case %d: ",t);
        if(total % 2 == 0)
            printf("%d\n",total/2);
        else printf("%d/2\n",total);
	}
	
	return 0;
}

