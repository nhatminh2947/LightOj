//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1080 - Binary Simulation - BIT
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

int BIT[maxN+5];
int q,n;
char s[100005];

void add(int x, int val)
{
    int i = x;
    while(i <= n)
    {
        BIT[i] += val;
        i += (i & -i);
    }
}

int get(int x)
{
    int sum = 0;
    int i = x;
    while(i > 0)
    {
        sum += BIT[i];
        i -= (i & -i);
    }
    
    return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1080 - Binary Simulation - BIT.INP","r",stdin);
    freopen("1080 - Binary Simulation - BIT.OUT","w",stdout);
    #endif
    
    int tcs;
    
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        printf("Case %d:\n",t);
        
        scanf(" %s ",&s);
        scanf(" %d ",&q);
        
        n = strlen(s);
        fr(i,1,100000) BIT[i] = 0;
        
        rep(i,q)
        {
            char c;
            scanf(" %c ",&c);
            
            if(c == 'I')
            {
                int a,b;
                scanf("%d %d",&a,&b);
                add(a,1);
                add(b+1,-1);
            }
            else
            {
                //cout << "CCC" << endl;
                int x;
                scanf("%d",&x);
                
                int k = get(x);
                int ans = (k & 1) ^ (s[x-1] - '0');
                printf("%d\n",ans);
                //DEBUG(k);
            }
        }
    }
    
    return 0;
}
