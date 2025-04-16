#ifndef ROUTE_H
#define ROUTE_H
#include <vector>
#include <string>

class Route {
    private:
        static int unique_id;
        int m_route_id;                      
        std::vector<std::pair<double, double>> m_nodes; 
        std::vector<double> m_distances; // distance from next index points -> { 96, 223, ... 0 }
        std::vector<double> m_schedule; // Arrival time at next lcoation -> { 12.34, ... , 0 }
    public:
        Route(const std::vector<std::pair<double, double>>& nodes, std::vector<double>& distances);            
        void updateSchedule(const std::vector<double>& new_timestamps);
        double getDistanceFromNextNode(const std::pair<double, double>& current) const;
        
        double getArrivalTime(std::pair<double, double>& current);
        std::pair<double, double>& getNextNode(std::pair<double, double>& current);
        const int getRouteId() const { return m_route_id; }
        double getDistance() const;
        const std::vector<std::pair<double, double>>& getNodes() const { return m_nodes; }
    
};
#endif