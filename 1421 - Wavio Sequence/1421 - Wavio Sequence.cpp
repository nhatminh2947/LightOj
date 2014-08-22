//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1421 - Wavio Sequence
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
int a[maxN+5];
vi LIS,LDS;
int dpLIS[maxN+5],dpLDS[maxN+5];

bool cmp(int u, int v)
{
    return u > v;
}

int solve()
{
    vi::iterator it;
    fr(i,1,n)
    {
        it = lower_bound(all(LIS),a[i]);
        dpLIS[i] = (int)(it - LIS.begin());
        
        if(it == LIS.end()) LIS.pb(a[i]);
        else *it = a[i];
    }
    
    reverse(a+1,a+n+1);
    
    fr(i,1,n)
    {
        it = lower_bound(all(LDS),a[i]);
        dpLDS[i] = (int)(it - LDS.begin());
        
        if(it == LDS.end()) LDS.pb(a[i]);
        else *it = a[i];
    }
    reverse(dpLIS+1,dpLIS+n+1);
    
    int ans = 0;
    fr(i,1,n) ans = max(ans,min(dpLDS[i],dpLIS[i])*2+1);
    
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1421 - Wavio Sequence.INP","r",stdin);
    freopen("1421 - Wavio Sequence.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        LIS.clear();
        LDS.clear();
        
        fr(i,1,n) scanf(" %d ",&a[i]);
        
        printf("Case %d: %d\n",t,solve());
    }
    
    return 0;
}
