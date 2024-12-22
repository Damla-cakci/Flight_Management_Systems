#ifndef CARGO_H
#define CARGO_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class cargo{
	
	private:
	string fileNameCargo;
	string FlightPrice;
	string cargoData;
	
	static const int V4 = 9;

	const string cities[V4] = {"Istanbul", "Ankara", "Samsun", "Antalya", "Izmir", "Adana", "Kayseri", "Eskisehir", "Trabzon"};
	
    int guzergahMesafeleri[V4 - 1][V4 - 1];
    
	int graph[V4][V4];	
    int minDistance(int dist[], bool sptSet[]) const;
    void printSolution(int dist[]) const;
    
    public:
    explicit cargo(string _flightNumber= "", int _day= 0, int _month=0 , int _year= 0, int hour=0 , int minute= 0, string _flightState= "", string _flightRoute= "");
    
    void fileReadCargo();
    void saveCargo();

	string getFlightPrice() const;
	
	int getV4() const;
	void dijkstraAlgorithm()const;
	void hesaplaVeYazdirMesafeSuresi() const;

};

#endif
