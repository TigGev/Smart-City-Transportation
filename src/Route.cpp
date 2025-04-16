#include "../includes/Route.h"
#include <iostream>
#include <stdexcept>

Route::Route(const std::vector<std::pair<double, double>>& nodes, std::vector<double>& distances)
    : m_route_id(unique_id++), m_nodes(nodes), m_distances(distances) {}

void Route::updateSchedule(const std::vector<double>& new_timestamps) {
    if (new_timestamps.size() != m_schedule.size()) std::cout << "Invalid schedule\n";
    m_schedule = new_timestamps;
}

double Route::getDistanceFromNextNode(const std::pair<double, double>& current) const {
    for (int i = 0; i < m_nodes.size(); ++i) {
        if (current == m_nodes[i]) return m_distances[i];
    }
    throw std::invalid_argument("Invalid node!");
}

std::pair<double, double>& Route::getNextNode(std::pair<double, double>& current) {
    if (current == m_nodes.back()) return current;
    for (int i = 0; i < m_nodes.size() - 1; ++i) {
        if (current == m_nodes[i])   return m_nodes[i + 1];
    }
    throw std::runtime_error("The location does not exist on this route");
}


double Route::getDistance() const { 
    int sum = 0;
    for (auto d : m_distances) sum += d;
    return sum;
}

double Route::getArrivalTime(std::pair<double, double>& current) {
    if (current == m_nodes.back()) return 0.0;
    for (int i = 0; i < m_nodes.size() - 1; ++i) {
        if (current == m_nodes[i]) return m_schedule[i];
    }
    throw std::runtime_error("The location does not exist on this route");
}

