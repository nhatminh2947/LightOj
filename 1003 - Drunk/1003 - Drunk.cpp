//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Number: 1003 - Drunk
// Verdict: 
//******************************************************************

#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

#define ff first
#define ss second
#define pb push_back

using namespace std;

map<string,int> enc;
queue<int> Out[20010];
vector<int> In[20010];
int n;

bool topo()
{
    queue<int> q;
    for(int i = 1 ; i <= n ; i++)
        if(In[i].empty())
            q.push(i);
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        while(!Out[u].empty())
        {
            int v = Out[u].front();
            Out[u].pop();
            vector<int>::iterator it;
            it = find(In[v].begin(),In[v].end(),u);
            if(it != In[v].end())
                In[v].erase(it);
            
            if(In[v].empty())
                q.push(v);
        }
    }
    
    for(int i = 1 ; i <= n ; i++)
        if(!In[i].empty())
            return false;
    return true;
}

int main()
{
    freopen("1003 - Drunk.INP","r",stdin);
    freopen("1003 - Drunk.OUT","w",stdout);
    
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        enc.clear();
        for(int i = 1 ; i <= 20005 ; i++)
        {
            In[i].clear();
            while(!Out[i].empty())
                Out[i].pop();
        }
        n = 0;
        int m;
        scanf(" %d ",&m);
        for(int i = 0 ; i < m ; i++)
        {
            string a,b;
            cin >> a >> b;
            if(!enc[a])
                enc[a] = ++n;
            if(!enc[b])
                enc[b] = ++n;
            
            Out[enc[a]].push(enc[b]);
            In[enc[b]].pb(enc[a]);
        }
        
        printf("Case %d: ",t);
        if(topo())
            puts("Yes");
        else puts("No");
    }
    
    return 0;
}
