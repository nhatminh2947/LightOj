//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: J - How Cow
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

int lf,rg,up,down;
int tcs;

bool check(int x,int y)
{
    return (lf<=x && x<=rg && down<=y && y<=up);
}

int main()
{
    //freopen("J.INP","r",stdin);
    //freopen("J.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d:\n",t);
        scanf(" %d %d %d %d ",&lf,&down,&rg,&up);
        int m;
        scanf(" %d ",&m);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf(" %d %d ",&x,&y);
            if(check(x,y))
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
