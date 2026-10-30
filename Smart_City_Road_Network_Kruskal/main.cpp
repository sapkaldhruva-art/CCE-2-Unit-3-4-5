
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Structure to store road details
struct Edge {
    int u, v, cost;
};

// Disjoint Set class to detect cycles
class DisjointSet {
private:
    vector<int> parent, rankValue;

public:
    // Initialize each junction as a separate set
    DisjointSet(int n) {
        parent.resize(n);
        rankValue.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find the parent of a junction
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Join two sets if they are different
    bool unite(int a, int b) {
        int x = find(a), y = find(b);

        // Check whether adding the road forms a cycle
        if (x == y) return false;

        // Union by rank
        if (rankValue[x] < rankValue[y])
            parent[x] = y;
        else if (rankValue[x] > rankValue[y])
            parent[y] = x;
        else {
            parent[y] = x;
            rankValue[x]++;
        }

        return true;
    }
};

int main() {
    int n, m;

    // Input number of road junctions
    cout << "Enter number of road junctions: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number.\n";
        return 1;
    }

    // Store unique junction names
    vector<string> names(n);

    cout << "Enter unique names (one word each):\n";

    for (int i = 0; i < n; i++) {
        cout << "Name " << i + 1 << ": ";
        cin >> names[i];

        // Check duplicate junction names
        for (int j = 0; j < i; j++) {
            if (names[i] == names[j]) {
                cout << "Names must be unique.\n";
                return 1;
            }
        }
    }

    // Input number of possible roads
    cout << "Enter number of possible roads: ";
    if (!(cin >> m) || m < 0) {
        cout << "Invalid number of roads.\n";
        return 1;
    }

    // Store all possible roads
    vector<Edge> edges;

    cout << "Enter each road as: name1 name2 cost\n";

    for (int i = 0; i < m; i++) {
        string a, b;
        int cost, u = -1, v = -1;

        // Input road details
        cout << "Road " << i + 1 << ": ";
        cin >> a >> b >> cost;

        // Find index of both junctions
        for (int j = 0; j < n; j++) {
            if (names[j] == a) u = j;
            if (names[j] == b) v = j;
        }

        // Validate junction names
        if (u == -1 || v == -1) {
            cout << "Unknown name.\n";
            return 1;
        }

        // Check construction cost
        if (cost < 0) {
            cout << "Cost cannot be negative.\n";
            return 1;
        }

        // Add road to edge list
        Edge e;
        e.u = u;
        e.v = v;
        e.cost = cost;

        edges.push_back(e);
    }

    // Sort roads in increasing order of cost using Bubble Sort
    for (int i = 0; i < (int)edges.size() - 1; i++) {
        for (int j = 0; j < (int)edges.size() - 1 - i; j++) {

            // Swap roads if cost is in wrong order
            if (edges[j].cost > edges[j + 1].cost) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize Disjoint Set
    DisjointSet ds(n);

    // Store selected MST roads
    vector<Edge> chosen;

    // Calculate minimum total construction cost
    long long total = 0;

    // Apply Kruskal's Algorithm
    for (int i = 0; i < (int)edges.size(); i++) {

        // Select road only if it does not form a cycle
        if (ds.unite(edges[i].u, edges[i].v)) {

            chosen.push_back(edges[i]);
            total += edges[i].cost;

            // Stop when V-1 roads are selected
            if ((int)chosen.size() == n - 1)
                break;
        }
    }

    // Display selected minimum-cost roads
    cout << "\nSelected minimum-cost roads:\n";
    cout << "From\tTo\tCost\n";

    for (int i = 0; i < (int)chosen.size(); i++)
        cout << names[chosen[i].u] << "\t"
             << names[chosen[i].v] << "\t"
             << chosen[i].cost << endl;

    // Check whether all junctions are connected
    if ((int)chosen.size() != n - 1)
        cout << "Cannot connect all locations: network is disconnected.\n";

    // Display minimum total cost
    else
        cout << "Minimum total cost: " << total << endl;

    return 0;
}
