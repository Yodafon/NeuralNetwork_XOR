// NeuralNetwork_XOR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Trainer.h"
#include"TrainingSet.h"

TrainingSet& getTrainingSet(vector<float> input, vector<float> output) {
    TrainingSet* trainingSet = new TrainingSet();
    trainingSet->input = input;
    trainingSet->output = output;
    return  *trainingSet;
}

int main()
{ 
    
    const TrainingSet &trainingSet1 = getTrainingSet({ 0,0 }, {0});
    const TrainingSet &trainingSet2 = getTrainingSet({ 1,0 }, {1});
    const TrainingSet &trainingSet3 = getTrainingSet({ 0,1 }, {1});
    const TrainingSet &trainingSet4 = getTrainingSet({ 1,1 }, {0});
    TrainingSetSet trainingSetSet;
    trainingSetSet.trainingSetVector = { trainingSet1, trainingSet2, trainingSet3, trainingSet4 };
    
    Trainer* trainer =new Trainer(trainingSetSet);
    
    trainer->setup(trainingSetSet.trainingSetVector.front().input.size());
    trainer->train();
    trainer->getResult();
    cout << trainer->getResult().at(0);
}

