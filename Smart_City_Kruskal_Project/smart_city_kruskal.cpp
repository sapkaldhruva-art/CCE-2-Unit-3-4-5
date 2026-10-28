#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAXV 50
#define MAXE 500

struct Road
{
    int from, to, cost;
};

class SmartCity
{
    string junction[MAXV];
    Road roads[MAXE];
    int vertexCount, roadCount;

    int findRoot(int parent[], int x)
    {
        if (parent[x] == x)
            return x;
        return findRoot(parent, parent[x]);
    }

    bool joinSets(int parent[], int rankSet[], int a, int b)
    {
        a = findRoot(parent, a);
        b = findRoot(parent, b);

        if (a == b)
            return false;

        if (rankSet[a] < rankSet[b])
            parent[a] = b;
        else if (rankSet[a] > rankSet[b])
            parent[b] = a;
        else
        {
            parent[b] = a;
            rankSet[a]++;
        }
        return true;
    }

public:
    SmartCity()
    {
        vertexCount = 0;
        roadCount = 0;
    }

    void addJunction()
    {
        if (vertexCount >= MAXV)
        {
            cout << "Junction limit reached!\n";
            return;
        }

        cin.ignore(1000, '\n');
        cout << "Enter junction name: ";
        getline(cin, junction[vertexCount]);

        if (junction[vertexCount].empty())
        {
            cout << "Junction name cannot be empty!\n";
            return;
        }

        cout << "Junction added with ID: " << vertexCount << endl;
        vertexCount++;
    }

    void displayJunctions()
    {
        if (vertexCount == 0)
        {
            cout << "No junctions added yet!\n";
            return;
        }

        cout << "\n--- Smart City Junctions ---\n";
        for (int i = 0; i < vertexCount; i++)
            cout << i << " : " << junction[i] << endl;
    }

    void addRoad()
    {
        if (vertexCount < 2)
        {
            cout << "Add at least two junctions first!\n";
            return;
        }

        if (roadCount >= MAXE)
        {
            cout << "Road limit reached!\n";
            return;
        }

        int a, b, cost;
        displayJunctions();

        cout << "Enter first junction ID: ";
        cin >> a;
        cout << "Enter second junction ID: ";
        cin >> b;

        if (a < 0 || a >= vertexCount || b < 0 ||
            b >= vertexCount || a == b)
        {
            cout << "Invalid junction IDs!\n";
            return;
        }

        cout << "Enter road construction cost: ";
        cin >> cost;

        if (cost < 0)
        {
            cout << "Cost cannot be negative!\n";
            return;
        }

        for (int i = 0; i < roadCount; i++)
        {
            if ((roads[i].from == a && roads[i].to == b) ||
                (roads[i].from == b && roads[i].to == a))
            {
                cout << "Road between these junctions already exists!\n";
                return;
            }
        }

        roads[roadCount].from = a;
        roads[roadCount].to = b;
        roads[roadCount].cost = cost;
        roadCount++;

        cout << "Road added successfully!\n";
    }

    void displayRoads()
    {
        if (roadCount == 0)
        {
            cout << "No roads added yet!\n";
            return;
        }

        cout << "\n--- Available Roads ---\n";
        cout << left << setw(24) << "From Junction"
             << setw(24) << "To Junction" << "Cost\n";

        for (int i = 0; i < roadCount; i++)
        {
            cout << left << setw(24) << junction[roads[i].from]
                 << setw(24) << junction[roads[i].to]
                 << roads[i].cost << endl;
        }
    }

    void kruskalMST()
    {
        if (vertexCount == 0)
        {
            cout << "Add junctions first!\n";
            return;
        }

        if (vertexCount == 1)
        {
            cout << "Only one junction exists. No road is required.\n";
            return;
        }

        if (roadCount == 0)
        {
            cout << "No roads available to connect the junctions!\n";
            return;
        }

        Road sorted[MAXE];
        for (int i = 0; i < roadCount; i++)
            sorted[i] = roads[i];

        // Bubble sort by construction cost for older Dev-C++ compatibility.
        for (int i = 0; i < roadCount - 1; i++)
        {
            for (int j = 0; j < roadCount - i - 1; j++)
            {
                if (sorted[j].cost > sorted[j + 1].cost)
                {
                    Road temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        int parent[MAXV], rankSet[MAXV];
        for (int i = 0; i < vertexCount; i++)
        {
            parent[i] = i;
            rankSet[i] = 0;
        }

        int selected = 0;
        long totalCost = 0;

        cout << "\n--- Minimum-Cost Smart City Road Network ---\n";
        cout << left << setw(24) << "From Junction"
             << setw(24) << "To Junction" << "Cost\n";

        for (int i = 0; i < roadCount && selected < vertexCount - 1; i++)
        {
            if (joinSets(parent, rankSet, sorted[i].from, sorted[i].to))
            {
                cout << left << setw(24) << junction[sorted[i].from]
                     << setw(24) << junction[sorted[i].to]
                     << sorted[i].cost << endl;

                totalCost += sorted[i].cost;
                selected++;
            }
        }

        if (selected == vertexCount - 1)
            cout << "\nAll junctions are connected.\n";
        else
        {
            cout << "\nThe road network is disconnected.\n";
            cout << "Not all junctions can be connected with the roads entered.\n";
        }

        cout << "Total minimum construction cost: " << totalCost << endl;
        cout << "Roads selected: " << selected << endl;
    }
};

int main()
{
    SmartCity city;
    int choice;

    do
    {
        cout << "\n===== SMART CITY ROAD NETWORK =====\n";
        cout << "1. Add Junction\n";
        cout << "2. Add Road and Construction Cost\n";
        cout << "3. Display Junctions\n";
        cout << "4. Display Available Roads\n";
        cout << "5. Find Minimum-Cost Network (Kruskal)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: city.addJunction(); break;
            case 2: city.addRoad(); break;
            case 3: city.displayJunctions(); break;
            case 4: city.displayRoads(); break;
            case 5: city.kruskalMST(); break;
            case 6: cout << "Program terminated.\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
