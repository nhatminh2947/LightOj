//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1231 - Coin Change (I)
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

int n;
int a[55],c[55];
int dp[55][1005];

const int mod = 100000007;

int solve(int p, int sum)
{
    if(p == n+1)
    {
        if(sum == 0) return 1;
        return 0;
    }
    
    if(dp[p][sum] != -1) return dp[p][sum];
    
    int ans = 0;
    for(int i = 0 ; i <= c[p] ; i++)
    {
        if(sum - a[p]*i >= 0)
        {
            ans += solve(p+1,sum-a[p]*i)%mod;
            ans %= mod;
        }
    }
    
    return dp[p][sum] = ans%mod;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1231 - Coin Change (I).INP","r",stdin);
    freopen("1231 - Coin Change (I).OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        int sum;
        scanf(" %d %d ",&n,&sum);
        
        fr(i,1,n) scanf(" %d ",&a[i]);
        fr(i,1,n) scanf(" %d ",&c[i]);
        
        fr(i,1,n) fr(j,0,sum) dp[i][j] = -1;
        
        printf("Case %d: %d\n",t,solve(1,sum)%mod);
    }
    
    return 0;
}
