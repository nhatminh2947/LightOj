//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1109 - False Ordering
// Verdict: Accepted
//******************************************************************

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int nDiv[1005];
int ans[1005];

bool cmp(int a, int b)
{
    if(nDiv[a] == nDiv[b])
        return a > b;
    return nDiv[a] < nDiv[b];
}

int main()
{
    freopen("1109 - False Ordering.INP","r",stdin);
    freopen("1109 - False Ordering.OUT","w",stdout);
    
    int tcs;
    scanf(" %d ",&tcs);
    
    for(int i = 1 ; i <= 1000 ; i++)
    {
        nDiv[i] = 0;
        ans[i] = i;
        for(int j = 1 ; j <= i ; j++)
            if(i%j == 0)
                nDiv[i]++;
    }
    
    sort(ans+1,ans+1001,cmp);
    
    for(int t = 1 ; t <= tcs ; t++)
    {
        int n;
        scanf(" %d ",&n);
        printf("Case %d: %d\n",t,ans[n]);
    }
    
    return 0;
}
