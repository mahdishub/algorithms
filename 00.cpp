#include<bits/stdc++.h>

using namespace std;

int parent[10],r[10];

inline int findp ( int a ) {
    return ( parent[a] == a ) ? a : parent[a] = findp(parent[a]);
}

inline void Union( int a, int b ) {
    int u,v;
    u = findp(a);
    v = findp(b);
    if ( u != v ) {
        r[v] += r[u];
        parent[u] = v;
    }
}

int main() {
    for ( int i = 1; i < 10; i++ ) parent[i] = i,r[i] = 1;
    int a,b;
    while ( cin >> a >> b ) {
        Union(a,b);
        printf("now\n");
        for ( int i = 1; i <= 6; i++ ) cout << i << ' ' << parent[i] << endl;
        printf("rank\n");
        for ( int i = 1; i <= 6; i++ ) cout << i << ' ' << r[i] << endl;
    }
}
