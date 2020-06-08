#pragma once
#include <vector>

using namespace std;

typedef struct TrainingSet {
    vector<float> input;
    vector<float> output;
};

typedef struct TrainingSetSet {
    vector<TrainingSet> trainingSetVector;
};
