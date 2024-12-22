#include "flight.h"

vector<flightInfo> flightInfo::flights;

flightInfo::flightInfo(string _flightNumber, int _day, int _month, int _year, int _hour, int _minute, string _flightState, string _flightRoute) {
    setflightNumber(_flightNumber);
    setflightDate(_day, _month, _year);
    setflightTime(_hour, _minute);
    setflightState(_flightState);
    setflightRoute(_flightRoute);
}

flightInfo::flightInfo(string _flightNumber, int _day, int _month, int _year, int _hour, int _minute, string _flightState, string _flightRoute ,int _passengerCapacity, double _ticketPrice){
	
	setflightNumber(_flightNumber);
    setflightDate(_day, _month, _year);
    setflightTime(_hour, _minute);
    setflightState(_flightState);
    setflightRoute(_flightRoute);
    setPassengerCapacity(_passengerCapacity);
    setTicketPrice(_ticketPrice);
}

void flightInfo::setflightNumber(string _flightNumber) {
	
    flightNumber = _flightNumber;
}

void flightInfo::setflightDate(int _day, int _month, int _year){
	
	if(checkDate(_day, _month, _year)){
		
		year = _year;
		month = _month;
		day = _day;
	}
	
	else{
		
		cerr << "Invalid date" << endl;
	}
}

void flightInfo::setflightTime(int _hour, int _minute) {
	
    if(checkTime(_hour,_minute)){
    	
    	hour = _hour;
    	minute = _minute;
	}
	
	else{
		
		cerr << "Invalid time" << endl;
	}
}

void flightInfo::setflightState(string _flightState) {
	
    flightState = _flightState;
}

void flightInfo::setflightRoute(string _flightRoute) {
	
    flightRoute = _flightRoute;
}

void flightInfo::setPassengerCapacity(int _passengerCapacity){
	
	passengerCapacity = _passengerCapacity;
}

void flightInfo::setTicketPrice(int _ticketPrice){
	
	ticketPrice = _ticketPrice;
}

string flightInfo::getflightNumber() {
	
    return flightNumber;
}

string flightInfo::getflightState() {
	
    return flightState;
}

string flightInfo::getflightRoute() {
	
    return flightRoute;
}

int flightInfo::getPassangerCapacity(){
	
	return passengerCapacity;
}

int flightInfo::getTicketPrice(){
	
	return ticketPrice;
}

void flightInfo::display() {
	
    cout << "Flight number: " << flightNumber << endl;
    cout << "Flight date: " << day << "." << month << "." << year << endl;
    cout << "Flight time: " << hour << ":" << minute << endl;
    cout << "Flight state: " << flightState << endl;
    cout << "Flight route: " << flightRoute << endl;
}

bool flightInfo::checkDate(int _day, int _month, int _year){
	
	int daysPerYear[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	bool isValidmonth = (_month > 0) && (_month <= 12);
	bool isValidday = ((_day>0) && (_day<=daysPerYear[_month])) || ((_month==2) && (_year%4==0) && (_day==29));
	
	return isValidmonth && isValidday;
}

bool flightInfo::checkTime(int _hour, int _minute){
	
	bool isValidHour = (_hour >= 0) && (_hour < 24);
    bool isValidMinute = (_minute >= 0) && (_minute < 60);

    return isValidHour && isValidMinute;
}

bool flightInfo::compareByDate(const flightInfo& flight1, const flightInfo& flight2) {
    if (flight1.year < flight2.year) return true;
    if (flight1.year > flight2.year) return false;
    if (flight1.month < flight2.month) return true;
    if (flight1.month > flight2.month) return false;
    return flight1.day < flight2.day;
}

void flightInfo::createFlight() {
	
    string flightNumber, flightState, flightRoute;
    int day, month, year, hour, minute;

    cout << "Enter Flight Number: ";
    cin >> flightNumber;
    cout << "Enter Flight Day: ";
    cin >> day;
    cout << "Enter Flight Month: ";
    cin >> month;
    cout << "Enter Flight Year: ";
    cin >> year;
    cout << "Enter Flight Hour: ";
    cin >> hour;
    cout << "Enter Flight Minute: ";
    cin >> minute;
    cout << "Enter Flight State: ";
    cin >> flightState;
    cout << "Enter Flight Route: ";
    cin >> flightRoute;

    if(checkDate(day, month, year) && checkTime(hour, minute)) {
        
        flights.push_back(flightInfo(flightNumber, day, month, year, hour, minute, flightState, flightRoute));

        cout << "New Flight Created:" << endl;
        flights.back().display();
        cout << "-------------------------" << endl;
    } 
    
	else{
		
        cout << "Flight creation failed. Invalid date or time." << endl;
    }
    
}

void flightInfo::displayAllFlights() {
	
    cout << "All Flights:" << endl;
    for (size_t i = 0; i < flights.size(); ++i) {
        flights[i].display();
        cout << "---------------------" << endl;
    }
}

