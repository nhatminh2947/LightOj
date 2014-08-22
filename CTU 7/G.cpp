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
bool check[10000005];
vector<int> primes;
int n;

void sieve()
{
    for(int i=0;i<=10000000;i++)
        check[i]=true;
    check[0]=check[1]=false;
    for(long long i=2;i<=10000000;i++)
    {
        if(check[i])
        {
            primes.push_back(i);
            for(long long j=2;i*j<=10000000;j++)
                check[i*j]=false;
        }
    }
    //cout<<primes.size();
}


int main()
{
    freopen("G.INP","r",stdin);
    freopen("G.OUT","w",stdout);
    sieve();
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        int sz=primes.size();
        int k=n/2;
        int cnt=0;
        for(int i=0;primes[i]<=k;i++)
        {
            if(check[n-primes[i]])
                cnt++;
        }
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
