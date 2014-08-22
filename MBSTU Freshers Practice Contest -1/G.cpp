//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: G - Chocolate Thief
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
    int sz;
    char name[25];
}chocolate;

int tcs;
int n;
chocolate data[105];

int main()
{
    //freopen("G.INP","r",stdin);
    //freopen("G.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            scanf(" %s %d %d %d ",&data[i].name,&x,&y,&z);
            data[i].sz=x*y*z;
        }
        int mx=-INF,mn=INF;
        int x,y;
        for(int i=0;i<n;i++)
        {
            if(mx<data[i].sz)
            {
                x=i;
                mx=data[i].sz;
            }
            if(mn>data[i].sz)
            {
                y=i;
                mn=data[i].sz;
            }
        }
        printf("Case %d: ",t);
        if(mx==mn)
            printf("no thief\n");
        else
            printf("%s took chocolate from %s\n",data[x].name,data[y].name);
    }
    return 0;
}
