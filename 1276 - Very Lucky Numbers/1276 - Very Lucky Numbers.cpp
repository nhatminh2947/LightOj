//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1276 - Very Lucky Numbers
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

vector<ull> ans, a;

void gen(int i, ull n)
{
    if(i >= sz(a)) return;
    if(1000000000000ULL / a[i] < n) return;
    
    ull m = 1;
    while(i < sz(a))
    {
        if(n*m > 1000000000000ULL) break;
        
        ans.pb(n*m);
        gen(i+1,n*m);
        m *= a[i];
    }
    
    return;
}

void preCal()
{
    rep(i,(1<<12))
    {
        ull n = 0;
        rep(j,12)
        {
            if((1<<j)&i) n = n*10 + 7;
            else n = n*10 + 4;
            
            a.pb(n);
        }
    }
    
    sort(all(a));
    vector<ull>::iterator it = unique(all(a));
    a.resize(distance(a.begin(),it));
    
    gen(0,1);
    
    sort(all(ans));
    it = unique(all(ans));
    ans.resize(distance(ans.begin(),it));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1276 - Very Lucky Numbers.INP","r",stdin);
    freopen("1276 - Very Lucky Numbers.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    preCal();
    
    fr(t,1,tcs)
    {
        ll a, b;
        read2(a,b);
        
        int p1 = lower_bound(ans.begin()+1,ans.end(),a) - ans.begin();
        int p2 = upper_bound(ans.begin()+1,ans.end(),b) - ans.begin();
        
        printf("Case %d: %d\n",t,p2 - p1);
    }
    
    return 0;
}

