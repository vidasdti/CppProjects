#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {

public:

    int data;
    Node* next;

    Node(int value)
        : data(value),
          next(nullptr) {}
};

class LinkedList {

private:

    Node* head;

public:

    LinkedList()
        : head(nullptr) {}

    Node* getHead() const {
        return head;
    }

    void insert(int value) {

        Node* newNode =
            new Node(value);

        if (head == nullptr) {

            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    void createLoop(int position) {

        if (head == nullptr) {
            return;
        }

        Node* loopNode = nullptr;
        Node* tail = head;

        int index = 0;

        while (tail->next != nullptr) {

            if (index == position) {
                loopNode = tail;
            }

            tail = tail->next;
            index++;
        }

        if (index == position) {
            loopNode = tail;
        }

        if (loopNode != nullptr) {

            tail->next = loopNode;

            cout
                << "Loop created at node position "
                << position
                << ".\n";
        }
    }

    void displayLimited(
        int limit = 20
    ) const {

        Node* current = head;

        int counter = 0;

        cout << "\nLinked List Preview:\n";

        while (
            current != nullptr &&
            counter < limit
        ) {

            cout
                << current->data
                << " -> ";

            current = current->next;

            counter++;
        }

        cout << "...\n";
    }

    ~LinkedList() {

        unordered_set<Node*> deleted;

        Node* current = head;

        while (
            current != nullptr &&
            deleted.find(current)
            == deleted.end()
        ) {

            deleted.insert(current);

            Node* nextNode =
                current->next;

            delete current;

            current = nextNode;
        }
    }
};

class CycleDetector {

public:

    // Detect cycle using Floyd Algorithm
    static bool detectUsingFloyd(
        Node* head
    ) {

        Node* slow = head;
        Node* fast = head;

        while (
            fast != nullptr &&
            fast->next != nullptr
        ) {

            slow = slow->next;

            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    // Find first node of the cycle
    static Node* findCycleStart(
        Node* head
    ) {

        Node* slow = head;
        Node* fast = head;

        bool hasCycle = false;

        while (
            fast != nullptr &&
            fast->next != nullptr
        ) {

            slow = slow->next;

            fast = fast->next->next;

            if (slow == fast) {

                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) {
            return nullptr;
        }

        slow = head;

        while (slow != fast) {

            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main() {

    ifstream file("input.txt");

    if (!file) {

        cout
            << "Failed to open input.txt\n";

        return 1;
    }

    LinkedList list;

    string line;

    getline(file, line);

    stringstream ss(line);

    int value;

    while (ss >> value) {

        list.insert(value);
    }

    int loopPosition;

    file >> loopPosition;

    cout
        << "Linked list loaded from file.\n";

    list.createLoop(loopPosition);

    list.displayLimited();

    bool found =
        CycleDetector::detectUsingFloyd(
            list.getHead()
        );

    if (found) {

        cout
            << "\nLoop detected successfully.\n";

        Node* startNode =
            CycleDetector::findCycleStart(
                list.getHead()
            );

        cout
            << "Cycle starts at node value: "
            << startNode->data
            << '\n';
    }
    else {

        cout
            << "\nNo loop found.\n";
    }

    return 0;
}