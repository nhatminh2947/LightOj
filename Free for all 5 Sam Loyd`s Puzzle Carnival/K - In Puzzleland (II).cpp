//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: K - In Puzzleland
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

void solve(long long n)
{
    if(n == 0) return;
    solve(n/6);
    printf("%lld",n%6);
}

int main()
{
    //freopen("K - In Puzzleland (II).INP","r",stdin);
    //freopen("K - In Puzzleland (II).OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        printf("Case %d: ",t);
        long long n;
        scanf(" %lld ",&n);
        if(n == 0)
        {
            printf("0\n");
            continue;
        }
        solve(n);
        printf("\n");
    }
    return 0;
}
