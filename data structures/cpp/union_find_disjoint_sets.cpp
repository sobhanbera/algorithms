/**
   Maintain a set of elements partitioned into non-overlapping subsets. Each
   partition is assigned a unique representative known as the parent, or root. The
   following implements two well-known optimizations known as union-by-size and
   path compression. This version is simplified to only work on integer elements.

   - find_set(u) returns the unique representative of the partition containing u.
   - same_set(u, v) returns whether elements u and v belong to the same partition.
   - union_set(u, v) replaces the partitions containing u and v with a single new
   partition consisting of the union of elements in the original partitions.

   Time Complexity:
   - O(a(n)) per call to find_set(), same_set(), and union_set(), where n is the
   number of elements, and a(n) is the extremely slow growing inverse of the Ackermann function
   (effectively a very small constant for all practical values of n).

   Space Complexity:
   - O(n) for storage of the disjoint set forest elements.
   - O(1) auxiliary for all operations.
**/

#include <bits/stdc++.h>

using namespace std;

class UnionFind {
  vector <int> par;
  vector <int> siz;
  int num_sets;
  size_t sz;

public:
  UnionFind() : par(1, -1), siz(1, 1), num_sets(0), sz(0) {}
  UnionFind(int n) : par(n + 1, -1), siz(n + 1, 1), num_sets(n), sz(n) {}

  int find_set(int u) {
    assert(u <= sz);

    int leader;
    for(leader = u; ~par[leader]; leader = par[leader]);

    for(int next = par[u]; u != leader; next = par[next]) {
      par[u] = leader;
      u = next;
    }
    return leader;
  }

  bool same_set(int u, int v) {
    return find_set(u) == find_set(v);
  }

  bool union_set(int u, int v) {
    if(same_set(u, v)) return false;

    int x = find_set(u);
    int y = find_set(v);

    if(siz[x] < siz[y]) swap(x, y);

    par[y] = x;
    siz[x] += siz[y];

    --num_sets;
    return true;
  }

  int number_of_sets() {
    return num_sets;
  }

  int size_of_set(int u) {
    return siz[find_set(u)];
  }

  size_t size() {
    return sz;
  }

  void clear() {
    par.clear();
    siz.clear();
    sz = num_sets = 0;
  }

  void assign(size_t n) {
    par.assign(n + 1, -1);
    siz.assign(n + 1,  1);
    sz = num_sets = n;
  }

  map < int, vector <int> > groups(int st) {
    map < int, vector <int> > ret;

    for(size_t i = st; i < sz + st; ++i)
      ret[find_set(i)].push_back(i);

    return ret;
  }
};

int main() {
	pair <int, int> ar[] = {{3, 2}, {6, 7}, {7, 5}, {9, 4}, {8, 1}};
	int sz = sizeof(ar) / sizeof(ar[0]);
	// max element in the array
	UnionFind uf(9);

	for(int i = 0; i < sz; ++i)
		if(!uf.same_set(ar[i].first, ar[i].second))
			uf.union_set(ar[i].first, ar[i].second);

	map <int, vector<int>> sets = uf.groups(1);
	for(auto parent : sets) {
		cout << parent.first << ": ";
		for(auto i : parent.second)
			cout << i << " ";
		cout << endl;
	}
}
