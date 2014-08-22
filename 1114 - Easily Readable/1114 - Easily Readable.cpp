//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 1114 - Easily Readable
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

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int n;
map<string,int> m;
char s[10005];
int cnt[60];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("1114 - Easily Readable.INP","r",stdin);
    freopen("1114 - Easily Readable.OUT","w",stdout);
    #endif
    
    int tcs;
    scanf(" %d ",&tcs);
    
    fr(t,1,tcs)
    {
        m.clear();
        
        scanf("%d",&n);
        getchar();
        rep(i,58) cnt[i] = 0;
        
        fr(q,1,n)
        {
            gets(s);
            
            string tmp = "";
            int len = strlen(s);
            rep(i,len) cnt[s[i]-'A']++;
            
            cnt[s[0]-'A']--;
            tmp += s[0];
            
            if(len == 1)
            {
                m[tmp]++;
                continue;
            }
            
            cnt[s[len-1]-'A']--;
            
            rep(i,58)
            {
                while(cnt[i])
                {
                    tmp += char(i+'A');
                    cnt[i]--;
                }
            }
            tmp += s[len-1];
            
            m[tmp]++;
        }
        
        scanf("%d",&n);
        getchar();
        printf("Case %d:\n",t);
        
        fr(q,1,n)
        {
            gets(s);
            int len = strlen(s);
            s[len] = ' ';
            s[len+1] = '\0';
            len++;
            
            char ft,lt;
            int ans = 1;
            //DEBUG(s);
            ft = lt = '*';
            
            for(int i = 0 ; i < len && ans ; i++)
            {
                if(s[i] == ' ')
                {
                    if(ft == '*') continue;
                    
                    cnt[ft-'A']--;
                    string tmp = "";
                    tmp += ft;
                    
                    if(lt != '*') cnt[lt-'A']--;
                    //DEBUG(lt);
                    for(int j = 0 ; j < 58 && lt != '*' ; j++)
                    {
                        while(cnt[j])
                        {
                            tmp += char(j+'A');
                            cnt[j]--;
                        }
                    }
                    
                    if(lt != '*')
                        tmp += lt;
                    
                    if(m.count(tmp)) ans *= m[tmp];
                    else ans = 0;
                    
                    lt = ft = '*';
                }
                else
                {
                    //DEBUG(s[i]);
                    cnt[s[i]-'A']++;
                    if(ft == '*') ft = s[i];
                    else lt = s[i];
                }
            }
            
            cout << ans << endl;
        }
    }
    
    return 0;
}
