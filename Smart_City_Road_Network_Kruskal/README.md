# Smart City Road Network using Kruskal's Algorithm

C++98-compatible Dev-C++ version. Road junctions are vertices, roads are edges, and construction costs are edge weights.

## Run
Open `main.cpp` in Dev-C++ and select **Execute > Compile & Run**.

## Sample input
```text
6
J1
J2
J3
J4
J5
J6
9
J1 J2 4
J1 J3 3
J2 J3 1
J2 J4 2
J3 J4 4
J3 J5 5
J4 J5 2
J4 J6 7
J5 J6 3
```

Expected minimum total construction cost: `11` (illustrative units).

## Algorithm
Sort roads by cost and use Union-Find to avoid cycles. Select roads until `V-1` roads connect all junctions.

## Complexity
`O(E log E)` time.
