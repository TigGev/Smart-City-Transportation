#ifndef MANAGER_H
#define MANAGER_H

#pragma once
#include <vector>
#include <memory>
#include "Vehicle.h"
#include "Event.h"
#include "Route.h"

class Manager {
    private:
        double m_time_step;
        std::vector<std::shared_ptr<void>> m_vehicles;
        std::vector<std::shared_ptr<void>> m_events;
        std::vector<std::shared_ptr<Route>> m_routes;
    public:
        Manager(double time_step = 1.0) : m_time_step(time_step) {}
    
        template <typename T>
        void addVehicle(std::shared_ptr<Vehicle<T>> vehicle) {
            m_vehicles.push_back(vehicle);
        }
        template <typename E>
        void addEvent(std::shared_ptr<Event<E>> event) {
            m_events.push_back(event);
        }
    
        void addRoute(std::shared_ptr<Route> route) {
            m_routes.push_back(route);
        }
    
        void runStep();
        void triggerRandomEvent();
        void renderState() const;
        void configure(double new_time_step);
    
};
#endif