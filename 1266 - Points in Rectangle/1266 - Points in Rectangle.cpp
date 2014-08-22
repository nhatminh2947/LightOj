//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1266 - Points in Rectangle
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

int n,q;
int BIT[1005][1005];
int check[1005][1005];

void add(int x, int y)
{
    for(int i = x ; i <= 1001 ; i += i&-i)
        for(int j = y ; j <= 1001 ; j += j&-j)
            BIT[i][j]++;
}

int get(int x, int y)
{
    int sum = 0;
    
    for(int i = x ; i > 0 ; i -= i&-i)
        for(int j = y ; j > 0 ; j -= j&-j)
            sum += BIT[i][j];
    
    return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1266 - Points in Rectangle.INP","r",stdin);
    freopen("1266 - Points in Rectangle.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf("%d",&tcs);
    
    fr(t,1,tcs)
    {
        printf("Case %d:\n",t);
        
        fr(i,1,1001)
            fr(j,1,1001) check[i][j] = BIT[i][j] = 0;
        
        scanf("%d",&n);
        
        fr(i,1,n)
        {
            scanf(" %d ",&q);
            
            if(q)
            {
                int x1,x2,y1,y2;
                scanf(" %d %d %d %d ",&x1,&y1,&x2,&y2);
                x1++;
                x2++;
                y1++;
                y2++;
                
                printf("%d\n",get(x2,y2) - get(x1-1,y2) - get(x2,y1-1) + get(x1-1,y1-1));
            }
            else
            {
                int x,y;
                scanf("%d %d",&x,&y);
                if(!check[x+1][y+1])
                {
                    add(x+1,y+1);
                    check[x+1][y+1] = true;
                }
            }
        }
    }
    
    return 0;
}
