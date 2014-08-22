//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: G
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
int a,b,n,m,k;

int F(int i)
{
    if(i==0) return a%k;
    if(i==1) return b%k;
    return (F(i-1)%k+F(i-2)%k)%k;
}

int main()
{
    freopen("G.INP","r",stdin);
    freopen("G.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d: ",t);
        k=1;
        scanf(" %d %d %d %d ",&a,&b,&n,&m);
        for(int i=0;i<m;i++)
            k*=10;
        int res=F(n);
        printf("%d\n",res);
    }
    return 0;
}
