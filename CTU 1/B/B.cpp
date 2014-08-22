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

int tcs,n,k,m;
int p[105];
vector<int> data[1005];
int vis[1005];
bool check[1005];

void BFS()
{
    for(int i=1;i<=n;i++)
        vis[i]=0;
    
   
    for(int i=0;i<k;i++)
    {
        queue< int > q;
        for(int j=1;j<=n;j++)
            check[j]=false;
        q.push(p[i]);
        vis[p[i]]++;
        check[p[i]]=true;
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            int sz=data[tmp].size();
            for(int j=0;j<sz;j++)
            {
                if(!check[data[tmp][j]])
                {
                    vis[data[tmp][j]]++;
                    q.push(data[tmp][j]);
                    check[data[tmp][j]]=true;
                }
            }
        }
    }
}

int main()
{
    //freopen("B.INP","r",stdin);
    //freopen("B.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d %d %d ",&k,&n,&m);
        for(int i=0;i<n;i++)
            data[i].clear();
        for(int i=0;i<k;i++)
            scanf(" %d ",&p[i]);
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf(" %d %d ",&u,&v);
            data[u].push_back(v);
        }
        BFS();
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(vis[i]==k) cnt++;
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
