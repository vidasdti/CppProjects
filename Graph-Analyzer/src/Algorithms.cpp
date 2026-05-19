#include "../include/Algorithms.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>

using namespace std;

/*
=========================================================
                Disjoint Set Union
=========================================================
Used in Kruskal algorithm to detect cycles.
*/
class DisjointSet {

private:

    vector<int> parent;
    vector<int> rankSet;

public:

    explicit DisjointSet(int n) {

        parent.resize(n);
        rankSet.resize(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    /*
    =====================================================
                        Find
    =====================================================
    Path Compression Optimization
    */
    int find(int node) {

        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }

    /*
    =====================================================
                        Union
    =====================================================
    Union by Rank Optimization
    */
    void unite(int u, int v) {

        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) {
            return;
        }

        if (rankSet[rootU] < rankSet[rootV]) {
            parent[rootU] = rootV;
        }
        else if (rankSet[rootU] > rankSet[rootV]) {
            parent[rootV] = rootU;
        }
        else {
            parent[rootV] = rootU;
            rankSet[rootU]++;
        }
    }
};

/*
=========================================================
                Kruskal MST Algorithm
=========================================================
Builds Minimum Spanning Tree using edge sorting.
*/
void Algorithms::runKruskal(
    const Graph& graph
) {

    vector<Edge> edges =
        graph.getEdges();

    if (edges.empty()) {

        cout << "\nGraph is empty.\n";
        return;
    }

    sort(
        edges.begin(),
        edges.end(),
        [](const Edge& a,
           const Edge& b) {

            return a.weight < b.weight;
        }
    );

    DisjointSet dsu(
        graph.getVertices()
    );

    int totalCost = 0;

    cout << "\n=========== KRUSKAL MST ===========\n";

    for (size_t i = 0; i < edges.size(); ++i) {

        int u = edges[i].source;
        int v = edges[i].destination;

        /*
        =============================================
            Prevent cycle creation
        =============================================
        */
        if (
            dsu.find(u) != dsu.find(v)
        ) {

            dsu.unite(u, v);

            totalCost += edges[i].weight;

            cout << u
                 << " --> "
                 << v
                 << " | weight = "
                 << edges[i].weight
                 << '\n';
        }
    }

    cout << "\nTotal MST Cost: "
         << totalCost
         << '\n';

    cout << "===================================\n";
}

/*
=========================================================
                Prim MST Algorithm
=========================================================
Uses Min Heap Priority Queue.
*/
void Algorithms::runPrim(
    const Graph& graph
) {

    vector<
        vector<
            pair<int, int>
        >
    > adjacency =
        graph.buildAdjacencyList();

    int vertices =
        graph.getVertices();

    if (vertices == 0) {

        cout << "\nGraph is empty.\n";
        return;
    }

    /*
    =====================================================
        Min Heap
        pair<weight, node>
    =====================================================
    */
    priority_queue<
        pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> >
    > pq;

    vector<bool>
    visited(vertices, false);

    /*
    =====================================================
        Start from node 0
    =====================================================
    */
    pq.push(
        make_pair(0, 0)
    );

    int totalCost = 0;

    cout << "\n============= PRIM MST =============\n";

    while (!pq.empty()) {

        pair<int, int> current =
            pq.top();

        pq.pop();

        int weight =
            current.first;

        int node =
            current.second;

        /*
        =================================================
            Skip already visited nodes
        =================================================
        */
        if (visited[node]) {
            continue;
        }

        visited[node] = true;

        totalCost += weight;

        cout << "Visited Node: "
             << node
             << " | Edge Weight: "
             << weight
             << '\n';

        /*
        =================================================
            Explore adjacent neighbors
        =================================================
        */
        for (
            size_t i = 0;
            i < adjacency[node].size();
            ++i
        ) {

            int nextNode =
                adjacency[node][i].first;

            int nextWeight =
                adjacency[node][i].second;

            if (!visited[nextNode]) {

                pq.push(
                    make_pair(
                        nextWeight,
                        nextNode
                    )
                );
            }
        }
    }

    cout << "\nTotal MST Cost: "
         << totalCost
         << '\n';

    cout << "====================================\n";
}

/*
=========================================================
                Dijkstra Algorithm
=========================================================
Finds shortest paths from start node.
*/
void Algorithms::runDijkstra(
    const Graph& graph,
    int startNode
) {

    vector<
        vector<
            pair<int, int>
        >
    > adjacency =
        graph.buildAdjacencyList();

    int vertices =
        graph.getVertices();

    if (
        startNode < 0 ||
        startNode >= vertices
    ) {

        cout << "\nInvalid start node.\n";
        return;
    }

    /*
    =====================================================
        Initialize distances
    =====================================================
    */
    vector<int>
    distance(
        vertices,
        numeric_limits<int>::max()
    );

    distance[startNode] = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> >
    > pq;

    pq.push(
        make_pair(0, startNode)
    );

    /*
    =====================================================
        Main Dijkstra Loop
    =====================================================
    */
    while (!pq.empty()) {

        pair<int, int> current =
            pq.top();

        pq.pop();

        int node =
            current.second;

        int dist =
            current.first;

        /*
        =================================================
            Ignore outdated distances
        =================================================
        */
        if (dist > distance[node]) {
            continue;
        }

        for (
            size_t i = 0;
            i < adjacency[node].size();
            ++i
        ) {

            int nextNode =
                adjacency[node][i].first;

            int weight =
                adjacency[node][i].second;

            /*
            =============================================
                Relaxation step
            =============================================
            */
            if (
                dist + weight <
                distance[nextNode]
            ) {

                distance[nextNode] =
                    dist + weight;

                pq.push(
                    make_pair(
                        distance[nextNode],
                        nextNode
                    )
                );
            }
        }
    }

    cout << "\n=========== DIJKSTRA ===========\n";

    for (
        size_t i = 0;
        i < distance.size();
        ++i
    ) {

        cout << "Shortest Distance to Node "
             << i
             << " = ";

        if (
            distance[i] ==
            numeric_limits<int>::max()
        ) {

            cout << "INF";
        }
        else {

            cout << distance[i];
        }

        cout << '\n';
    }

    cout << "================================\n";
}

/*
=========================================================
                Graph Analytics
=========================================================
Generates graph statistics report.
*/
void Algorithms::generateAnalytics(
    const Graph& graph
) {

    vector<Edge> edges =
        graph.getEdges();

    cout << "\n========== GRAPH ANALYTICS ==========\n";

    cout << "Vertices: "
         << graph.getVertices()
         << '\n';

    cout << "Edges: "
         << edges.size()
         << '\n';

    if (edges.empty()) {

        cout << "Graph is empty.\n";

        cout << "=====================================\n";
        return;
    }

    int totalWeight = 0;

    int minWeight = edges[0].weight;
    int maxWeight = edges[0].weight;

    for (size_t i = 0; i < edges.size(); ++i) {

        totalWeight += edges[i].weight;

        if (edges[i].weight < minWeight) {
            minWeight = edges[i].weight;
        }

        if (edges[i].weight > maxWeight) {
            maxWeight = edges[i].weight;
        }
    }

    double averageWeight =
        static_cast<double>(totalWeight)
        / edges.size();

    cout << "Total Weight: "
         << totalWeight
         << '\n';

    cout << "Average Weight: "
         << fixed
         << setprecision(2)
         << averageWeight
         << '\n';

    cout << "Minimum Edge Weight: "
         << minWeight
         << '\n';

    cout << "Maximum Edge Weight: "
         << maxWeight
         << '\n';

    cout << "=====================================\n";
}

/*
=========================================================
                Export Graph To DOT
=========================================================
Creates GraphViz visualization file.
*/
void Algorithms::exportDOT(
    const Graph& graph,
    const string& filename
) {

    ofstream file(filename.c_str());

    if (!file) {

        cout << "\nFailed to create DOT file.\n";
        return;
    }

    file << "graph G {\n";

    vector<Edge> edges =
        graph.getEdges();

    for (size_t i = 0; i < edges.size(); ++i) {

        file << "    "
             << edges[i].source
             << " -- "
             << edges[i].destination
             << " [label=\""
             << edges[i].weight
             << "\"];\n";
    }

    file << "}\n";

    file.close();

    cout << "\nDOT visualization exported to: "
         << filename
         << '\n';
}