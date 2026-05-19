#include "../include/Graph.h"

#include <iostream>

using namespace std;

/*
=========================================================
                    Constructor
=========================================================
*/
Graph::Graph(int vertices)
    : vertices(vertices) {}

/*
=========================================================
                    Set Vertices
=========================================================
*/
void Graph::setVertices(int vertices) {

    this->vertices = vertices;
}

/*
=========================================================
                    Get Vertices
=========================================================
*/
int Graph::getVertices() const {

    return vertices;
}

/*
=========================================================
                    Get Edges
=========================================================
*/
const vector<Edge>& Graph::getEdges() const {

    return edges;
}

/*
=========================================================
                    Clear Graph
=========================================================
Removes all edges from graph.
=========================================================
*/
void Graph::clear() {

    edges.clear();
}

/*
=========================================================
                    Edge Exists
=========================================================
Checks if edge already exists.
Since graph is undirected:
0 -> 1 == 1 -> 0
=========================================================
*/
bool Graph::edgeExists(
    int source,
    int destination
) const {

    for (size_t i = 0; i < edges.size(); ++i) {

        if (

            (
                edges[i].source == source &&
                edges[i].destination == destination
            )

            ||

            (
                edges[i].source == destination &&
                edges[i].destination == source
            )
        ) {

            return true;
        }
    }

    return false;
}

/*
=========================================================
                    Add Edge
=========================================================
Adds weighted undirected edge.

Validation:
- Invalid vertices
- Self-loops
- Duplicate edges
=========================================================
*/
bool Graph::addEdge(
    int source,
    int destination,
    int weight
) {

    /*
    =====================================================
        Vertex validation
    =====================================================
    */
    if (
        source < 0 ||
        destination < 0 ||
        source >= vertices ||
        destination >= vertices
    ) {

        cout << "[ERROR] Invalid vertices.\n";

        return false;
    }

    /*
    =====================================================
        Prevent self-loop
    =====================================================
    */
    if (source == destination) {

        cout << "[ERROR] Self-loop detected.\n";

        return false;
    }

    /*
    =====================================================
        Prevent duplicate edges
    =====================================================
    */
    if (edgeExists(source, destination)) {
        return false;
    }

    /*
    =====================================================
        Create edge
    =====================================================
    */
    Edge edge;

    edge.source = source;
    edge.destination = destination;
    edge.weight = weight;

    edges.push_back(edge);

    return true;
}

/*
=========================================================
                    Remove Edge
=========================================================
Removes edge if exists.
=========================================================
*/
bool Graph::removeEdge(
    int source,
    int destination
) {

    for (size_t i = 0; i < edges.size(); ++i) {

        if (

            (
                edges[i].source == source &&
                edges[i].destination == destination
            )

            ||

            (
                edges[i].source == destination &&
                edges[i].destination == source
            )
        ) {

            edges.erase(
                edges.begin() + i
            );

            return true;
        }
    }

    cout << "[ERROR] Edge not found.\n";

    return false;
}

/*
=========================================================
                    Display Graph
=========================================================
Displays all graph edges.
=========================================================
*/
void Graph::displayGraph() const {

    cout << "\n========== GRAPH ==========\n";

    /*
    =====================================================
        Empty graph check
    =====================================================
    */
    if (edges.empty()) {

        cout << "Graph is empty.\n";

        cout << "===========================\n";

        return;
    }

    /*
    =====================================================
        Print edges
    =====================================================
    */
    for (size_t i = 0; i < edges.size(); ++i) {

        cout << edges[i].source
             << " --> "
             << edges[i].destination
             << " | weight = "
             << edges[i].weight
             << '\n';
    }

    cout << "===========================\n";
}

/*
=========================================================
                Build Adjacency List
=========================================================
Converts edge list into adjacency list.

adjacency[node] =
    pair<neighbor, weight>
=========================================================
*/
vector<
    vector<
        pair<int, int>
    >
>
Graph::buildAdjacencyList() const {

    vector<
        vector<
            pair<int, int>
        >
    > adjacency(vertices);

    /*
    =====================================================
        Build adjacency structure
    =====================================================
    */
    for (size_t i = 0; i < edges.size(); ++i) {

        int source =
            edges[i].source;

        int destination =
            edges[i].destination;

        int weight =
            edges[i].weight;

        /*
        =================================================
            Undirected graph:
            Add both directions
        =================================================
        */
        adjacency[source].push_back(
            make_pair(
                destination,
                weight
            )
        );

        adjacency[destination].push_back(
            make_pair(
                source,
                weight
            )
        );
    }

    return adjacency;
}