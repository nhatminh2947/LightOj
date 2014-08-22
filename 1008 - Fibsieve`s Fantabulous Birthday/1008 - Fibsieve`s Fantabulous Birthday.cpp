//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1008 - Fibsieve`s Fantabulous Birthday
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



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1008 - Fibsieve`s Fantabulous Birthday.INP","r",stdin);
    freopen("1008 - Fibsieve`s Fantabulous Birthday.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    ll n;
    fr(t,1,tcs)
    {
        scanf(" %lld ",&n);
        
        ll lo = 1;
        ll hi = 4*1e7;
        ll m;
        while(lo <= hi)
        {
            ll mid = (lo+hi)>>1;
            
            if(mid*mid >= n)
            {
                hi = mid - 1;
                m = mid;
            }
            else lo = mid + 1;
        }
        
        //DEBUG(m);
        ll tmp = (m*m + (m-1)*(m-1)+1)/2;
        ll x,y;
        //DEBUG(tmp);
        if(n >= tmp && m%2 == 0)
        {
            x = m;
            y = (m - abs(tmp - n));
        }
        else if(n <= tmp && m%2 == 0)
        {
            y = m;
            x = (m - abs(tmp - n));
        }
        else if(n >= tmp && m%2 == 1)
        {
            y = m;
            x = (m - abs(tmp-n));
        }
        else if(n <= tmp && m%2 == 1)
        {
            x = m;
            y = (m - abs(tmp - n));
        }
        
        printf("Case %d: %lld %lld\n",t,x,y);
    }
    
    return 0;
}
