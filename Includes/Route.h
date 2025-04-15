#ifndef ROUTE_H
#define ROUTE_H
#include <vector>
#include <string>

class Route {
    private:
        static int unique_id;
        int m_route_id;                      
        std::vector<std::pair<double, double>> m_nodes; 
        std::vector<double> m_distances; // distance from previous index points -> 0, 223, ...
        // double m_distance;
        std::vector<double> m_schedule; 
    public:
        Route(const std::vector<std::pair<double, double>>& nodes, std::vector<double>& distances);            
        std::pair<double, double> getNextStop(size_t current_index) const;
        void updateSchedule(const std::vector<double>& new_timestamps);
        double calculateDistance(size_t start_index, size_t end_index) const;
        
        const int getRouteId() const { return m_route_id; }
        double getDistance() const;
        const std::vector<std::pair<double, double>>& getNodes() const { return m_nodes; }
    
};
#endif