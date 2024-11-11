
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int calculateRouteDistance(const vector<int>& route, const vector<vector<int>>& distanceMatrix) 
{
    int totalDistance = 0;
    int n = route.size();
    for (int i = 0; i < n; i++) {
        totalDistance += distanceMatrix[route[i]][route[(i + 1) % n]];
    }
    return totalDistance;
}

void travelingSalesman(const vector<vector<int>>& distanceMatrix) 
{
    int n = distanceMatrix.size();
    vector<int> cities(n);
    for (int i = 0; i < n; i++)
    {
        cities[i] = i;
    }

    int minDistance = numeric_limits<int>::max();
    vector<int> bestRoute;
    do {
        int currentDistance = calculateRouteDistance(cities, distanceMatrix);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            bestRoute = cities;
        }
    } 
    while (next_permutation(cities.begin(), cities.end()));
    cout << "Shortest route: ";
    for (int city : bestRoute) 
    {
        cout << city << " ";
    }
    cout << "\nMinimum distance: " << minDistance << endl;
}

int main() 
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> distanceMatrix(n, vector<int>(n));

    cout << "Enter the distance matrix (enter 0 for diagonal elements):" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cin >> distanceMatrix[i][j];
        }
    }

    travelingSalesman(distanceMatrix);
    return 0;
}


tudent@student:~$ g++ ts.cpp
student@student:~$ ./a.out
Enter the number of cities: 3
Enter the distance matrix (enter 0 for diagonal elements):
0 5 10
5 0 20
10 7 0
Shortest route: 0 2 1 
Minimum distance: 22
student@student:~$ ./a.out
Enter the number of cities: 4
Enter the distance matrix (enter 0 for diagonal elements):
0 10 15 20 
10 0 35 25 
15 35 0 30    
20 25 30 0
Shortest route: 0 1 3 2 
Minimum distance: 80
student@student:~$ ./a.out
Enter the number of cities: 5
Enter the distance matrix (enter 0 for diagonal elements):
0 20 30 10 11 
15 0 16 4 2 
3 5 0 2 4 
19 6 18 0 3
16 4 7 16 0
Shortest route: 0 3 1 4 2 
Minimum distance: 28

