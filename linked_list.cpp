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

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,char > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

struct node{
    int info;
    node *link;
};

node *start,*ptr,*temp,*before,*after,*new_node;

void fnd( int item ) {
    ptr = start;
    before = start;
    after = NULL;
    while ( ptr != NULL ) {
        if ( ptr->info >= item ) {
            after = ptr;
            break;
        }
        before = ptr;
        ptr = ptr->link;
    }
}
void print ( node* start ) {
    node* ptr = start;
    while ( ptr != NULL ) {
        cout << ptr->info << endl;
        ptr = ptr->link;
    }
}

node* Find( int item  ) {
    ptr = start;
    after = NULL;
    while ( ptr != NULL ) {
        if ( ptr->info >= item ) break;
        after = ptr;
        ptr = ptr->link;
    }
    return after;
}
void dlt ( ) {
    if ( after == start ) start = after->link;
    else {
        before->link = after->link;
    }
}

int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    start = temp  = ptr = NULL;
    while ( n-- ) {
        temp = new node;
        cin >> temp -> info;
        if ( start == NULL ) ptr=start=temp;
        ptr->link = temp;
        ptr = temp;
    }
    ptr->link = NULL;
    ptr = start;
    while ( ptr != NULL) cout << ptr->info << endl, ptr = ptr->link;
    node *new_node;
    new_node = (node*)malloc(sizeof(node));
    int item;
    cin >> item;
    fnd(item);
    dlt();
    ptr = start;
    while ( ptr != NULL) cout << ptr->info << endl, ptr = ptr->link;

}
