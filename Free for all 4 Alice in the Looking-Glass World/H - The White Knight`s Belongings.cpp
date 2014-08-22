//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: H - The White Knight`s Belongings
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
#define maxN 123456
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

using namespace std;

int n;
vector<int> v[105], c[105];
vector< pair<int,int> > data;
bool vis[105];


int BFS()
{
    queue<int> q;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
        vis[i] = false;
    for(int i = 0 ; i < n ; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            cnt++;
            q.push(i);
            while(!q.empty())
            {
                int tmp = q.front();
                q.pop();
                int sz = v[data[tmp].ff].size();
                for(int j = 0 ; j < sz ; j++)
                    if(!vis[v[data[tmp].ff][j]])
                    {
                        vis[v[data[tmp].ff][j]] = true;
                        q.push(v[data[tmp].ff][j]);
                    }
                
                sz = c[data[tmp].ss].size();
                for(int j = 0 ; j < sz ; j++)
                    if(!vis[c[data[tmp].ss][j]])
                    {
                        vis[c[data[tmp].ss][j]] = true;
                        q.push(c[data[tmp].ss][j]);
                    }
            }
        }
    }
    return cnt;
}

int main()
{
    //freopen("H - The White Knight`s Belongings.INP","r",stdin);
    //freopen("H - The White Knight`s Belongings.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        scanf(" %d ",&n);
        data.clear();
        for(int i = 0 ; i < 101 ; i++)
            v[i].clear();
        for(int i = 0 ; i < 101 ; i++)
            c[i].clear();
        for(int i = 0 ; i < n ; i++)
        {
            string tmp;
            cin >> tmp;
            int sz = tmp.size();
            int cnt1 = 0,cnt2 = 0;
            for(int j = 0 ; j < sz ; j++)
            {
                if(tmp[j] == 'a' || tmp[j] == 'e' || tmp[j] == 'i' || tmp[j] == 'o' || tmp[j] == 'u')
                    cnt1++;
                else cnt2++;
            }
            v[cnt1].pb(i);
            c[cnt2].pb(i);
            pair<int,int> p;
            p.ff = cnt1;
            p.ss = cnt2;
            data.pb(p);
        }
        
        printf("Case %d: %d\n",t,BFS());
    }
    return 0;
}
