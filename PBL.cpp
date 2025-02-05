#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
using namespace std;


class Destination {
public:
    string name;
    string details;
    Destination(string n, string d) : name(n), details(d) {}
};
struct TreeNode {
    Destination* dest;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Destination* d) : dest(d), left(nullptr), right(nullptr) {}
};

class DestinationTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, Destination* dest) {
        if (!node) return new TreeNode(dest);
        if (dest->name < node->dest->name) {
            node->left = insert(node->left, dest);
        } else {
            node->right = insert(node->right, dest);
        }
        return node;
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->dest->name << " - " << node->dest->details << endl;
        inorder(node->right);
    }

public:
    DestinationTree() : root(nullptr) {}
    
    void addDestination(Destination* dest) {
        root = insert(root, dest);
    }

    void displayDestinations() {
        inorder(root);
    }
};

class TravelGraph {
private:
    map<string, vector<string>> adjList;

public:
    void addRoute(string from, string to) {
        adjList[from].push_back(to);
        adjList[to].push_back(from); // Assuming bidirectional routes
    }

    void displayRoutes() {
        for (auto& pair : adjList) {
            cout << pair.first << " -> ";
            for (auto& dest : pair.second) {
                cout << dest << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    // Data structures
    stack<Destination*> undoStack;
    queue<Destination*> upcomingDestinations;
    list<Destination*> allDestinations;
    DestinationTree destinationTree;
    TravelGraph travelGraph;

    // Example interaction
    Destination* d1 = new Destination("Paris", "Eiffel Tower, Louvre Museum");
    Destination* d2 = new Destination("London", "Big Ben, Tower Bridge");
    Destination* d3 = new Destination("Rome", "Colosseum, Vatican City");

    // Add destinations
    allDestinations.push_back(d1);
    allDestinations.push_back(d2);
    allDestinations.push_back(d3);

    destinationTree.addDestination(d1);
    destinationTree.addDestination(d2);
    destinationTree.addDestination(d3);

    undoStack.push(d1);
    undoStack.push(d2);
    undoStack.push(d3);

    upcomingDestinations.push(d1);
    upcomingDestinations.push(d2);
    upcomingDestinations.push(d3);

    travelGraph.addRoute("Paris", "London");
    travelGraph.addRoute("London", "Rome");

    // Display options
    cout << "All Destinations:" << endl;
    for (auto& dest : allDestinations) {
        cout << dest->name << " - " << dest->details << endl;
    }

    cout << "\nPlanned Routes:" << endl;
    travelGraph.displayRoutes();

    cout << "\nDestinations in Order:" << endl;
    while (!upcomingDestinations.empty()) {
        auto dest = upcomingDestinations.front();
        cout << dest->name << endl;
        upcomingDestinations.pop();
    }

    cout << "\nAvailable Destinations (Tree Traversal):" << endl;
    destinationTree.displayDestinations();

    return 0;
}
