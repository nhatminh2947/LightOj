//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1085 - All Possible Increasing Subsequences
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
#define mod 1000000007

int tcs,n;
int a[maxN+5],b[maxN+5],BIT[maxN+5];
map<int,int> m;

void add(int x, int val)
{
    while(x <= n)
    {
        BIT[x] += val%mod;
        BIT[x] %= mod;
        x += x&-x;
    }
}

int get(int x)
{
    int total = 0;
    
    while(x > 0)
    {
        total += BIT[x]%mod;
        total %= mod;
        x -= x&-x;
    }
    
    return total;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1085 - All Possible Increasing Subsequences.INP","r",stdin);
    freopen("1085 - All Possible Increasing Subsequences.OUT","w",stdout);
    #endif
    
    scanf("%d",&tcs);
    
    fr(t,1,tcs)
    {
        scanf("%d",&n);
        
        m.clear();
        BIT[0] = 0;
        BIT[n+1] = 0;
        
        fr(i,1,n) BIT[i] = 0;
        fr(i,1,n)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b+1,b+n+1);
        
        fr(i,1,n)
            if(!m.count(b[i])) m[b[i]] = sz(m);
        
        fr(i,1,n)
        {
            a[i] = m[a[i]];
            add(a[i], (get(a[i]-1)+1) % mod);
        }
        
        printf("Case %d: %d\n",t,get(sz(m))%mod);
    }
    
    return 0;
}
