//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1032 - Fast Bit Calculations
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
ll p[35];
ll dp[35];

int preCal()
{
    p[0] = 1;
    fr(i,1,31) p[i] = p[i-1]*2;
    
    dp[0] = 0;
    fr(i,1,30)
    {
        dp[i] = dp[i-1]*2 + p[i-1];
        //DEBUG(dp[i]);
    }
}

ll solve(int n)
{
    if(n < 3) return 0;
    if(n == 3) return 1;
    
    
}

void printBit(int n)
{
    if(n == 0)
    {
        return;
    }
    printBit(n/2);
    printf("%d",n%2);
}

int test(int t)
{
    int ans = 0;
        int m = 0;
        for(int i = 0 ; i <= t ; i++)
        {
            for(int k = 0 ; k <= 30 ; k++)
            {
                int a = 1 << k;
                int b = 1 << (k+1);
                
                a &= i;
                b &= i;
                
                if(a && b)
                {
                    ans++;
                }
            
                if(i == t)
                {
                    //DEBUG(a);
                    if(a) m = k;
                }
            }
        }
        //DEBUG(m);
        printf("p[%2d] = %5d ",m,p[m]);
        printf("t = %5d ans = %5d bit = ",t,ans);
        printBit(t);
        puts("");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1032 - Fast Bit Calculations.INP","r",stdin);
    freopen("1032 - Fast Bit Calculations.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    preCal();
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        
        test(n);
    }
    
    
    return 0;
}
