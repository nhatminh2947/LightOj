//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1377 - Blade and Sword
// Verdict: 
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

int n,m;
char a[205][205];
map< pair< pair<int,int>, int > ,int> step;
vii tele;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

int BFS(ii st, ii ed)
{
    queue< pair< pair<int,int>, int > > q;
    step[mp(st,-1)] = 0;
    q.push(mp(st,-1));
    
    while(!q.empty())
    {
        int y = q.front().ff.ff;
        int x = q.front().ff.ss;
        int t = q.front().ss;
        printf("y = %d x = %d t = %d step = %d\n",y,x,t,step[mp(mp(y,x),t)]);
        if(ed == mp(y,x)) return step[mp(mp(y,x),t)];
        q.pop();
        
        rep(i,4)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(a[yy][xx] == '.' || a[yy][xx] == 'D' && !step.count(mp(mp(yy,xx),t)))
            {
                step[mp(mp(yy,xx),t)] = step[mp(mp(y,x),t)] + 1;
                q.push(mp(mp(yy,xx),t));
            }
            else if(a[yy][xx] == '*')
            {
                rep(j,sz(tele))
                {
                    rep(k,4)
                    {
                        int yy = tele[j].ff + dy[k];
                        int xx = tele[j].ss + dx[k];
                        int tt = j;
                        
                        if(!step.count(mp(mp(yy,xx),tt)))
                        {
                            step[mp(mp(yy,xx),tt)] = step[mp(mp(y,x),t)] + 2;
                            q.push(mp(mp(yy,xx),tt));
                        }
                    }
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1377 - Blade and Sword.INP","r",stdin);
    freopen("1377 - Blade and Sword.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        scanf(" %d %d ",&n,&m);
        fr(i,1,n) gets(a[i]+1);
        
        step.clear();
        tele.clear();
        ii st,ed;
        
        fr(i,1,n)
            fr(j,1,m)
                if(a[i][j] == '*')
                    tele.pb(mp(i,j));
                else if(a[i][j] == 'P')
                    st = mp(i,j);
                else if(a[i][j] == 'D')
                    ed = mp(i,j);
        
        int ans = BFS(st,ed);
        
        printf("Case %d: ",t);
        if(ans == -1) puts("impossible");
        else printf("%d\n",ans);
    }
    
    return 0;
}
