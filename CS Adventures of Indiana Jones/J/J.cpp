//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: J
// Verdict:
//******************************************************************
#include <iostream>
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
#define INF 999999999
#define PI 3,1415926535

using namespace std;

int tcs;
int n,m,D,u,v,w1,w2;
vector< pair<int, pair<int,int> > > data[10005];
int d[1005][2];
bool vis[1005][2];

int dij()
{
    for(int i=0;i<n;i++)
    {
        vis[i][0]=vis[i][1]=false;
        d[i][0]=d[i][1]=INF;
    }
    d[0][0]=0;
    set< pair<int, pair<int,int> > > s;
    s.insert(make_pair(0,make_pair(0,0)));
    while(!s.empty())
    {
        pair<int, pair<int,int> > tmp=*s.begin();
        int dist=tmp.first;
        int pos=tmp.second.first;
        int man=tmp.second.second;
        vis[pos][man]=true;
        s.erase(tmp);
        if(pos==n-1) break;
        for(int i=0;i<data[pos].size();i++)
        {
            int p=data[pos][i].first;
            int tmpd[2];
            tmpd[0]=data[pos][i].second.first;
            tmpd[1]=data[pos][i].second.second;
            for(int j=0;j<2;j++)
            {
                int k=dist+tmpd[j];
                if(man!=j)
                    k+=D;
                if(!vis[p][j] && k<d[p][j])
                {
                    if(d[p][j]!=INF)
                        s.erase(make_pair(d[p][j],make_pair(p,j)));
                    d[p][j]=k;
                    s.insert(make_pair(d[p][j],make_pair(p,j)));
                }
            }
        }
    }
    int ans=min(d[n-1][0],d[n-1][1]);
    return ans;
}

int main()
{
    //freopen("J.INP","r",stdin);
    //freopen("J.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf(" %d %d %d ",&n,&m,&D);
        for(int j=0;j<n;j++)
            data[j].clear();
        for(int j=0;j<m;j++)
        {
            scanf(" %d %d %d %d ",&u,&v,&w1,&w2);
            data[u].push_back(make_pair(v,make_pair(w1,w2)));
            data[v].push_back(make_pair(u,make_pair(w1,w2)));
        }
        printf("Case %d: %d\n",i,dij());
    }
    return 0;
}
