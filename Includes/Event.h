#ifndef EVENT_H
#define EVENT_H
#include <vector>
#include <string>
#include <memory>

template <typename E>
class Event {
    private:
        E event_type_;                          
        double duration_;                       
        double severity_;                       
        std::vector<std::string> affected_routes_; 
    public:    
        Event(E event_type, double duration, double severity, const std::vector<std::string>& affected_routes)
            : event_type_(event_type), duration_(duration), severity_(severity), affected_routes_(affected_routes) {}
        void notifyVehicles();
        void applyEffect();
        void subscribeVehicle(std::shared_ptr<void> vehicle);

        E getEventType() const { return event_type_; }
        double getDuration() const { return duration_; }
        double getSeverity() const { return severity_; }
        const std::vector<std::string>& getAffectedRoutes() const { return affected_routes_; }
};
#endif