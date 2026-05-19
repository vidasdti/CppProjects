#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Graph.h"
#include <string>

class FileManager {

public:

    static bool saveGraph(
        const Graph& graph,
        const std::string& filename
    );

    static bool loadGraph(
        Graph& graph,
        const std::string& filename
    );
};

#endif