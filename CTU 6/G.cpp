//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:
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

int tcs,n;
int data[2005];

int main()
{
    freopen("G.INP","r",stdin);
    freopen("G.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d: ",t);
        scanf(" %d ",&n);
        for(int i=1;i<=n;i++)
        {
            scanf(" %d ",&data[i]);
        }
        
        sort(data+1,data+n+1);
        
        int cnt=0;
        for(int i=1;i<=n-2;i++)
        {
            for(int l=i+1;l<=n-1;i++)
            int k=data[i]+data[i+1];
            for(int j=i+2;j<=n;j++)
            {
                if(data[j]>k)
                {
                    cnt+=(n-j+1);
                    break;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
