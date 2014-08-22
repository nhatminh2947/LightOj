//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1037 - Agent 47
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

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

const int dx[] = {-1, 0, 0, 1};
const int dy[] = { 0,-1, 1, 0};

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 20

int n;
int a[maxN+5], d[maxN+5][maxN+5];
int dp[maxN+5][40000];
bool check[maxN+5];

int solve(int i, int b)
{
    if(i == n)
    {
        return 0;
    }
    if(dp[i][b] != INF)
    {
        return dp[i][b];
    }
    
    for(int k = 0 ; k < n ; k++)
    {
        if((b & (1<<k)) == 0)
        {
            int m = solve(i+1, b | (1<<k));
            int dd = 1;
            for(int j = 0 ; j < n ; j++)
            {
                if((1<<j) & b)
                {
                    dd = max(dd, d[j][k]);
                }
            }

            dd = a[k] / dd + (a[k] % dd != 0);
            
            dp[i][b] = min(dp[i][b], m + dd);
        }
    }
    
    return dp[i][b];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1037 - Agent 47.INP","r",stdin);
    freopen("1037 - Agent 47.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        read(n);
        
        rep(i,n)
        {
            read(a[i]);
            fr(j,0,32768) dp[i][j] = INF;
        }
        
        rep(i,n)
        {
            string s;
            read(s);
            rep(j,n) d[i][j] = s[j] - '0';
        }
        
        dp[0][0] = INF;
        
        solve(0,0);
        
        cout << "Case " << t << ": " << dp[0][0] << endl;
    }
    
    return 0;
}


