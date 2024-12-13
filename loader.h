#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <string>

class Loader {
public:
    // Function to load the ratings matrix from a CSV file
    std::vector<std::vector<int>> loadRatingsMatrix(const std::string& filename);
};

#endif // LOADER_H
