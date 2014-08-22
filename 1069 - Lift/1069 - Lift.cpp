//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1069 - Lift
// Verdict: Accepted
//******************************************************************

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("1069 - Lift.INP","r",stdin);
    freopen("1069 - Lift.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int pos,lift;
        scanf(" %d %d ",&pos,&lift);
        
        int n = abs(pos - lift);
        int s = 4*n;
        
        s += 3 + 5 + 3;
        s += pos*4;
        s += 3 + 5;
        
        printf("Case %d: %d\n",t,s);
    }
    
    return 0;
}
