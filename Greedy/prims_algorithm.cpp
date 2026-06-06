#include <bits/stdc++.h>
using namespace std;

int V;

int selectMinVertex(vector<int>& value, vector<bool>& setMST)
{
    int minimum = INT_MAX;
    int vertex = -1;

    for(int i = 0; i < V; i++)
    {
        if(!setMST[i] && value[i] < minimum)
        {
            minimum = value[i];
            vertex = i;
        }
    }

    return vertex;
}

void findMST(vector<vector<int>>& graph)
{
    vector<int> parent(V, -1);
    vector<int> value(V, INT_MAX);
    vector<bool> setMST(V, false);

    value[0] = 0; // Start from vertex 0

    for(int i = 0; i < V - 1; i++)
    {
        int U = selectMinVertex(value, setMST);

        if(U == -1)
            break;

        setMST[U] = true;

        for(int j = 0; j < V; j++)
        {
            if(graph[U][j] != 0 &&
               !setMST[j] &&
               graph[U][j] < value[j])
            {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }

    // Check if graph is disconnected
    for(int i = 1; i < V; i++)
    {
        if(parent[i] == -1)
        {
            cout << "Graph is disconnected. MST is not possible.\n";
            return;
        }
    }

    int totalCost = 0;

    cout << "\nEdges in MST:\n";

    for(int i = 1; i < V; i++)
    {
        cout << parent[i] << " -> "
             << i << "    Weight = "
             << graph[parent[i]][i] << '\n';

        totalCost += graph[parent[i]][i];
    }

    cout << "\nTotal MST Cost = " << totalCost << '\n';
}

int main()
{
    int E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter edges (u v w):\n";

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w; // Undirected Graph
    }

    findMST(graph);

    return 0;
}

/*
Input: 

Enter number of vertices: 6
Enter number of edges: 8
Enter edges (u v w):
0 1 4
0 2 6
1 2 6
1 3 3
1 4 4
2 3 1
3 4 2
3 5 3

Output: 

Edges in MST:
0 -> 1    Weight = 4
3 -> 2    Weight = 1
1 -> 3    Weight = 3
3 -> 4    Weight = 2
3 -> 5    Weight = 3

Total MST Cost = 13
*/