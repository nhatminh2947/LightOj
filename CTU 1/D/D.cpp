//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code:
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
#define INF 1000000000
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)

using namespace std;

int tcs;

int main()
{
    //freopen("D.INP","r",stdin);
    //freopen("D.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        string cmd,web;
        deque<string> s;
        int c=0;
        printf("Case %d:\n",t);
        s.push_back("http://www.lightoj.com/");
        int sz=s.size();
        while(cin>>cmd)
        {
            if(cmd=="QUIT") break;
            if(cmd=="VISIT")
            {
                
                cin>>web;
                
                c++;
                s.erase(s.begin()+c,s.end());
                s.push_back(web);
                cout<<web<<endl;
            }
            else if(cmd=="FORWARD")
            {
                if(c+1>=s.size()) printf("Ignored\n");
                else
                {
                    c++;
                    cout<<s[c]<<endl;
                }
            }
            else if(cmd=="BACK")
            {
                int sz=s.size();
                if(c-1<0)
                    printf("Ignored\n");
                else
                {
                    c--;
                    cout<<s[c]<<endl;
                }
            }
        }
    }
    return 0;
}
