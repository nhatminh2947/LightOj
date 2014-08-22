//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: F - Humanity Prevails!
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

char inp[5000005];
int data[300005];
deque<int> maxK, minK;

void push_maxK(int ind)
{
	while(!maxK.empty() && data[maxK.back()] <= data[ind])
		maxK.pop_back();
	maxK.push_back(ind);
}

void push_minK(int ind)
{
	while(!minK.empty() && data[minK.back()] >= data[ind])
		minK.pop_back();
	minK.push_back(ind);
}

void pop_maxK(int ind)
{
	while(!maxK.empty() && maxK.front() <= ind)
		maxK.pop_front();
}

void pop_minK(int ind)
{
	while(!minK.empty() && minK.front() <= ind)
		minK.pop_front();
}

int main()
{
	freopen("F - Humanity Prevails!.INP","r",stdin);
	freopen("F - Humanity Prevails!.OUT","w",stdout);
	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		printf("Case %d:",t);
		maxK.clear();
		minK.clear();
		int n,k;
		scanf(" %d %d ",&n,&k);
		gets(inp);
		
		int sz = strlen(inp);
		inp[sz] = ' ';
		inp[sz+1] = 'X';
		inp[sz+2] = '\0';
		
		int tmp = 0;
		sz = strlen(inp);
		int ind = 1;
		int ans = -INF;
		for(int i = 0 ; i < sz ; i++)
		{
			if(inp[i] == ' ')
			{
				data[ind] = tmp;
				tmp = 0;
				push_maxK(ind);
				push_minK(ind);
				pop_maxK(ind - k);
				pop_minK(ind - k);
				
				int a = data[maxK.front()] - data[minK.front()];
				ans = max(ans,a);
				
				ind++;
			}
			else if(inp[i] == 'X')
			{
				if(ans == -INF)
					ans = 0;
				printf(" %d",ans);
				//ans = -INF;
				i++;
			}
			else
			{
				tmp = tmp * 10 + (inp[i] - '0');
			}
		}
		printf("\n");
	}
	return 0;
}

