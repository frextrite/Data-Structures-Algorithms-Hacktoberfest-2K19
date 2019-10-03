// a class providing an implementation of the union find operations
// using the weighted union and (full) path compression heuristics
// the items are assumed as integers in the range [0, number of items)

public class UnionFind {
    private int components; // number of disjoint components
    private int parent[],   // parent of a particular component
                size[];     // size of component rooted at i
                            // however, i should be root of a component
    
    // initialize a union find object with specified number of items
    public UnionFind(int numItems) {
        components = numItems;
        parent = new int[numItems];
        size = new int[numItems];
        
        // initially all components are singleton sets
        for (int i = 0; i < numItems; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // get the number of disjoint components
    public int components() {
        return components;
    }
    
    // are two items in the same component?
    public boolean connected(int u, int v) {
        return find(u) == find(v);
    }
    
    // get the root of the specified item
    // this implements full path-compression
    public int find(int u) {
        // first get the root for the specified item by traversing to root
        int root = u;
        while (root != parent[root])
            root = parent[root];
        
        // then perform path-compression by traversing to root again
        // but setting the parent of the items on the path to the root
        while (u != root) {
            int prevParent = parent[u];
            parent[u] = root;
            u = prevParent;
        }
        
        return root;
    }
    
    // merge two components containing u and v respectively
    // into a single component
    public void union(int u, int v) {
        int rootU = find(u), rootV = find(v);
        
        if (rootU == rootV) return;
        
        // add the smaller root to the larger root
        // i.e. add the smaller component to the larger one
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        }
        else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
        components--;
    }
    
    // unit testing
    public static void main(String[] args) {
        UnionFind uf = new UnionFind(10);
        uf.union(0, 1);
        uf.union(1, 2);
        uf.union(0, 1);
        uf.union(1, 9);
        uf.union(3, 4);
        uf.union(3, 5);
        uf.union(7, 8);
        
        // current state, root elements in [...]
        // {[0], 1, 2, 9}, {[3], 4, 5}, {[6]}, {[7], 8}
        assert uf.components() == 4;
        
        assert    uf.connected(0, 1) &&  uf.connected(0, 9) && !uf.connected(0, 3) 
               && uf.connected(3, 5) && !uf.connected(3, 6) &&  uf.connected(7, 8);        
        
        assert uf.find(0) == 0;
        assert uf.find(3) == 3;
        assert uf.find(6) == 6;
        assert uf.find(7) == 7;
    }
}
