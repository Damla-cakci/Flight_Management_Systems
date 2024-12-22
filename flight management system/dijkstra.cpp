#include "dijkstra.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

cargo::cargo(string _flightNumber, int _day, int _month, int _year, int hour, int minute, string _flightState, string _flightRoute)
   
{
    fileNameCargo = "cargo.txt";
    fileReadCargo();

    FlightPrice = "150"; 
	
	int tempGraph[V4][V4] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                            {4, 0, 8, 0, 0, 0, 0, 11, 0},
                            {0, 8, 0, 7, 0, 4, 0, 0, 2},
                            {0, 0, 7, 0, 9, 14, 0, 0, 0},
                            {0, 0, 0, 9, 0, 10, 0, 0, 0},
                            {0, 0, 4, 14, 10, 0, 2, 0, 0},
                            {0, 0, 0, 0, 0, 2, 0, 1, 6},
                            {8, 11, 0, 0, 0, 0, 1, 0, 7},
                            {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    for (int i = 0; i < V4; ++i) {
        for (int j = 0; j < V4; ++j) {
            graph[i][j] = tempGraph[i][j];
        }
    } 
}

void cargo::fileReadCargo()
{
    ifstream file(fileNameCargo.c_str());

    if (file.is_open())
    {
        stringstream buffer;
        buffer << file.rdbuf();
        cargoData = buffer.str();

        file.close();
    }
    else
    {
        cerr << "File could not open: " << fileNameCargo << std::endl;
    }
}

void cargo::saveCargo()
{
    ofstream file(fileNameCargo.c_str());

    if (file.is_open())
    {
        file << cargoData;

        file.close();
    }
    else
    {
        cerr << "File could not open: " << fileNameCargo << std::endl;
    }
}


string cargo::getFlightPrice() const
{
    return FlightPrice;
}

int cargo::getV4() const
{
    return V4;
}

void cargo::printSolution(int dist[]) const
{
    cout << "City Name \t\t Distance (km)" << endl
         << endl;
    for (int i = 0; i < V4; i++)
        cout << cities[i] << " \t\t\t\t" << dist[i] << endl;
}

int cargo::minDistance(int dist[], bool sptSet[]) const
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V4; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void cargo::dijkstraAlgorithm() const
{
    int dist[V4];
    bool sptSet[V4];

    for (int i = 0; i < V4; i++)
    {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }

    dist[0] = 0;

    for (int count = 0; count < V4 - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V4; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

void cargo::hesaplaVeYazdirMesafeSuresi() const
{

    string kalkis, varis;
    cout << "Enter the city of departure: ";
    cin >> kalkis;
    cout << "Enter the destination city: ";
    cin >> varis;

    int kalkisIndex = -1, varisIndex = -1;
    for (int i = 0; i < V4; ++i)
    {
        if (cities[i] == kalkis)
        {
            kalkisIndex = i;
        }
        if (cities[i] == varis)
        {
            varisIndex = i;
        }
    }

    if (kalkisIndex == -1 || varisIndex == -1)
    {
        cerr << "Incorrect entry! Please enter valid city names." << endl;
        return;
    }

    int mesafe = guzergahMesafeleri[kalkisIndex][varisIndex];
    int dist[V4];
    bool sptSet[V4];

    for (int i = 0; i < V4; i++)
    {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }

    dist[kalkisIndex] = 0;

    for (int count = 0; count < V4 - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V4; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int mesafe4 = dist[varisIndex];

    int kargoUcreti = mesafe4 * 5;

    cout << "\nDeparture: " << kalkis << ", Destination: " << varis << "\nDistance Time: " << dist[varisIndex] << " km" << endl;
    cout << "Recommended Shipping Fee: " << kargoUcreti << " TL" << endl;
    cout << "Estimated Travel Duration: " << dist[varisIndex] * 5 << " min" << endl;
}


