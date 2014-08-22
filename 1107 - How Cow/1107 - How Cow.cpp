//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1107 - How Cow
// Verdict: Accepted
//******************************************************************

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int x[5],y[5];

int main()
{
    freopen("1107 - How Cow.INP","r",stdin);
    freopen("1107 - How Cow.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d %d %d %d ",&x[1],&y[1],&x[2],&y[2]);
        int m;
        scanf(" %d ",&m);
        printf("Case %d:\n",t);
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            scanf(" %d %d ",&a,&b);
            if(x[1] < a && a < x[2] && y[1] < b && b < y[2])
                puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}
