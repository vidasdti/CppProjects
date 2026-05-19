#include "../include/Utilities.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void Utilities::generateRandomGraph(
    Graph& graph,
    int vertices,
    int edgeCount
) {

    srand(static_cast<unsigned>(time(0)));

    // Clear old graph
    graph.clear();

    // Set new vertex count
    graph.setVertices(vertices);

    int addedEdges = 0;

    /*
    ============================================
        Maximum Possible Edges
        For Undirected Graph:
        n * (n - 1) / 2
    ============================================
    */
    int maxEdges =
        (vertices * (vertices - 1)) / 2;

    if (edgeCount > maxEdges) {

        cout << "\n[WARNING] Too many edges requested.\n";

        edgeCount = maxEdges;
    }

    /*
    ============================================
        Generate Unique Random Edges
    ============================================
    */
    while (addedEdges < edgeCount) {

        int source =
            rand() % vertices;

        int destination =
            rand() % vertices;

        int weight =
            rand() % 100 + 1;

        // Prevent self-loop
        if (source == destination) {
            continue;
        }

        /*
        ========================================
            Add edge only if unique
        ========================================
        */
        bool success =
            graph.addEdge(
                source,
                destination,
                weight
            );

        if (success) {
            addedEdges++;
        }
    }

    cout << "\n[INFO] Random graph generated successfully.\n";
}