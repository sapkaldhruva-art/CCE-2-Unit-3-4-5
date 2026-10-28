# Smart City Road Network Using Kruskal's Algorithm

## Problem Statement
Develop a smart city road network with construction costs and apply Kruskal's algorithm to connect all junctions at minimum total cost.

## Project Overview
This menu-driven C++ application represents city junctions as vertices and possible roads as weighted edges. Each edge stores the construction cost. Kruskal's algorithm sorts roads by cost and selects the least expensive roads that do not form a cycle. If the graph is connected, the selected roads form a Minimum Spanning Tree (MST).

## Features
1. Add junctions.
2. Add roads with construction costs.
3. Display all junctions.
4. Display available roads and costs.
5. Calculate a minimum-cost road network using Kruskal's algorithm.
6. Show total construction cost and selected road count.
7. Detect when the entered network cannot connect every junction.

## DSA Concepts
- Weighted, undirected graph
- Edge-list representation
- Sorting
- Disjoint Set Union (Union-Find)
- Cycle detection
- Minimum Spanning Tree

## Run in Dev-C++
1. Extract the ZIP file.
2. Open `smart_city_kruskal.cpp` in Dev-C++.
3. Select **Execute -> Compile & Run**.
4. Add all junctions.
5. Add possible roads with their construction costs.
6. Select option 5 to calculate the minimum-cost network.

The source uses bubble sort instead of lambda expressions, so it is suitable for older Dev-C++ compiler configurations.

## Sample Network
Add junctions:
- ID 0: City Centre
- ID 1: North Zone
- ID 2: South Zone
- ID 3: East Zone
- ID 4: West Zone

Add roads (first ID, second ID, cost):
- 0, 1, 4
- 0, 2, 3
- 1, 2, 2
- 1, 3, 5
- 2, 3, 3
- 2, 4, 6
- 3, 4, 4

Expected minimum-cost roads:
- North Zone -- South Zone: 2
- City Centre -- South Zone: 3
- South Zone -- East Zone: 3
- East Zone -- West Zone: 4

Expected total construction cost: 12 cost units.

## Complexity
This beginner-friendly version uses bubble sort, so sorting takes O(E^2) time. Union-Find operations are nearly constant amortized time. Space complexity is O(V + E).

## Note
This is an educational model. Costs are user-entered values and are not actual construction estimates.
