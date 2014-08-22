//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1010 - Knights in Chessboard
// Verdict: Accepted
//******************************************************************

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    freopen("1010 - Knights in Chessboard.INP","r",stdin);
    freopen("1010 - Knights in Chessboard.OUT","w",stdout);

    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        int n,m;
        scanf(" %d %d ",&n,&m);
        if(n > m)
            swap(n,m);

        int ans;
        
        if(n == 1)
            ans = m*n;
        else if(n == 2)
        {
            ans = (m+1)/4;
            ans *= 4;
            if(m % 4 == 1)
                ans += 2;
            else if(m % 4 == 2)
                ans += 4;
        }
        else ans = (m*n+1)/2;

        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}
