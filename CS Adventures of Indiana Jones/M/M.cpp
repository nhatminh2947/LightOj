//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: M - The Grail Trials (III)
// Verdict:
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

vector<int> F;
int a,b,x,y;
long long n;
int tcs;

long long fn()
{
    F.clear();
    F.push_back(a);
    F.push_back(b);
    for(int i=2;i<n;i++)
    {
        F.push_back((x*F[i-1]+y*F[i-2])%1000);
    }
    return F[n-1];
}

int main()
{
    freopen("M.INP","r",stdin);
    freopen("M.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int i=1;i<=tcs;i++)
    {
        scanf(" %d %d %d %d %lld ",&a,&b,&x,&y,&n);
        int res=fn()%1000;
        int tmp=res;
        int len=0;
        while(tmp)
        {
            len++;
            tmp/=10;
        }
        printf("Case %d: ",i);
        for(int j=0;j<3-len;j++)
            printf("0");
        printf("%d\n",res);
    }
    return 0;
}
