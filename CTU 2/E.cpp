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
int n,m;
deque<int> q;

int main()
{
    //freopen("E.INP","r",stdin);
    //freopen("E.OUT","w",stdout);
    scanf(" %d ",&tcs);
    for(int t=1;t<=tcs;t++)
    {
        printf("Case %d:\n",t);
        string s;
        int x;
        q.clear();
        scanf(" %d %d ",&n,&m);
        for(int i=0;i<m;i++)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                scanf(" %d ",&x);
                if(q.size()==n)
                    printf("The queue is full\n");
                else
                {
                    q.push_front(x);
                    printf("Pushed in left: %d\n",x);
                }
            }
            else if(s=="pushRight")
            {
                scanf(" %d ",&x);
                if(q.size()==n)
                    printf("The queue is full\n");
                else
                {
                    q.push_back(x);
                    printf("Pushed in right: %d\n",x);
                }
            }
            else if(s=="popLeft")
            {
                if(q.size()==0)
                    printf("The queue is empty\n");
                else
                {
                    printf("Popped from left: %d\n",q.front());
                    q.pop_front();
                }
            }
            else if(s=="popRight")
            {
                if(q.size()==0)
                    printf("The queue is empty\n");
                else
                {
                    printf("Popped from right: %d\n",q.back());
                    q.pop_back();
                }
            }
        }
    }
    return 0;
}
