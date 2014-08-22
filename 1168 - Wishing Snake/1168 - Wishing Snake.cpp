//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1168 - Wishing Snake
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
#define maxN 1000

const int n=1000;
int c, k;
bool exist[maxN+5], root[maxN+5], deg[maxN+5];

//for tarjan algorithm
vi a[maxN+5];
int low[maxN+5], num[maxN+5], reg[maxN+5];
int idx, nreg;
stack<int> s;

void init()
{
    s = stack<int>();
    idx = nreg = 0;
    rep(i,maxN)
    {
        a[i].clear();
        exist[i] = false;
        low[i] = num[i] = reg[i] = deg[i] = 0;
        root[i] = true;
    }
}

void tarjan(int u)
{
    low[u] = num[u] = ++idx;
    s.push(u);
    rep(i, sz(a[u]))
    {
        int v = a[u][i];
        
        if(reg[v]) continue;
        
        if(!num[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],num[v]);
    }
    
    if(low[u] == num[u])
    {
        int v;
        ++nreg;
        
        do
        {
            v = s.top();
            s.pop();
            reg[v] = nreg;
        }while(u != v);
    }
}

bool solve()
{
    rep(i,n) if(exist[i] && !num[i]) tarjan(i);
    
    rep(u,n) if(exist[u])
    {
        rep(i,sz(a[u]))
        {
            int v = a[u][i];
            
            if(reg[u] != reg[v])
            {
                if(deg[reg[u]]) return false;
                deg[reg[u]]++;
                root[reg[v]] = false;
            }
        }
    }
    
    int r = -1;
    int cnt = 0;
    fr(i,1,nreg)
    {
        if(root[i])
        {
            r = i;
            cnt++;
            if(cnt > 1) return false;
        }
    }
    
    return r == reg[0];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1168 - Wishing Snake.INP","r",stdin);
    freopen("1168 - Wishing Snake.OUT","w",stdout);
    #endif
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        init();
        
        read(c);
        
        rep(i,c)
        {
            read(k);
            rep(j,k)
            {
                int u,v;
                read2(u,v);
                exist[u] = exist[v] = true;
                a[u].pb(v);
            }
        }
        
        printf("Case %d: %s\n",t,solve() ? "YES":"NO");
    }
    
    return 0;
}

