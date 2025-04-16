#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <vector>
#include <memory>
#include "Route.h"

template <typename T>
class Vehicle {    
    private:
        int m_id;
        double m_speed; // km/h
        int m_capacity;
        std::shared_ptr<Route> m_route;
        std::pair<double, double> m_current_location;
        double m_arrival_time;
        T m_consumption; // per 100km
        T m_specific_fuel;
        void takeAwayFuel(double distance);
    public:
        Vehicle(int id, double speed, int capacity, const std::string& route_id, T consumption, T specific_fuel);
        void updateLocation(double time_step);
        void adjustSpeed(double new_speed);
        void recalculateRoute();
        void logData() const;

        int getId() const { return m_id; }
        double getSpeed() const { return m_speed; }
        const std::string& getRouteId() const { return route_id_; }
        const T& getSpecificData() const { return m_specific_data; }
};
#endif