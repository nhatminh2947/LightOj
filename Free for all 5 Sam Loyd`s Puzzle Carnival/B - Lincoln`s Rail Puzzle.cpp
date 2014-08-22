//******************************************************************
// Coded by: Huynh Nhat Minh
// Problem Code: B - Lincoln`s Rail Puzzle
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
    //freopen("B - Lincoln`s Rail Puzzle.INP","r",stdin);
    //freopen("B - Lincoln`s Rail Puzzle.OUT","w",stdout);
    int tcs;
    scanf(" %d ",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {
        double n,len;
        scanf(" %lf %lf ",&n,&len);
        
        double area = (n*len*len)/(4*tan(PI/n));
        printf("Case %d: %.2lf\n",t,area);
    }
    return 0;
}
