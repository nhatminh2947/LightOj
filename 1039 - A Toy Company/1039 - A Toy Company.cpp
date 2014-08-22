//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1039 - A Toy Company
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
#define i64 long long
#define u64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define maxN 123456
#define INF 1000111222

using namespace std;

map<string,bool> vis;
string a,b;
int n;

inline int BFS()
{
    if(vis[a])
        return -1;
    queue< pair<string,int> > q;
    q.push(mp(a,0));
    vis[a] = true;
    while(!q.empty())
    {
        string tmp = q.front().ff;
        if(tmp == b)
            return q.front().ss;
        int d = q.front().ss;
        q.pop();
        
        for(int i = 0 ; i < 3 ; i++)
        {
            string s = tmp;
            if(s[i] == 'a')
                s[i] = 'z';
            else s[i]--;
            
            if(!vis[s])
            {
                vis[s] = true;
                q.push(mp(s,d+1));
            }
            
            s = tmp;
            if(s[i] == 'z')
                s[i] = 'a';
            else s[i]++;
            
            if(!vis[s])
            {
                vis[s] = true;
                q.push(mp(s,d+1));
            }
        }
    }
    
    return -1;
}

int main()
{
	freopen("1039 - A Toy Company.INP","r",stdin);
	freopen("1039 - A Toy Company.OUT","w",stdout);
	
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
        vis.clear();
	    cin >> a >> b;
	    scanf(" %d ",&n);
	    for(int i = 0 ; i < n ; i++)
	    {
	        char tmp;
	        string c[5];
	        for(int j = 0 ; j < 3 ; j++)
                cin >> c[j];
            
            string v = "000";
            for(int i = 0 ; i < c[0].size() ; i++)
            {
                v[0] = c[0][i];
                for(int j = 0 ; j < c[1].size() ; j++)
                {
                    v[1] = c[1][j];
                    for(int k = 0 ; k < c[2].size() ; k++)
                    {
                        v[2] = c[2][k];
                        vis[v] = true;
                    }
                }
            }
	    }
        
        printf("Case %d: %d\n",t,BFS());
	}

	return 0;
}

