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
    int x,y;
}coor;

coor d[50005];
int tcs,n,w;

bool cmp(coor a,coor b)
{
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}

int main()
{
    //freopen("B.INP","r",stdin);
    //freopen("B.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d %d ",&n,&w);
        for(int i=0;i<n;i++)
            scanf(" %d %d ",&d[i].x,&d[i].y);
        sort(d,d+n,cmp);
        int y=d[0].y;
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            if(d[i].y-y>w)
            {
                y=d[i].y;
                cnt++;
            }
        }
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
