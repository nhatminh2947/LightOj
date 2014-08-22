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
	//freopen(".INP","r",stdin);
	freopen("C.INP","w",stdout);
	int tcs = 100;
	printf("%d\n",tcs);
	int n = 10;
	for(int t = 1 ; t <= tcs ; t++)
	{
		printf("%d\n",n);
		for(int i = 0 ; i < n ; i++)
			printf("%d ",rand()%100001);
		printf("\n");
	}	
	return 0;
}

