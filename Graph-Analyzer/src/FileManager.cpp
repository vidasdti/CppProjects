#include "../include/FileManager.h"

#include <fstream>
#include <iostream>

using namespace std;

/*
=========================================================
                    Save Graph
=========================================================
Saves graph data into a text file.
*/
bool FileManager::saveGraph(
    const Graph& graph,
    const string& filename
) {

    ofstream file(filename.c_str());

    if (!file.is_open()) {

        cout << "\n[ERROR] Failed to save file.\n";
        return false;
    }

    /*
    =====================================================
        Save number of vertices
    =====================================================
    */
    file << graph.getVertices()
         << '\n';

    /*
    =====================================================
        Save edges
    =====================================================
    */
    vector<Edge> edges =
        graph.getEdges();

    for (size_t i = 0; i < edges.size(); ++i) {

        file << edges[i].source << ' '
             << edges[i].destination << ' '
             << edges[i].weight << '\n';
    }

    file.close();

    cout << "\n[INFO] Graph saved successfully.\n";

    return true;
}

/*
=========================================================
                    Load Graph
=========================================================
Loads graph data from text file.
*/
bool FileManager::loadGraph(
    Graph& graph,
    const string& filename
) {

    ifstream file(filename.c_str());

    if (!file.is_open()) {

        cout << "\n[ERROR] Failed to open file.\n";
        return false;
    }

    /*
    =====================================================
        Read vertices count
    =====================================================
    */
    int vertices;

    file >> vertices;

    /*
    =====================================================
        Rebuild graph
    =====================================================
    */
    graph = Graph(vertices);

    /*
    =====================================================
        Read edges
    =====================================================
    */
    int source;
    int destination;
    int weight;

    while (
        file >> source
             >> destination
             >> weight
    ) {

        graph.addEdge(
            source,
            destination,
            weight
        );
    }

    file.close();

    cout << "\n[INFO] Graph loaded successfully.\n";

    return true;
}