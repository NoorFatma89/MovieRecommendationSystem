#include "predictor_recommender.h"
#include <algorithm>

// Function to predict ratings for a specific user
std::vector<double> Predictor::predictRatings(const std::vector<std::vector<int>>& ratings, int targetUser) {
    int numMovies = ratings[0].size();
    std::vector<double> predictedRatings(numMovies, 0.0);
    std::vector<double> similaritySum(numMovies, 0.0);

    for (size_t otherUser = 0; otherUser < ratings.size(); ++otherUser) {
        if (otherUser == targetUser) continue;

        double similarity = similarityCalculator.calculateSimilarity(ratings[targetUser], ratings[otherUser]);
        for (int movie = 0; movie < numMovies; ++movie) {            
            if (ratings[targetUser][movie] == 0 && ratings[otherUser][movie] != 0) {
                predictedRatings[movie] += similarity * ratings[otherUser][movie];
                similaritySum[movie] += similarity;
            }
        }
    }

    for (int movie = 0; movie < numMovies; ++movie) {
        if (similaritySum[movie] != 0) {
            predictedRatings[movie] /= similaritySum[movie];
        }
    }

    return predictedRatings;
}

// Function to recommend top N movies
std::vector<std::pair<int, double>> Recommender::recommendMovies(const std::vector<double>& predictedRatings, int topN) {
    std::vector<std::pair<int, double>> movieScores;
    for (size_t i = 0; i < predictedRatings.size(); ++i) {
        if (predictedRatings[i] > 0) {
            movieScores.emplace_back(i, predictedRatings[i]);
        }
    }

    std::sort(movieScores.begin(), movieScores.end(), [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
        return a.second > b.second; 
    });

    if (movieScores.size() > static_cast<size_t>(topN)) {
        movieScores.resize(topN);
    }

    return movieScores;
}
