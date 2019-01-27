#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define pi             3.1415926535
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
///#define MAX            100005
#define f              first
#define s              second
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

struct node {
    node *parent,*left,*right;
    int info;
};

node *root=NULL;

void ins ( node *n, node *p ) {
    if ( root == NULL ) {root = n;return;}
    if ( n->info < p->info ) {
        if (  p->left == NULL ) p->left = n;
        else ins(n,p->left);
    }
    if ( n->info > p->info ) {
        if ( p->right == NULL ) p->right = n;
        else ins(n,p->right);
    }
}

void inorder ( node  *n ) {
    if ( n != NULL ) {
        inorder( n->left );
        cout << n->info;
        inorder( n->right );
    }
}


int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while ( n-- ) {
        node *temp = new node;
        temp = NULL;
        cin >> temp->info;
        ins(temp,root);
    }
    inorder(root);
    return 0;
}
