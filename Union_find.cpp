#include <bits/stdc++.h>

using namespace std;

class UnionFind{
   public:
    vector<int> par;
    vector<int> size;

    UnionFind(int n) {
        par.resize(n);
        for(int x=0;x<n;x++)par[x] = x;
        size.resize(n,1);
    }

    int find(int x) {
        while ( x != par[x] ) {
            x = par[x];
        }
        return x;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    void unite(int x,int y) {
        int a = find(x);
        int b = find(y);

        if(size[a] < size[b])swap(a,b);
        size[a] += b;
        par[b] = a;
        
    }
};

int main() {
    int n;
    cin>>n;
    int q;
    cin>>q;
    UnionFind d(n);
    while(q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 0) {
            d.unite(a, b);
        } else {
            if (d.same(a, b)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}