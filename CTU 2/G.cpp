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

typedef struct
{
    long long a,b,c,d;
}matrix;
int tcs;
int m;
long long f1,f0,n,k;
matrix A,tmp,res;

matrix solve(int i)
{
    if(i==1 || i==0) return A;
    matrix M;
    if(i%2==0)
    {
        M=solve(i/2);
        tmp.a=(((M.a%k)*(M.a%k))%k+((M.b%k)*(M.c%k))%k)%k;
        tmp.b=(((M.a%k)*(M.b%k))%k+((M.b%k)*(M.d%k))%k)%k;
        tmp.c=(((M.c%k)*(M.a%k))%k+((M.d%k)*(M.c%k))%k)%k;
        tmp.d=(((M.c%k)*(M.b%k))%k+((M.d%k)*(M.d%k))%k)%k;
        return tmp;
    }
    else
    {
        M=solve(i-1);
        tmp.a=(((M.a%k)*(A.a%k))%k+((M.b%k)*(A.c%k))%k)%k;
        tmp.b=(((M.a%k)*(A.b%k))%k+((M.b%k)*(A.d%k))%k)%k;
        tmp.c=(((M.c%k)*(A.a%k))%k+((M.d%k)*(A.c%k))%k)%k;
        tmp.d=(((M.c%k)*(A.b%k))%k+((M.d%k)*(A.d%k))%k)%k;
        return tmp;
    }
}

int main()
{
    //freopen("G.INP","r",stdin);
    //freopen("G.OUT","w",stdout);
    
        A.a=1;
        A.b=1;
        A.c=1;
        A.d=0;
    
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d: ",t);
        scanf(" %lld %lld %lld %d ",&f0,&f1,&n,&m);
        
        k=1;
        for(int i=0;i<m;i++)
            k*=10;
        if(n==0)
        {
            printf("%lld\n",f0%k);
            continue;
        }
        if(n==1)
        {
            printf("%lld\n",f1%k);
            continue;
        }
        
        res=solve(n-1);
        long long ans=(((res.a%k)*(f1%k))%k+((res.b%k)*(f0%k))%k)%k;
        cout<<ans<<endl;
    }
    return 0;
}
