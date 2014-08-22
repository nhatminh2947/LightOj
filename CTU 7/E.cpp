//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: E - Array Queries
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

int tcs,q,n;
int res[1000005];
int A[1000005];

void bTree(int p,int a,int b) {
    if(a==b) {
        res[p]=A[a];
        return;
    }
    int c = p << 1, mid = (a + b) / 2;

    bTree(c,a,mid);
    bTree(c+1,mid + 1, b);
    res[p] = min(res[c], res[c + 1]);
}

int get(int p, int lf, int rg, int u, int v) {
    if (v < lf || rg < u) return INF;
    if (u <= lf && rg <= v) return res[p];
    int c = p << 1, mid = (lf + rg) / 2;
    return min(get(c, lf, mid, u, v), get(c + 1, mid + 1, rg, u, v));
}

int main()
{
//    freopen("E.INP","r",stdin);
//    freopen("E.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d:\n",t);
        scanf(" %d %d ",&n,&q);
        for(int i=0;i<n;i++)
            scanf(" %d ",&A[i]);
        bTree(1,0,n-1);
        for(int i=0;i<q;i++)
        {
            int a,b;
            scanf(" %d %d ",&a,&b);
            int k=get(1,0,n-1,a-1,b-1);
            printf("%d\n",k);
        }
    }
    return 0;
}
