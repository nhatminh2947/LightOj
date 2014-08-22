//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1088 - Points in Segments
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

int n,q;
int ans[maxN+5];
vi a;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1088 - Points in Segments.INP","r",stdin);
    freopen("1088 - Points in Segments.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf("%d",&tcs);
    
    fr(t,1,tcs)
    {
        scanf("%d %d",&n,&q);
        a.clear();
        rep(i,n)
        {
            int x;
            read(x);
            a.pb(x);
        }
        sort(all(a));
        
        ans[0] = a[0];
        
        printf("Case %d:\n",t);
        rep(i,q)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            
            int p1 = lower_bound(all(a),u) - a.begin();
            int p2 = upper_bound(all(a),v) - a.begin();
            
            printf("%d\n",p2 - p1);
        }
    }
    
    return 0;
}

