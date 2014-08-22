//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: E - Civil and Evil Engineer
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

typedef struct
{
    int u,v,c;
}edge;

edge data[12010];
int lab[12010];
int tcs,n;

int getRoot(int u)
{
    if(lab[u]==u) return u;
    return lab[u]=getRoot(lab[u]);
}

int unionset(int a,int b)
{
    return lab[a]=b;
}

bool cmpi(edge a,edge b)
{
    return a.c<b.c;
}

bool cmpd(edge a,edge b)
{
    return a.c>b.c;
}


int main()
{
    //freopen("E.INP","r",stdin);
    //freopen("E.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        int cnt=0;
        scanf(" %d ",&n);
        while(scanf(" %d %d %d ",&data[cnt].u,&data[cnt].v,&data[cnt].c))
        {
            if(data[cnt].u==0 && data[cnt].v==0 && data[cnt].c==0) break;
            cnt++;
        }
        
        for(int i=0;i<=n;i++)
            lab[i]=i;
        
        sort(data,data+cnt,cmpi);
        
        int cost=0;
        int done=0;
        for(int i=0;i<cnt;i++)
        {
            int r1=getRoot(data[i].u);
            int r2=getRoot(data[i].v);
            int c=data[i].c;
            
            if(r1!=r2)
            {
                done++;
                unionset(r1,r2);
                cost+=c;
            }
            if(done==n) break;
        }
        
        //max
        
        for(int i=0;i<=n;i++)
            lab[i]=i;
        
        sort(data,data+cnt,cmpd);
        
        done=0;
        for(int i=0;i<cnt;i++)
        {
            int r1=getRoot(data[i].u);
            int r2=getRoot(data[i].v);
            int c=data[i].c;
            
            if(r1!=r2)
            {
                done++;
                unionset(r1,r2);
                cost+=c;
            }
            if(done==n) break;
        }
        
        printf("Case %d: ",t);
        if(cost%2==1) printf("%d/2",cost);
        else printf("%d",cost/2);
        printf("\n");
    }
    return 0;
}
