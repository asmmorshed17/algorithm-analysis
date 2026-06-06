 #include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

vector<int> parent, Rank;

int findParent(int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]); // Path Compression
}

void unionSet(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if(a != b)
    {
        if(Rank[a] < Rank[b])
            swap(a, b);

        parent[b] = a;

        if(Rank[a] == Rank[b])
            Rank[a]++;
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v w):\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    parent.resize(V);
    Rank.assign(V, 0);

    for(int i = 0; i < V; i++)
        parent[i] = i;

    int mstCost = 0;
    int edgeCount = 0;

    cout << "\nEdges in MST:\n";

    for(auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        // Check for cycle
        if(findParent(u) != findParent(v))
        {
            unionSet(u, v);

            cout << u << " -> "
                 << v << "   Weight = "
                 << w << '\n';

            mstCost += w;
            edgeCount++;

            if(edgeCount == V - 1)
                break;
        }
    }

    if(edgeCount != V - 1)
    {
        cout << "\nGraph is disconnected. MST is not possible.\n";
        return 0;
    }

    cout << "\nTotal MST Cost = "
         << mstCost << '\n';

    return 0;
}

/*
Enter number of vertices: 6
Enter number of edges: 9
Enter edges (u v w):
0 1 1
0 2 5
0 4 9
1 2 3
1 3 2
2 3 3
2 5 8
3 5 7
4 1 4

Edges in MST:
0 -> 1   Weight = 1
1 -> 3   Weight = 2
1 -> 2   Weight = 3
4 -> 1   Weight = 4
3 -> 5   Weight = 7

Total MST Cost = 17*/

/*
Sorted Edges: 
0-1 = 1
1-3 = 2
1-2 = 3
2-3 = 3
4-1 = 4
0-2 = 5
3-5 = 7
2-5 = 8
0-4 = 9
*/




/*
Algorithm: Kruskal's Algorithm
Technique: Greedy + DSU (Disjoint Set Union)
Cycle Detection: findParent(u) != findParent(v)
Path Compression: parent[x] = findParent(parent[x])
Union by Rank: Rank[]
Time Complexity: O(ElogE)
Space Complexity: O(V + E
*/