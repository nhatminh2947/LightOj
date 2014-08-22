//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1062 - Crossed Ladders
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

double x,y,c;

double f(double z)
{
    return (sqrt(y*y - z*z)*sqrt(x*x - z*z)) / (sqrt(y*y - z*z) + sqrt(x*x - z*z));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1062 - Crossed Ladders.INP","r",stdin);
    freopen("1062 - Crossed Ladders.OUT","w",stdout);
    #endif
    
    int tcs;
    read(tcs);
    
    fr(t,1,tcs)
    {
        read3(x,y,c);
        
        double lf = 0.0;
        double rg = 1000000000.0;
        double ans;
        
        rep(i,100)
        {
            double z = (lf + rg)/2.0;
            
            if(z*z >= y*y || z*z >= x*x) rg = z;
            else if(f(z) < c)
            {
                rg = z;
            }
            else
            {
                lf = z;
                ans = z;
            }
        }
        
        printf("Case %d: %.10lf\n",t,ans);
    }
    
    return 0;
}


