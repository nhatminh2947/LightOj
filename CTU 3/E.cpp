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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs,s,n,m;
bool vis[505];
int dist[505];
vector< pair<int,int> > data[505];

void Dij()
{
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
        dist[i]=INF;
    }
    set< pair<int,int> > se;
    dist[s]=0;
    se.insert(make_pair(0,s));
    while(!se.empty())
    {
        pair<int,int> tmp=*se.begin();
        int dis=tmp.first;
        int pos=tmp.second;
        vis[pos]=true;
        se.erase(tmp);
        
        int sz=data[pos].size();
        for(int i=0;i<sz;i++)
        {
            int p=data[pos][i].first;
            int d=data[pos][i].second;
            if(!vis[p] && dist[p]>d)
            {
                dist[p]=min(dist[p],max(dis,d));
                se.insert(make_pair(dist[p],p));
            }
        }
    }
}

int main()
{
    freopen("E.INP","r",stdin);
    freopen("E.OUT","w",stdout);
    scanf(" %d ",&tcs);
    int u,v,w;
    for(int t=1;t<=tcs;t++)
    {
        
        scanf(" %d %d ",&n,&m);
        for(int i=0;i<n;i++)
            data[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf(" %d %d %d ",&u,&v,&w);
            data[u].push_back(make_pair(v,w));
            data[v].push_back(make_pair(u,w));
        }
        scanf(" %d ",&s);
        Dij();
        printf("Case %d:\n",t);
        for(int i=0;i<n;i++)
        {
            if(dist[i]==INF) printf("Impossible\n");
            else printf("%d\n",dist[i]);
        }
    }
    return 0;
}
