//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: L - Life Is But A Dream
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

string s[15];
int n,q;

void F(string suf)
{
    for(int j = 0 ; j < n ; j++)
    {
        int sz = s[j].size();
        string tmp;
        for(int k = 0 ; k < sz ; k++)
        {
            if(s[j][k] == ' ')
            {
                if(tmp.size() >= suf.size() && tmp.compare(tmp.size() - suf.size(),tmp.size(),suf) == 0)
                {
                    cout << tmp << endl;
                    return;
                }
                tmp.clear();
            }
            else if('a' <= s[j][k] && s[j][k] <= 'z')
                tmp += s[j][k];
        }
    }
    printf("*\n");
}

void L(string suf)
{
    for(int j = n-1 ; j >= 0 ; j--)
    {
        int sz = s[j].size();
        string tmp;
        for(int k = sz - 1 ; k >= 0 ; k--)
        {
            if(s[j][k] == ' ')
            {
                reverse(tmp.begin(),tmp.end());
                if(tmp.size() >= suf.size() && tmp.compare(tmp.size() - suf.size(),tmp.size(),suf) == 0)
                {
                    cout << tmp << endl;
                    return;
                }
                tmp.clear();
            }
            else if('a' <= s[j][k] && s[j][k] <= 'z')
                tmp += s[j][k];
        }
    }
    printf("*\n");
}

int N(string suf)
{
    int cnt = 0;
    for(int j = 0 ; j < n ; j++)
    {
        int sz = s[j].size();
        string tmp;
        for(int k = 0 ; k < sz ; k++)
        {
            if(s[j][k] == ' ')
            {
                if(tmp.size() >= suf.size() && tmp.compare(tmp.size() - suf.size(),tmp.size(),suf) == 0)
                    cnt++;
                tmp.clear();
            }
            else if('a' <= s[j][k] && s[j][k] <= 'z')
                tmp += s[j][k];
        }
    }
    printf("%d\n",cnt);
}

int main()
{
    freopen("L - Life Is But A Dream.INP","r",stdin);
    freopen("L - Life Is But A Dream.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        printf("Case %d:\n",t);
        scanf(" %d ",&n);
        for(int i = 0 ; i < n ; i++)
        {
            getline(cin,s[i]);
            for(int j = 0 ; j < s[i].size() ; j++)
            {
                if('A' <= s[i][j] && s[i][j] <= 'Z')
                    s[i][j] += ('a' - 'A');
                else if(('a' > s[i][j] || s[i][j] > 'z') && s[i][j] != ' ')
                {
                    s[i].erase(s[i].begin() + j);
                    j--;
                }
            }
            s[i].insert(s[i].begin(),' ');
            s[i] += ' ';
        }
        
        scanf(" %d ",&q);
        for(int i = 0 ; i < q ; i++)
        {
            char cmd;
            string suf;
            scanf(" %c ",&cmd);
            cin >> suf;
            
            if(cmd == 'F')
                F(suf);
            else if(cmd == 'L')
                L(suf);
            else if(cmd == 'N')
                N(suf);
            
        }
    }
    return 0;
}
