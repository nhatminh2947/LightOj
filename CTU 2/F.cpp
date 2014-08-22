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

int tcs;
int res[10000005];
int q;

void solve()
{
    for(int i=1;i<=10000000;i++)
    {
        res[i]=0;
        if(i%5==0)
        {
            int k=5;
            int cnt=0;
            while(k<=i)
            {
                cnt++;
                k*=5;
            }
            res[i]=res[i-1]+cnt;
        }
        else res[i]=res[i-1];
    }
    cout<<res[10000000]<<endl;
}

int main()
{
    freopen("F.INP","r",stdin);
    freopen("F.OUT","w",stdout);
    solve();
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&q);
    }
    return 0;
}
