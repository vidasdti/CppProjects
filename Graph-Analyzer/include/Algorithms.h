#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"
#include <string>

class Algorithms {

public:

    static void runKruskal(
        const Graph& graph
    );

    static void runPrim(
        const Graph& graph
    );

    static void runDijkstra(
        const Graph& graph,
        int startNode
    );

    static void runDFS(
        const Graph& graph,
        int startNode
    );

    static void runBFS(
        const Graph& graph,
        int startNode
    );

    static void generateAnalytics(
        const Graph& graph
    );

    static void exportDOT(
        const Graph& graph,
        const std::string& filename
    );
};

#endif