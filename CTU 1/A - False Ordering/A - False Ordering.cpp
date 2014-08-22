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

typedef struct
{
    int id,n;
}num;

num divi[1005];
int tcs,n;

bool cmp(num a,num b)
{
    if(a.n<b.n) return a.id<b.id;
    if(a.n==b.n && a.id>b.id) return a.id>b.id;
    return b.id>a.id;
}

void solve()
{
    divi[1].id=1;
    divi[1].n=1;
    for(int i=2;i<=1000;i++)
    {
        divi[i].id=i;
        divi[i].n=2;
        for(int j=2;j<=i/2;j++)
            if(i%j==0) divi[i].n++;
    }
    sort(divi+1,divi+1001,cmp);
}

int main()
{
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);
    solve();
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        scanf(" %d ",&n);
        printf("%d\n",divi[n].id);
    }
    return 0;
}
