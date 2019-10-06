#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define sf3(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define pi             acos(-1.0)
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define check(x)       cout << x << endl;
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
#define MAX            100005
#define ff             first
#define ss             second
#define all(v)         v.begin(),v.end()

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
typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
template < class T > inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}

struct Trie{
    map<char,Trie*> children;
    bool isEndOfWord;
    Trie():isEndOfWord(false) {};
};


void Insert( Trie* root,string key ) {
    Trie *itr = new Trie();
    itr = root;
    for ( int i = 0; i < key.length(); i++ ) {
        if ( !itr->children[key[i]] ) { /// charecter not existing in node
            itr->children[key[i]] = new Trie();
        }
        itr = itr->children[key[i]];
    }
    itr->isEndOfWord = true; /// marking the leaf as end of word
}


void TriePrinter ( Trie *itr ) {

    if ( itr == NULL ) return;
    for ( auto t: itr->children ) cout << t.ff << ' ';
    if ( itr->children.size() == 0 ) cout << "Leaf";
    cout << endl;
    for ( auto t: itr->children ) {
        TriePrinter(t.ss);
    }
}


int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    Trie *root = new Trie();
    Insert(root,"abcd");
    Insert(root,"abgl");
    Insert(root,"cdf");
    Insert(root,"abcd");
    Insert(root,"lmn");
    TriePrinter(root);
    delete root;

    return 0;
}



