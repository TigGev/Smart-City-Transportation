#include "../includes/Vehicle.h"

template <typename T>
Vehicle<T>::Vehicle(int id, double speed, int capacity, const std::string& route_id, T consumption, T specific_data) 
    : m_id(id), m_speed(speed), m_capacity(capacity), m_route_id(route_id), m_consumption(consumption), m_specific_fuel(specific_fuel) {}

template <>
void Vehicle<int>::takeAwayFuel(double distance) { // electro
    if (distance <= 0) return;
    int fuel_consumed = (distance / 100) * m_consumption;
    m_specific_fuel -= fuel_consumed;
    if (m_specific_fuel < 0) m_specific_fuel = 0;
}

template <>
void Vehicle<double>::takeAwayFuel(double distance) { // petrol
    if (distance <= 0) return;
    double fuel_consumed = (distance / 100) * m_consumption;
    m_specific_fuel -= fuel_consumed;
    if (m_specific_fuel < 0) m_specific_fuel = 0.0;
}

template <typename T>
void Vehicle<T>::updateLocation(double time_step) { 
    if (time_step <= 0) return;
    double passed_route = m_speed * (time_step / 60); // to hour
    takeAwayFuel(passed_route);
    while (passed_route > 0) {
        double distance = m_route->getDistanceFromNextNode(m_current_location);
        passed_route -= distance;
        if (passed_route >= 0) {
            m_current_location = m_route->getNextNode(m_current_location);
            m_arrival_time = m_route->getArrivalTime(m_current_location);
        }
    }
}

template <typename T>
void Vehicle<T>::adjustSpeed(double new_speed) {
    if (new_speed < 0) return;
    m_speed = new_speed;    
}

template <typename T>
void Vehicle<T>::recalculateRoute() {

}
