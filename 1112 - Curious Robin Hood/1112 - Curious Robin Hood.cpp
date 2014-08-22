//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1112 - Curious Robin Hood
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

int n,q,k,m;
int a[maxN+5];
int BIT[maxN+5];

int get(int x)
{
    int total = 0;
    while(x>0)
    {
        total += BIT[x];
        x -= x&-x;
    }
    
    return total;
}

void add(int x, int val)
{
    while(x <= n)
    {
        BIT[x] += val;
        x += x&-x;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1112 - Curious Robin Hood.INP","r",stdin);
    freopen("1112 - Curious Robin Hood.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf("%d",&tcs);
    
    fr(t,1,tcs)
    {
        printf("Case %d:\n",t);
        scanf("%d %d",&n,&q);
        fr(i,1,n) BIT[i] = 0;
        fr(i,1,n)
        {
            scanf("%d",&a[i]);
            add(i,a[i]);
        }
        
        rep(i,q)
        {
            scanf("%d",&k);
            if(k == 1)
            {
                scanf("%d",&m);
                m++;
                int val = get(m) - get(m-1);
                add(m,-val);
                //add(m+1,val);
                printf("%d\n",val);
                //DEBUG(get(m) - get(m-1));
            }
            else if(k == 2)
            {
                int u,val;
                scanf("%d %d",&u,&val);
                u++;
                add(u,val);
                //add(u+1,-val);
                //DEBUG(get(u) - get(u-1));
            }
            else if(k == 3)
            {
                int u,v;
                scanf("%d %d",&u,&v);
                u++;
                v++;
                printf("%d\n",get(v) - get(u-1));
            }
        }
    }
    
    return 0;
}
