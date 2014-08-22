//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: C - Brush (III)
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
#define INF 1000000005
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

typedef struct
{
    int x,y;
}coor;

coor p[105];
int tcs,n,w,k;
int part[150];

bool cmp(coor a, coor b)
{
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}

bool cmpd(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("C.INP","r",stdin);
    freopen("C.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d %d %d ",&n,&w,&k);
        for(int i=0;i<n;i++)
            scanf(" %d %d ",&p[i].x,&p[i].y);
        
        sort(p,p+n,cmp);
        
        for(int i=0;i<=n;i++)
            part[i]=1;
        
        int cnt=0;
        int cur=p[0].y;
        
        for(int i=0;i<n;i++)
        {
            if(cur==p[i].y)
                part[cnt]++;
            else
            {
                cnt++;
                cur=p[i].y;
            }
        }
        cnt++;
        
        sort(part,part+cnt,cmpd);
        int ans=0;
        for(int i=0;i<k && i<cnt;i++)
            ans+=part[i];
        
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
