//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: K - I hate Prime
// Verdict: Accepted
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
int n;
bool check[60005];

void sieve()
{
    for(int i=0;i<=60000;i++)
        check[i]=true;
    check[1]=check[0]=false;
    for(long long i=2;i<=60000;i++)
    {
        if(check[i])
        {
            for(long long j=2;j*i<=60000;j++)
                check[i*j]=false;
        }
    }
}

int main()
{
    //freopen("K.INP","r",stdin);
    //freopen("K.OUT","w",stdout);
    sieve();
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        int a,b;
        printf("Case %d: ",t);
        scanf(" %d %d ",&a,&b);
        if(a>b) swap(a,b);
        int cnt=0;
        for(int i=a;i<=b;i++)
        {
            if(check[i]) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
