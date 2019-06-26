#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define pi             3.1415926535
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
///#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define check(x)       cout << x << endl;
#define bug            cout << 'x' << endl;
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define inf            0x3f3f3f3f
#define MAX            100005
#define ff             first
#define ss             second
#ifdef FACT
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)
    #define timeStamp

#endif

struct debugger{
    template<typename T> debugger & operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;


typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;


string factors[1005];


string cmp ( string a, string b ) {
    int alen = a.length(), blen = b.length();
    if ( alen == 0 ) return b;
    if ( blen == 0 ) return a;
    if ( alen == blen ) {
        for ( int i = 0; i < alen; i++ ) {
            if ( a[i] > b[i] ) return b;
            if ( b[i] > a[i] ) return a;
        }
    }
    return ( alen > blen ) ? b:a;
}

string add ( string a,string b ) {
    string t;
    if ( b.length() > a.length() ) swap(a,b);
    int lena = a.length(), lenb = b.length();
    t.append(lena-lenb,'0');
    b = t+b;
    short sum = 0,c = 0;
    for ( int i = lena-1; i >= 0; i-- ) {
        sum = (a[i]-'0' + b[i] -'0'+c);
        c = sum/10;
        a[i] = (sum%10)+'0';
    }
    if ( c != 0 ) {
        a = char(c+'0')+a;
    }
    return a;
}

string multiply ( string a, string b ) {
    string ans;
    vector <string> layer;
    int c,d,d1,d2;
    string s2;
    for ( int i = b.length()-1; i >= 0; i--  ) {
        string s ="";
        c = 0;
        for ( int j = a.length()-1;  j >= 0; j-- ) {
            d1 = b[i]-'0', d2 = a[j]-'0';
            s += ((((d1*d2)+c)%10) + '0');
            c = ((d1*d2)+c)/10;
        }
        if ( c != 0 )s += (c +'0');
        s = s2 + s;
        layer.push_back(s);
        s2.push_back('0');
    }
    int n = layer[layer.size()-1].length();
    c = 0;
    for ( int i = 0; i < n; i++ ) {
        int s = 0;
        for ( int j = 0; j < layer.size(); j++ ) {
            if ( i >= layer[j].length() ) continue;
            s += (layer[j][i]-'0');
        }
        ans.push_back(((s+c)%10+'0'));
        c = (s+c)/10;
    }
    if ( c != 0 ) ans.push_back(c+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}

string toString ( int n ) {
    string ans;
    while ( n ) {
        ans.push_back((n%10)+'0');
        n /= 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void precal ( ) {
    factors[0] = "1";
    for ( int i = 1; i <= 1000; i++ ) {
        factors[i] = multiply(factors[i-1],toString(i));
    }
}




int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precal();
    int n;
    while ( cin >> n ) {
        cout << n << '!' << endl << factors[n] << endl;
    }
    return 0;
}
