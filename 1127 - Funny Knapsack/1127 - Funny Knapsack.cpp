//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1127 - Funny Knapsack
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
#define maxN 100000

int n, w;
vector<ll> a;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1127 - Funny Knapsack.INP","r",stdin);
    freopen("1127 - Funny Knapsack.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    fr(t,1,tcs)
    {
        read2(n,w);
        a.clear();
        
        rep(i,n) 
        {
            ll x;
            read(x);
            a.pb(x);
        }
        
        sort(all(a));
        
        int k = n/2;
        vector<ll> u, v;
        rep(i,(1<<k))
        {
            ll sum = 0;
            rep(j,k)
            {
                if(i & (1<<j))
                    sum += a[j];
            }
            
            u.pb(sum);
        }
        
        int l = n - k;
        fr(i,1,(1<<l)-1)
        {
            ll sum = 0;
            rep(j,l)
            {
                if(i & (1<<j))
                    sum += a[j+k];
            }
            
            v.pb(sum);
        }
        
        sort(all(u));
        sort(all(v));
        
        int ans = 0;
        
        rep(i,sz(u))
        {
            int lf = 0;
            int rg = sz(v)-1;
            int pos = -1;
            
            while(lf <= rg)
            {
                ll mid = (lf+rg)/2;
                
                if(v[mid] + u[i] <= w)
                {
                    pos = mid;
                    lf = mid + 1;
                }
                else rg = mid - 1;
            }
            
            
            if(pos == -1) continue;
            ans += pos+1;
            
        }
        
        int lf = 0;
        int rg = sz(u)-1;
        int pos = -1;
        
        while(lf <= rg)
        {
            ll mid = (lf+rg)/2;
            
            if(u[mid] <= w)
            {
                pos = mid;
                lf = mid + 1;
            }
            else rg = mid - 1;
        }
        
        ans += pos+1;
        
        printf("Case %d: %d\n",t,ans);
    }
    
    return 0;
}


