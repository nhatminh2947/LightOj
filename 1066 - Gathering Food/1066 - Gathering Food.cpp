//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1066 - Gathering Food
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
#define maxN 10

int n;
char a[12][12];
int step[12][12];
ii pos[25];

bool inside(int y, int x)
{
    return (0 <= y && y < n && 0 <= x && x < n);
}

int BFS(int k)
{
    rep(i,11) rep(j,11) step[i][j] = -1;
    queue<ii> q;
    step[pos[k].ff][pos[k].ss] = 0;
    q.push(pos[k]);
    
    while(!q.empty())
    {
        int y = q.front().ff;
        int x = q.front().ss;
        a[y][x] = '.';
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(inside(yy,xx) && a[yy][xx] == '.' && step[yy][xx] == -1)
            {
                q.push(mp(yy,xx));
                step[yy][xx] = step[y][x] + 1;
            }
            else if(mp(yy,xx) == pos[k+1])
                return step[y][x] + 1;
        }
    }
    
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1066 - Gathering Food.INP","r",stdin);
    freopen("1066 - Gathering Food.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {        
        read(n);
        
        rep(i,n) read(a[i]);
        
        int cnt = 0;
        rep(i,n) rep(j,n)
        {
            if('A' <= a[i][j] && a[i][j] <= 'Z')
            {
                pos[a[i][j]-'A'] = mp(i,j);
                cnt++;
            }
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < cnt-1 ; i++)
        {
            int k = BFS(i);
            
            if(!k)
            {
                ans = -1;
                break;
            }
            
            ans += k;
        }
        
        printf("Case %d: ",t);
        if(ans == -1) puts("Impossible");
        else printf("%d\n",ans);
    }
    return 0;
}
