#include "../includes/Route.h"
#include <iostream>
#include <stdexcept>

Route::Route(const std::vector<std::pair<double, double>>& nodes, std::vector<double>& distances)
    : m_route_id(unique_id++), m_nodes(nodes), m_distances(distances) {}

std::pair<double, double> Route::getNextStop(size_t current_index) const {
    return current_index + 1 < m_nodes.size() ? m_nodes[current_index + 1] : m_nodes.back();
}

void Route::updateSchedule(const std::vector<double>& new_timestamps) {
    if (new_timestamps.size() != m_schedule.size()) std::cout << "Invalid schedule\n";
    m_schedule = new_timestamps;
}

double Route::calculateDistance(size_t start_index, size_t end_index) const {
    if (start_index > m_distances.size() || end_index > m_distances.size())
        throw std::out_of_range("Invalid arguments");
    if (start_index == m_distances.size() - 1) return 0;
    int sum = 0;
    for (int i = start_index + 1; i <= end_index; ++i) {
        sum += m_distances[i];
    }
    return sum;
}

double Route::getDistance() const { 
    int sum = 0;
    for (auto d : m_distances) sum += d;
    return sum;
}

