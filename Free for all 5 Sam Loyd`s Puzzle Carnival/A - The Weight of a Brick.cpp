//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: A - The Weight of a Brick
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
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

int gcd(int a,int b)
{
    if(b%a==0) return a;
    return gcd(b%a,a);
}

int main()
{
    //freopen("A - The Weight of a Brick.INP","r",stdin);
    //freopen("A - The Weight of a Brick.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        char t1[15],t2[15];
        long long a,b,c,d;
        scanf(" %s %s ",&t1,&t2);
        sscanf(t1,"%lld/%lld",&a,&b);
        sscanf(t2,"%lld/%lld",&c,&d);
        
        long long u = c*b;
        long long v = b*d - a*d;
        printf("Case %d: ",t);
        if(u % v == 0)
            printf("%lld\n",u/v);
        else
        {
            long long k = gcd(min(u,v),max(u,v));
            printf("%lld/%lld\n",u/k,v/k);
        }
    }
    return 0;
}
