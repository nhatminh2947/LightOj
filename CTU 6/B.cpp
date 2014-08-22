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

int n,m,k,d;
int tcs;
int dist[20005];
bool vis[20005];
vector< pair<int,int> > city[20005];
vector< pair<int,int> > prop[10005];

void dij()
{
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        vis[i]=false;
    }
    set< pair<int,int> > s;
    s.insert( make_pair(0,0) );
    
    while(!s.empty())
    {
        pair<int,int> tmp=*s.begin();
        int dis=tmp.first;
        int pos=tmp.second;
        
        s.erase(tmp);
        vis[pos]=true;
        int sz=city[pos].size();
        for(int i=0;i<sz;i++)
        {
            int d=dis+city[pos][i].second;
            int p=city[pos][i].first;
            if(!vis[p] && d<dist[i])
            {
                if(dist[i]!=INF) s.erase(make_pair(dist[i],p));
                dist[i]=d;
                s.insert(d,p);
            }
        }
    }
}

int solve()
{
    for(int i=0;i<k;i++)
    return cnt;
}

int main()
{
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    int u,v,w;
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d %d %d %d ",&n,&m,&k,&d);
        for(int i=0;i<m;i++)
        {
            scanf(" %d %d ",&u,&v,&w);
            city[u].push_back(make_pair(v,w));
            city[v].push_back(make_pair(u,w));
        }
        
        for(int j=0;j<k;j++)
        {
            scanf(" %d %d ",&u,&v,&w);
            prop[u].push_back(make_pair(v,w));
            prop[v].push_back(make_pair(u,w));
        }
        
        
    }
    return 0;
}
