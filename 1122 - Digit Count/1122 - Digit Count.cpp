//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1122 - Digit Count
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

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int n,m;
int dp[15][15];
int a[15];

int solve(int p, int num)
{
    if(p == n) return 1;
    if(dp[p][num] != -1) return dp[p][num];
    
    int ans = 0;
    fr(i,1,m)
    {
        if(abs(a[num] - a[i]) <= 2)
            ans += solve(p+1,i);
    }
    
    return dp[p][num] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1122 - Digit Count.INP","r",stdin);
    freopen("1122 - Digit Count.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&m,&n);
        fr(i,1,m) scanf(" %d ",&a[i]);
        
        fr(i,1,n) fr(j,1,m) dp[i][j] = -1;
        
        int ans = 0;
        fr(i,1,m) ans += solve(1,i);
        printf("Case %d: %d\n",t,ans);
    }
    
    return 0;
}
