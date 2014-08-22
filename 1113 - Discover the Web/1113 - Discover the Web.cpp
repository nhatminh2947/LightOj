//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: 1113 - Discover the Web
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
#define int64 long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define DEBUG(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define maxN 123456
#define INF 1000111222

using namespace std;

int main()
{
	freopen("1113 - Discover the Web.INP","r",stdin);
	freopen("1113 - Discover the Web.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		printf("Case %d:\n",t);
		stack<string> fw,bw;
		string s;
		string cur = "http://www.lightoj.com/";
		while(cin >> s)
		{
			if(s == "QUIT")
				break;
			
			if(s == "VISIT")
			{
				bw.push(cur);
				cin >> cur;
				cout << cur << endl;
				while(!fw.empty())
					fw.pop();
			}
			else if(s == "BACK")
			{
				if(bw.empty())
				{
					puts("Ignored");
					continue;
				}
				fw.push(cur);
				cur = bw.top();
				bw.pop();
				cout << cur << endl;
			}
			else if(s == "FORWARD")
			{
				if(fw.empty())
				{
					puts("Ignored");
					continue;
				}
				
				bw.push(cur);
				cur = fw.top();
				fw.pop();
				cout << cur << endl;
			}
		}
	}
	return 0;
}

