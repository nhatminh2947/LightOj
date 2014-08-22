//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1055 - Going Together
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

int step[11][11][11][11][11][11];
char a[11][11];
ii A,B,C;
vii X;
int n;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

inline bool inside(int y, int x)
{
    return (1 <= y && y <= n && 1 <= x && x <= n);
}

inline bool valid(ii u)
{
    return (a[u.ff][u.ss] == '.' || a[u.ff][u.ss] == 'X');
}

inline ii go(ii u, int i)
{
    ii v = mp(u.ff + dy[i], u.ss + dx[i]);
    
    if(inside(v.ff,v.ss) && valid(v)) return v;
    return u;
}

inline bool check()
{
    int id[5];
    rep(i,3) id[i] = i;
    do
    {
        if(A == X[id[0]] && B == X[id[1]] && C == X[id[2]])
            return true;
    }
    while(next_permutation(id,id+3));
    
    return false;
}

inline int BFS()
{
    memset(step,-1,sizeof(step));
    queue< pair<ii, pair<ii,ii> > > q;
    q.push(mp(A,mp(B,C)));
    step[A.ff][A.ss][B.ff][B.ss][C.ff][C.ss] = 0;
    
    while(!q.empty())
    {
        pair<ii, pair<ii,ii> > p = q.front();
        
        A = p.ff;
        B = p.ss.ff;
        C = p.ss.ss;
        
        if(check()) return step[A.ff][A.ss][B.ff][B.ss][C.ff][C.ss];
        
        q.pop();
        
        rep(i,4)
        {
            ii AA,BB,CC;
            AA = go(A,i);
            BB = go(B,i);
            CC = go(C,i);
            
            if(AA == BB)
            {
                if(AA == CC)
                    CC = C;
                AA = A;
                BB = B;
            }
            
            if(AA == CC)
            {
                AA = A;
                CC = C;
            }
            
            if(BB == CC)
            {
                BB = B;
                CC = C;
            }
            
            if(step[AA.ff][AA.ss][BB.ff][BB.ss][CC.ff][CC.ss] == -1)
            {
                step[AA.ff][AA.ss][BB.ff][BB.ss][CC.ff][CC.ss] = step[A.ff][A.ss][B.ff][B.ss][C.ff][C.ss] + 1;
                q.push(mp(AA,mp(BB,CC)));
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1055 - Going Together.INP","r",stdin);
    freopen("1055 - Going Together.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d ",&n);
        X.clear();
        fr(i,1,n)
        {
            gets(a[i]+1);
            
            fr(j,1,n)
                if(a[i][j] == 'A')
                {
                    A = mp(i,j);
                    a[i][j] = '.';
                }
                else if(a[i][j] == 'B')
                {
                    B = mp(i,j);
                    a[i][j] = '.';
                }
                else if(a[i][j] == 'C')
                {
                    C = mp(i,j);
                    a[i][j] = '.';
                }
                else if(a[i][j] == 'X')
                    X.pb(mp(i,j));
        }
        
        int ans = BFS();
        printf("Case %d: ",t);
        if(ans != -1) printf("%d\n",ans);
        else puts("trapped");
    }
    
    return 0;
}
