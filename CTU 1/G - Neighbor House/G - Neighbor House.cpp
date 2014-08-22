//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: G - Neighbor House
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

int h[25][3];
bool vis[25];
int price[25];
int tcs,n;

void DIJ()
{
    set< pair<int,pair<int,int> > > s;
    
    int m=INF;
    int k,p;
    for(int i=0;i<n;i++)
    {
        price[i]=INF;
        vis[i]=false;
        for(int j=0;j<3;j++)
            if(h[i][j]<m)
            {
                m=h[i][j];
                k=j;
                p=i;
            }
    }
    s.insert(make_pair(m,make_pair(p,k)));
    price[p]=m;
    while(!s.empty())
    {
        pair<int,pair<int,int> > tmp=*s.begin();
        int cost=tmp.first;
        int hou=tmp.second.first;
        int c=tmp.second.second;
        s.erase(tmp);
        vis[hou]=true;
        
        for(int i=0;i<3;i++)
        {
            if(hou+1<n && !vis[hou+1] && cost+h[hou+1][i]<price[hou+1] && i!=c)
            {
                if(price[hou+1]!=INF) s.erase(make_pair(price[hou+1],make_pair(hou+1,i)));
                price[hou+1]=cost+h[hou+1][i];
                s.insert(make_pair(price[hou+1],make_pair(hou+1,i)));
            }
            if(hou-1>=0 && !vis[hou-1] && cost+h[hou-1][i]<price[hou-1] && i!=c)
            {
                if(price[hou-1]!=INF) s.erase(make_pair(price[hou-1],make_pair(hou-1,i)));
                price[hou-1]=cost+h[hou-1][i];
                s.insert(make_pair(price[hou-1],make_pair(hou-1,i)));
            }
        }
    }
}

int main()
{
    freopen("G - Neighbor House.INP","r",stdin);
    freopen("G - Neighbor House.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        for(int i=0;i<n;i++)
            scanf(" %d %d %d ",&h[i][0],&h[i][1],&h[i][2]);
        if(n==2)
        {
            int res=0;
            for(int i=0;i<n;i++)
            {
                int m=INF;
                for(int j=0;j<3;j++)
                    m=min(m,h[i][j]);
                res+=m;
            }
            printf("Case %d: %d\n",t,res);
            continue;
        }
        DIJ();
        int res=-INF;
        for(int i=0;i<n;i++)
            res=max(res,price[i]);
        printf("Case %d: %d\n",t,res);
    }
    return 0;
}
