#include "../includes/Route.h"
#include <iostream>

Route::Route(const std::vector<std::pair<double, double>>& nodes, double distance)
    : m_route_id(unique_id++), m_nodes(nodes), m_distance(distance) {}

std::pair<double, double> Route::getNextStop(size_t current_index) const {
    return current_index + 1 < m_nodes.size() ? m_nodes[current_index + 1] : m_nodes.back();
}

void Route::updateSchedule(const std::vector<double>& new_timestamps) {
    if (new_timestamps.size() != m_schedule.size()) std::cout << "Invalid schedule\n";
    m_schedule = new_timestamps;
}

// double calculateDistance(size_t start_index, size_t end_index) const;
