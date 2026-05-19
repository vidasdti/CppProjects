#include "../include/Algorithms.h"
#include "../include/FileManager.h"
#include "../include/Utilities.h"

#include <iostream>
#include <string>

using namespace std;

/*
=========================================================
                    Menu UI
=========================================================
*/
void printMenu() {

    cout << "\n====== SMART GRAPH ANALYZER ======\n";

    cout << "1. Add Edge\n";
    cout << "2. Remove Edge\n";
    cout << "3. Display Graph\n";
    cout << "4. Run Kruskal MST\n";
    cout << "5. Run Prim MST\n";
    cout << "6. Run Dijkstra\n";
    cout << "7. Generate Analytics\n";
    cout << "8. Export DOT File\n";
    cout << "9. Generate Random Graph\n";
    cout << "10. Save Graph\n";
    cout << "11. Load Graph\n";
    cout << "0. Exit\n";

    cout << "==================================\n";

    cout << "Choice: ";
}

/*
=========================================================
                        Main
=========================================================
*/
int main() {

    /*
    =====================================================
        Create graph with default size
    =====================================================
    */
    Graph graph(10);

    int choice;

    do {

        printMenu();

        cin >> choice;

        /*
        =================================================
                        Add Edge
        =================================================
        */
        if (choice == 1) {

            int source;
            int destination;
            int weight;

            cout << "\nSource: ";
            cin >> source;

            cout << "Destination: ";
            cin >> destination;

            cout << "Weight: ";
            cin >> weight;

            graph.addEdge(
                source,
                destination,
                weight
            );
        }

        /*
        =================================================
                    Remove Edge
        =================================================
        */
        else if (choice == 2) {

            int source;
            int destination;

            cout << "\nSource: ";
            cin >> source;

            cout << "Destination: ";
            cin >> destination;

            graph.removeEdge(
                source,
                destination
            );
        }

        /*
        =================================================
                    Display Graph
        =================================================
        */
        else if (choice == 3) {

            graph.displayGraph();
        }

        /*
        =================================================
                    Run Kruskal
        =================================================
        */
        else if (choice == 4) {

            Algorithms::runKruskal(graph);
        }

        /*
        =================================================
                    Run Prim
        =================================================
        */
        else if (choice == 5) {

            Algorithms::runPrim(graph);
        }

        /*
        =================================================
                    Run Dijkstra
        =================================================
        */
        else if (choice == 6) {

            int startNode;

            cout << "\nStart Node: ";
            cin >> startNode;

            Algorithms::runDijkstra(
                graph,
                startNode
            );
        }

        /*
        =================================================
                Generate Analytics
        =================================================
        */
        else if (choice == 7) {

            Algorithms::generateAnalytics(graph);
        }

        /*
        =================================================
                    Export DOT
        =================================================
        */
        else if (choice == 8) {

            Algorithms::exportDOT(
                graph,
                "output/graph_visualization.dot"
            );
        }

        /*
        =================================================
                Generate Random Graph
        =================================================
        */
        else if (choice == 9) {

            int vertices;
            int edges;

            cout << "\nVertices: ";
            cin >> vertices;

            cout << "Edges: ";
            cin >> edges;

            graph = Graph(vertices);

            Utilities::generateRandomGraph(
                graph,
                vertices,
                edges
            );
        }

        /*
        =================================================
                    Save Graph
        =================================================
        */
        else if (choice == 10) {

            string filename;

            cout << "\nEnter filename: ";
            cin >> filename;

            FileManager::saveGraph(
                graph,
                filename
            );
        }

        /*
        =================================================
                    Load Graph
        =================================================
        */
        else if (choice == 11) {

            string filename;

            cout << "\nEnter filename: ";
            cin >> filename;

            FileManager::loadGraph(
                graph,
                filename
            );
        }

        /*
        =================================================
                        Exit
        =================================================
        */
        else if (choice == 0) {

            cout << "\nExiting system...\n";
        }

        /*
        =================================================
                    Invalid Input
        =================================================
        */
        else {

            cout << "\nInvalid option.\n";
        }

    } while (choice != 0);

    return 0;
}