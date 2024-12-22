#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class flightInfo {
public:
    flightInfo(string _flightNumber, int _day, int _month, int _year, int _hour, int _minute, string _flightState, string _flightRoute);
    flightInfo(string _flightNumber, int _day, int _month, int _year, int _hour, int _minute, string _flightState, string _flightRoute, int _passengerCapacity, double _ticketPrice);

    void setflightNumber(string _flightNumber);
    void setflightDate(int _day = 1, int _month = 1, int _year = 2024);
    void setflightTime(int _hour, int _minute);
    void setflightState(string _flightState);
    void setflightRoute(string _flightRoute);
    void setPassengerCapacity(int _passengerCapacity);
    void setTicketPrice(int _ticketPrice);

    string getflightNumber();
    string getflightState();
    string getflightRoute();
    int getPassangerCapacity();
    int getTicketPrice();

    void display();
    static bool checkDate(int _day, int _month, int _year);
    static bool checkTime(int _hour, int _minute);

    static bool compareByDate(const flightInfo& flight1, const flightInfo& flight2); // sýralama algoritmasý

    static void createFlight();
    static void displayAllFlights();
    static vector<flightInfo> flights;

private:
    string flightNumber;
    string flightTime;
    string flightState;
    string flightRoute;
    int passengerCapacity;
    int ticketPrice;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

#endif

