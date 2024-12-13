#include <iostream>
#include "loader.h"
#include "predictor_recommender.h"

int main() {
    Loader loader;
    Predictor predictor;
    Recommender recommender;

    std::string filename = "ratings.csv"; //Data File
    int targetUser = 0;  //Suppose user1(index-0) as target user
    int topN = 3;       // Number of top movies to recommend

    std::vector<std::vector<int>> ratings = loader.loadRatingsMatrix(filename);
    std::vector<double> predictedRatings = predictor.predictRatings(ratings, targetUser);

    std::cout << "Predicted Ratings for User" << targetUser + 1 << ":\n";
    for (size_t i = 0; i < predictedRatings.size(); ++i) {
        std::cout << "Movie" << i + 1 << ": " << predictedRatings[i] << "\n";
    }

    std::vector<std::pair<int, double>> recommendations = recommender.recommendMovies(predictedRatings, topN);
    std::cout << "Top " << topN << " recommended movies for User" << targetUser + 1 << ":\n";
    for (const auto& rec : recommendations) {
        std::cout << "Movie" << rec.first + 1 << " with predicted rating " << rec.second << "\n";
    }

    return 0;
}
