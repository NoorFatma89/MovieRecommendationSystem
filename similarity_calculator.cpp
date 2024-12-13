#include "similarity_calculator.h"
#include <cmath>
#include <cstddef>

// Function to calculate similarities between  users (or items)
double SimilarityCalculator::calculateSimilarity(const std::vector<int>& user1, const std::vector<int>& user2) {
    double dotProduct = 0.0, normA = 0.0, normB = 0.0;

    for (size_t i = 0; i < user1.size(); ++i) {
        dotProduct += user1[i] * user2[i];
        normA += user1[i] * user1[i];
        normB += user2[i] * user2[i];
    }

    return (normA == 0 || normB == 0) ? 0 : dotProduct / (std::sqrt(normA) * std::sqrt(normB));
}
