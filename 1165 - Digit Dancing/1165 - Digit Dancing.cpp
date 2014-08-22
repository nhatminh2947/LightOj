//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1165 - Digit Dancing
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

vi a;
bool valid[20];
int step[87654325];

int BFS()
{
    rep(i,87654323) step[i] = -1;
    queue<vi> q;
    q.push(a);
    
    int m = 0;
    //DEBUG(m);
    rep(i,8)
    {
        m = m*10 + abs(a[i]);
        //DEBUG(m);
    }
    step[m] = 0;
    while(!q.empty())
    {
        vi u = q.front();
        
        q.pop();
        
        m = 0;
        rep(i,8) m = m*10 + abs(u[i]);
        if(m == 12345678)
            return step[m];
        
        for(int i = 0 ; i < 8 ; i++)
        {
            for(int j = 0 ; j < 8 ; j++)
            {
                if(u[i] * u[j] < 0 && valid[abs(u[i]) + abs(u[j])])
                {
                    if(i < j)
                    {
                        vi v = u;
                        for(int k = j ; k > i+1 ; k--)
                            swap(v[k],v[k-1]);
                        int n = 0;
                        rep(k,8)
                            n = n*10 + abs(v[k]);
                        
                        if(step[n] == -1)
                        {
                            step[n] = step[m] + 1;
                            q.push(v);
                        }
                        
                        v = u;
                        for(int k = j ; k > i ; k--)
                            swap(v[k],v[k-1]);
                        n = 0;
                        rep(k,8)
                            n = n*10 + abs(v[k]);
                        if(step[n] == -1)
                        {
                            step[n] = step[m] + 1;
                            q.push(v);
                        }
                    }
                    else
                    {
                        vi v = u;
                        for(int k = j ; k < i-1 ; k++)
                            swap(v[k],v[k+1]);
                        int n = 0;
                        rep(k,8)
                            n = n*10 + abs(v[k]);
                        if(step[n] == -1)
                        {
                            step[n] = step[m] + 1;
                            q.push(v);
                        }
                        
                        v = u;
                        for(int k = j ; k < i ; k++)
                            swap(v[k],v[k+1]);
                        n = 0;
                        rep(k,8)
                            n = n*10 + abs(v[k]);
                        if(step[n] == -1)
                        {
                            step[n] = step[m] + 1;
                            q.push(v);
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
    freopen("1165 - Digit Dancing.INP","r",stdin);
    freopen("1165 - Digit Dancing.OUT","w",stdout);
    #endif
    
    rep(i,17) valid[i] = false;
    valid[1] = valid[2] = valid[3] = valid[5] = valid[7] = valid[11] = valid[13] = true;

    int tcs;
    read(tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        a.clear();
        rep(i,8)
        {
            int x;
            read(x);
            //DEBUG(x);
            a.pb(x);
        }
        
        printf("Case %d: %d\n",t,BFS());
    }
    
    return 0;
}

