//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: A - Jabberwockian Words
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

int main()
{
    //freopen("A - Jabberwockian Words.INP","r",stdin);
    //freopen("A - Jabberwockian Words.OUT","w",stdout);
    int tcs;
    bool V[50];
    for(int i = 0; i < 40 ; i++)
        V[i] = false;
    V['a' - 'a'] = V['e' - 'a'] = V['i' - 'a'] = V['o' - 'a'] = V['u' - 'a'] = true;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        string s;
        cin >> s;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(V[s[i] - 'a'] && !V[s[i + 1] - 'a'] && V[s[i + 2] - 'a'] && (i + 3 <= s.size()))
            {
                if((s[i + 2] == 'e') && (i + 2 == s.size() - 1)) continue;
                s.insert(s.begin() + i + 1,'-');
                i++;
            }
            else if(V[s[i] - 'a'] && !V[s[i + 1] - 'a'] && !V[s[i + 2] - 'a'] && V[s[i + 3] - 'a'] && (i + 4 <= s.size()))
            {
                if((s[i + 3] == 'e') && (i + 3 == s.size() - 1)) continue;
                s.insert(s.begin() + i + 2,'-');
                i+=2;
            }
            else if(V[s[i] - 'a'] && !V[s[i + 1] - 'a'] && !V[s[i + 2] - 'a'] && !V[s[i + 3] - 'a'] && V[s[i + 4] - 'a'] && (i + 5 <= s.size()))
            {
                if((s[i + 4] == 'e') && (i + 4 == s.size() - 1)) continue;
                s.insert(s.begin() + i + 2,'-');
                i+=2;
            }
        }
        printf("Case %d: ",t);
        cout << s << endl;
    }
    return 0;
}
