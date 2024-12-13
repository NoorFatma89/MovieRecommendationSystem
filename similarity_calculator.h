#ifndef SIMILARITY_CALCULATOR_H
#define SIMILARITY_CALCULATOR_H

#include <vector>

class SimilarityCalculator {
public:
    // Function to calculate similarities between  users (or items)
    double calculateSimilarity(const std::vector<int>& user1, const std::vector<int>& user2);
};

#endif // SIMILARITY_CALCULATOR_H
