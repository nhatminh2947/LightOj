//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1263 - Equalizing Money
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
#define maxN 1000

int n,m;
int a[maxN+5];
vi adj[maxN+5];
bool vis[maxN+5];
int cnt;

int DFS(int u)
{
    if(vis[u]) return 0;
    cnt++;
    vis[u] = true;
    
    int sum = a[u];
    rep(i,sz(adj[u]))
    {
        int v = adj[u][i];
        sum += DFS(v);
    }
    
    return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1263 - Equalizing Money.INP","r",stdin);
    freopen("1263 - Equalizing Money.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&m);
        
        fr(i,1,n)
        {
            scanf(" %d ",&a[i]);
            adj[i].clear();
            vis[i] = false;
        }
        
        rep(i,m)
        {
            int u,v;
            
            scanf(" %d %d ",&u,&v);
            
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        bool yes = true;
        set<int> s;
        fr(i,1,n)
        {
            if(!vis[i])
            {
                cnt = 0;
                int sum = DFS(i);
                
                if(sum%cnt)
                {
                    yes = false;
                    break;
                }
                
                s.insert(sum/cnt);
            }
        }
        
        printf("Case %d: ",t);
        if(yes && sz(s) == 1) puts("Yes");
        else puts("No");
    }
    
    return 0;
}
