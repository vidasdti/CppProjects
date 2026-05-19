#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

struct Edge {

    int source;
    int destination;
    int weight;
};

class Graph {

private:

    int vertices;

    std::vector<Edge> edges;

public:

    Graph(int vertices = 0);

    void setVertices(int vertices);

    int getVertices() const;

    const std::vector<Edge>& getEdges() const;

    bool addEdge(
        int source,
        int destination,
        int weight
    );

    bool removeEdge(
        int source,
        int destination
    );

    void displayGraph() const;

    bool edgeExists(
        int source,
        int destination
    ) const;

    void clear();
    
    std::vector<
        std::vector<
            std::pair<int, int>
        >
    > buildAdjacencyList() const;
};

#endif