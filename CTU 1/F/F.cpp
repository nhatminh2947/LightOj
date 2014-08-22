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

int tcs,n;
vector< pair<int,int> > data[30005];
bool vis[30005];

void BFS()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            vis[j]=false;
        queue< pair<int,int> > q;
        q.push(make_pair(i,0));
        vis[i]=true;
        int res=-INF;
        while(!q.empty())
        {
            int p=q.front().first;
            int d=q.front().second;
            q.pop();
            res=max(res,d);
            int sz=data[p].size();
            for(int j=0;j<sz;j++)
            {
                if(!vis[data[p][j].first])
                {
                    vis[data[p][j].first]=true;
                    q.push(make_pair(data[p][j].first,d+data[p][j].second));
                }
            }
        }
        printf("%d\n",res);
    }
}

int main()
{
    freopen("F.INP","r",stdin);
    freopen("F.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        printf("Case %d:\n",t);
        for(int i=0;i<n;i++)
            data[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            scanf(" %d %d %d ",&u,&v,&w);
            data[u].push_back(make_pair(v,w));
            data[v].push_back(make_pair(u,w));
        }
        BFS();
    }
    return 0;
}
