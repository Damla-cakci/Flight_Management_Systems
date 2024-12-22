//// reservation.cpp
//
//#include "reservation.h"
//#include "flight.h"
//#include <algorithm>
//#include <cstddef>
//
//// Implementation of reservation class
//
//reservation::reservation(flightInfo _flight, Customer _customer)
//    : flight(_flight), customer(_customer) {}
//
//void reservation::display() {
//    std::cout << "Reservation Details:" << std::endl;
//    std::cout << "Flight Information:" << std::endl;
//    flight.display();
//    std::cout << "Customer Information:" << std::endl;
//    customer.display();
//    std::cout << "---------------------" << std::endl;
//}
//
//flightInfo* reservationSystem::findFlightByNumber(const std::string& flightNumber) const {
//    auto foundFlight = std::find_if(flightInfo::flights.begin(), flightInfo::flights.end(),
//                                     [flightNumber](const flightInfo& flight) { return flight.getflightNumber() == flightNumber; });
//
//    if (foundFlight != flightInfo::flights.end()) {
//        return &(*foundFlight);
//    } else {
//        return nullptr;
//    }
//}
//
//void reservationSystem::createReservation() {
//    std::string flightNumber;
//    int customerId;
//
//    std::cout << "Enter Flight Number for Reservation: ";
//    std::cin >> flightNumber;
//
//    std::cout << "Enter Customer ID for Reservation: ";
//    std::cin >> customerId;
//
//    // Find flight by its identifier
//    flightInfo* foundFlight = findFlightByNumber(flightNumber);
//
//    // Find customer by its identifier
//    auto customerIt = std::find_if(Customer::customers.begin(), Customer::customers.end(),
//                                   [customerId](const Customer& customer) { return customer.getCustomer_id() == customerId; });
//
//    // Check if both flight and customer exist
//    if (foundFlight != nullptr && customerIt != Customer::customers.end()) {
//        // Create a reservation using found flight and customer
//        reservation newReservation(*foundFlight, *customerIt);
//        reservations.push_back(newReservation);
//
//        std::cout << "New Reservation Created:" << std::endl;
//        newReservation.display();
//    } else {
//        std::cout << "Flight or Customer not found. Reservation creation failed." << std::endl;
//    }
//}
//
//
//Customer* reservationSystem::findCustomerById(int customerId) const {
//    auto foundCustomer = std::find_if(Customer::customers.begin(), Customer::customers.end(),
//                                       [customerId](const Customer& customer) { return customer.getCustomer_id() == customerId; });
//
//    if (foundCustomer != Customer::customers.end()) {
//        return &(*foundCustomer);
//    } else {
//        return NULL;
//    }
//}

