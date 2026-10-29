Smart City Road Network using Kruskal's Algorithm

Problem Statement

To develop a smart city road network with construction costs and apply Kruskal's Algorithm to connect all junctions at minimum total cost.

Objective

To implement Kruskal's Algorithm in C++ to connect road junctions with minimum construction cost using a Minimum Spanning Tree.

Data Structure Used

- Graph
- Edge List
- Disjoint Set (Union-Find)
- Vector

Operations

- Enter the number of road junctions.
- Enter unique names of junctions.
- Enter possible roads with their construction costs.
- Sort roads according to their costs.
- Select minimum-cost roads without forming cycles.
- Display the selected roads.
- Display the minimum total construction cost.

Concepts Used

- C++
- Graph
- Kruskal's Algorithm
- Minimum Spanning Tree (MST)
- Disjoint Set
- Union-Find
- Vectors
- Structures
- Greedy Algorithm
- Sorting

Algorithm

1. Start the program.
2. Enter the number of road junctions and their unique names.
3. Enter the number of possible roads.
4. Enter the connected junctions and construction cost of each road.
5. Sort all roads in increasing order of cost.
6. Initialize the Disjoint Set for all junctions.
7. Select the road with the lowest cost that does not form a cycle.
8. Repeat until all junctions are connected or no more roads can be selected.
9. Display the selected roads and their construction costs.
10. Display the minimum total cost if all junctions are connected.
11. If the network is disconnected, display an appropriate message.
12. Stop the program.

Advantages

- Minimizes the total road construction cost.
- Connects junctions using minimum-cost roads.
- Avoids cycles in the selected network.
- Uses the Disjoint Set to check connectivity.
- Helps in planning cost-effective road networks.

Conclusion

The Smart City Road Network demonstrates the implementation of Kruskal's Algorithm using a graph in C++. It selects roads with minimum construction costs to connect all junctions without forming cycles. The project helps in understanding Minimum Spanning Trees, greedy algorithms, sorting, and the Disjoint Set data structure.
