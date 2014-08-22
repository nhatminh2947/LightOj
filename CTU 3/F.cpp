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

typedef struct
{
    string u,v;
    int c;
}edge;

int tcs,n;
map< string,int > str;
edge road[55];
int lab[55];

int getRoot(int u)
{
    if(lab[u]==u) return u;
    return lab[u]=getRoot(lab[u]);
}

int unionset(int a,int b)
{
    return lab[a]=b;
}

bool cmp(edge a,edge b)
{
    return a.c<b.c;
}

int main()
{
    freopen("F.INP","r",stdin);
    freopen("F.OUT","w",stdout);
    scanf(" %d ",&tcs);
    string a,b;
    int c;
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            cin>>road[i].u>>road[i].v>>road[i].c;
            if(!str[road[i].u])
                str[road[i].u]=cnt++;
            if(!str[road[i].v])
                str[road[i].v]=cnt++;
        }
        for(int i=0;i<=cnt;i++)
            lab[i]=i;
        sort(road,road+n,cmp);
        int M=0,cost=0;
        
        for(int i=0;i<cnt;i++)
        {
            int u=str[road[i].u];
            int v=str[road[i].v];
            int c=road[i].c;
            
            int r1=getRoot(lab[u]);
            int r2=getRoot(lab[v]);
            
            if(r1!=r2)
            {
                M++;
                cost+=c;
                unionset(r1,r2);
            }
            if(M==(n-1)) break;
        }
        printf("%d\n",cost);
    }
    return 0;
}
