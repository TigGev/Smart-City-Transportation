#ifndef EVENT_H
#define EVENT_H
#include <vector>
#include <string>
#include <memory>
#include "Route.h"

template <typename E>
class Event {
    private:
        E m_event_type;
        double m_duration;
        double m_severity;
        std::vector<Route> m_affected_routes;
    public:    
        Event(E event_type, double duration, double severity, const std::vector<Route>& affected_routes)
            : m_event_type(event_type), m_duration(duration), m_severity(severity), m_affected_routes(affected_routes) {}
        void notifyVehicles();
        void applyEffect();
        void subscribeVehicle(std::shared_ptr<void> vehicle);

        E getEventType() const { return m_event_type; }
        double getDuration() const { return m_duration; }
        double getSeverity() const { return m_severity; }
        const std::vector<std::string>& getAffectedRoutes() const { return m_affected_routes; }
};
#endif