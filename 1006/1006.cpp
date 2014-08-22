//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 1006 - Hex-a-bonacci
// Verdict: Accepted
//******************************************************************
#include <iostream>
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
#define INF 999999999
#define PI 3,1415926535

using namespace std;

long long F[10005];
int tcs;
long long a,b,c,d,e,f,n;
long long res;

int fn()
{
    F[0]=a;
    F[1]=b;
    F[2]=c;
    F[3]=d;
    F[4]=e;
    F[5]=f;
    for(int i=6;i<=n;i++)
    {
        F[i]=F[i-1]+F[i-2]+F[i-3]+F[i-4]+F[i-5]+F[i-6];
        F[i]%=10000007;
    }
    return F[n];
}

int main()
{
    //freopen("1006.INP","r",stdin);
    //freopen("1006.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf(" %lld %lld %lld %lld %lld %lld %lld ",&a,&b,&c,&d,&e,&f,&n);
        if(n==0) res=a;
        else if(n==1) res=b;
        else if(n==2) res=c;
        else if(n==3) res=d;
        else if(n==4) res=e;
        else if(n==5) res=f;
        else if(n>5) res=fn();
        printf("Case %d: %lld\n",i,res%10000007);
    }
    return 0;
}
