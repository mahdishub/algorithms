#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b);
#define pi             3.1415926535
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define bug            cout << 'x' << endl;
#define check(x)       cout << x << endl;
#define e              2.71828182845
#define mp             make_pair
#define s              second
#define f              first
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));

typedef long long ll;
typedef unsigned long long ull;
typedef pair < ull,int > ii;
typedef priority_queue< ii,vector<ii>, greater<ii> > pq_increasing;


int arr[] = {1,5,3,4,8,-2,9,3};
int len[8];
int n = 8;
int lis ( ) {
    int maxm = 0;
    for ( int i = 1; i < n; i++ ) {
        for ( int j = 0; j < i; j++ ) {
            if ( arr[i] > arr[j] && len[i] < len[j]+1 ) {
                len[i] = len[j]+1;
                maxm = max(maxm,len[i]+1);
            }
        }
    }
    return maxm;
}


int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cout << lis() << endl;
}
