//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1040 - Donation
// Verdict: Accepted
//******************************************************************

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define DEBUG(x) cout << #x << " = " << x << endl

using namespace std;

struct edge
{
    int u,v,w;
};

edge e[2505];
int lab[100];

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
    freopen("1040 - Donation.INP","r",stdin);
    freopen("1040 - Donation.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int n;
        int ans = 0;
        int cnt = 0;
        scanf(" %d ",&n);
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
            {
                int val;
                scanf(" %d ",&val);
                if(val != 0)
                {
                    if(i == j)
                    {
                        ans += val;
                        continue;
                    }
                    e[cnt].u = i;
                    e[cnt].v = j;
                    e[cnt].w = val;
                    ans += val;
                    cnt++;
                }
            }
        
        for(int i = 1 ; i <= n ; i++)
            lab[i] = i;
        sort(e,e+cnt,cmp);
        
        int done = 0;
        for(int i = 0 ; i < cnt ; i++)
        {
            int u = getRoot(e[i].u);
            int v = getRoot(e[i].v);
            int w = e[i].w;
            
            if(u != v)
            {
                unionset(u,v);
                ans -= w;
                done++;
            }
            
            if(done == n-1)
                break;
        }
        
        printf("Case %d: ",t);
        if(done == n-1)
            printf("%d\n",ans);
        else printf("-1\n");
    }
    
    return 0;
}
