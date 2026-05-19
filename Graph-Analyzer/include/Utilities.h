#ifndef UTILITIES_H
#define UTILITIES_H

#include "Graph.h"

class Utilities {

public:

    static void generateRandomGraph(
        Graph& graph,
        int vertices,
        int edges
    );
};

#endif