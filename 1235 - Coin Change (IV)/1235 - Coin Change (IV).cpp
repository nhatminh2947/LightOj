//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1235 - Coin Change (IV)
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

int n, k;
int a[maxN+5];
vector<ll> u,v;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1235 - Coin Change (IV).INP","r",stdin);
    freopen("1235 - Coin Change (IV).OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        u.clear();
        v.clear();
        
        read2(n,k);
        
        fr(i,1,n) read(a[i]);
        
        int m = n/2;
        n -= m;
        
        ll m3 = 1;
        ll n3 = 1;
        
        rep(i,m) m3 *= 3;
        rep(i,n) n3 *= 3;
        
        rep(i,n3)
        {
            ll p = i;
            ll sum = 0;
            int j = 1;
            
            while(p)
            {
                sum += a[j] * (p%3);
                p /= 3;
                j++;
            }
            
            u.pb(sum);
        }
        
        rep(i,m3)
        {
            ll p = i;
            ll sum = 0;
            int j = 1;
            while(p)
            {
                sum += a[j+n] * (p%3);
                p /= 3;
                j++;
            }
            
            v.pb(sum);
        }
        
        sort(all(u));
        sort(all(v));
        
        bool ok = false;
        rep(i,sz(u))
        {
            ll sum = u[i];
            
            int lf = 0;
            int rg = sz(v)-1;
            
            while(lf <= rg)
            {
                int mid = (lf+rg)/2;
                
                if(v[mid] + sum == k)
                {
                    ok = true;
                    break;
                }
                
                if(v[mid] + sum < k)
                    lf = mid + 1;
                else if(v[mid] + sum > k)
                    rg = mid - 1;
            }
            
            if(ok) break;
        }
        
        printf("Case %d: ",t);
        if(ok) puts("Yes");
        else puts("No");
    }
    
    return 0;
}
