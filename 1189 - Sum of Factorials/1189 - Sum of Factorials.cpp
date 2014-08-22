//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1189 - Sum of Factorials
// Verdict: 
//******************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#define int64 long long
#define pb push_back

using namespace std;

int64 F[25],ans[25],n;
int cnt;

int main()
{
    freopen("1189 - Sum of Factorials.INP","r",stdin);
    freopen("1189 - Sum of Factorials.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    F[0] = 1LL;
    F[1] = 1LL;
    F[2] = 2LL;
    F[3] = 6LL;
    F[4] = 24LL;
    F[5] = 120LL;
    F[6] = 720LL;
    F[7] = 5040LL;
    F[8] = 40320LL;
    F[9] = 362880LL;
    F[10] = 3628800LL;
    F[11] = 39916800LL;
    F[12] = 479001600LL;
    F[13] = 6227020800LL;
    F[14] = 87178291200LL;
    F[15] = 1307674368000LL;
    F[16] = 20922789888000LL;
    F[17] = 355687428096000LL;
    F[18] = 6402373705728000LL;
    F[19] = 121645100408832000LL;
    
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %lld ",&n);
        cnt = 0;
        for(int i = 19 ; i >= 0 && n > 0; i--)
        {
            if(n >= F[i])
            {
                n -= F[i];
                ans[cnt++] = i;
            }
        }
        
        printf("Case %d: ",t);
        if(n != 0)
            printf("impossible\n");
        else
        {
            printf("%d!",ans[cnt-1]);
            for(int i = cnt-2 ; i >= 0 ; i--)
                printf("+%d!",ans[i]);
            printf("\n");
        }
    }
    
    return 0;
}
