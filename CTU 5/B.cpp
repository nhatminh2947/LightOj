//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: B - Array Simulation
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

int tcs,n,m;
long long data[105];

int main()
{
    //freopen("B.INP","r",stdin);
   // freopen("B.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d:\n",t);
        scanf(" %d %d ",&n,&m);
        for(int i=0;i<n;i++)
            scanf(" %lld ",&data[i]);
        
        char cmd;
        long long a;
        for(int i=0;i<m;i++)
        {
            scanf(" %c ",&cmd);
            if(cmd=='S')
            {
                scanf(" %lld ",&a);
                for(int i=0;i<n;i++)
                    data[i]+=a;
            }
            else if(cmd=='M')
            {
                scanf(" %lld ",&a);
                for(int i=0;i<n;i++)
                    data[i]*=a;
            }
            else if(cmd=='D')
            {
                scanf(" %lld ",&a);
                for(int i=0;i<n;i++)
                    data[i]/=a;
            }
            else if(cmd=='R')
            {
                reverse(data,data+n);
            }
            else if(cmd=='P')
            {
                long long k;
                scanf(" %lld %lld ",&a,&k);
                swap(data[a],data[k]);
            }
        }
        printf("%lld",data[0]);
        for(int i=1;i<n;i++)
            printf(" %lld",data[i]);
        printf("\n");
    }
    return 0;
}
