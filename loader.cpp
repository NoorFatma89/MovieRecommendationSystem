#include "loader.h"
#include <fstream>
#include <sstream>

// Function to load the ratings matrix from a CSV file
std::vector<std::vector<int>> Loader::loadRatingsMatrix(const std::string& filename) {
    std::vector<std::vector<int>> ratings;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            row.push_back(std::stoi(value));
        }
        ratings.push_back(row);
    }
    return ratings;
}
