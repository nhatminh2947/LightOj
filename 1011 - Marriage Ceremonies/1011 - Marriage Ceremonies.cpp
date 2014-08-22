//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1011 - Marriage Ceremonies
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

int a[20][20];
int dp[20][70000];
int n;

int solve(int i, int b)
{
    if(i == n) return 0;
    
    if(dp[i][b] != -1) return dp[i][b];
    
    int ans = 0;
    
    rep(j,n)
    {
        int k = 1 << j;
        if(k & b) continue;
        ans = max(ans,a[i][j] + solve(i+1,b | k));
    }
    
    return dp[i][b] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1011 - Marriage Ceremonies.INP","r",stdin);
    freopen("1011 - Marriage Ceremonies.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        
        rep(i,n)
            rep(j,n)
                scanf(" %d ",&a[i][j]);
        
        int k = 1 << n;
        rep(i,n)
            rep(j,k)
                dp[i][j] = -1;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                
            }
        }
                
        printf("Case %d: %d\n",t,solve(0,0));
    }
    
    return 0;
}
