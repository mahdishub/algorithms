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
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define MAX            2005

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

int arr[] = {8, 1, 9, 8, 3, 4, 6, 1, 5, 2};
int I[11];
vector < ii > L;
vector < int > seq;

int lis ( int arr[], int n ) {
    int maxlen = -1,tail;
    fill(I,I+n,INT_MAX);
    I[0] = INT_MIN;
    int pos;
    for ( int i = 0 ; i < n; i++ ) {
        pos = lower_bound(I,I+n,arr[i]) - I;
        I[pos] = arr[i];
        if ( maxlen < pos ) {
            tail = L.size();
            maxlen = pos;
        }
        L.push_back({arr[i],pos});
    }
    seq.push_back(L[tail].first);
    for ( int i = tail; i >= 0; i-- ) {
        if ( L[tail].second == 1 ) break;
        if ( L[i].first < L[tail].first &&  L[i].second == L[tail].second-1 ) {
            seq.push_back(L[i].first);
            tail = i;
        }
    }
    reverse(seq.begin(),seq.end());
    return maxlen;
}


int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int n = sizeof(arr)/sizeof(int);
    int len = lis(arr,n);
    cout << len << endl;
    loop(seq,itr) cout << *itr << ' ';
    cout << endl;

}
