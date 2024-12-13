#ifndef PREDICTOR_RECOMMENDER_H
#define PREDICTOR_RECOMMENDER_H

#include <vector>
#include <utility>
#include "similarity_calculator.h"

class Predictor {
private:
    SimilarityCalculator similarityCalculator;
public:
    // Function to predict ratings for a specific user
    std::vector<double> predictRatings(const std::vector<std::vector<int>>& ratings, int targetUser);
};

class Recommender {
public:
    // Function to recommend top N movies
    std::vector<std::pair<int, double>> recommendMovies(const std::vector<double>& predictedRatings, int topN);
};

#endif // PREDICTOR_RECOMMENDER_H
