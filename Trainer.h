#pragma once
#include <vector>
#include "Layer.h"
#include "TrainingSet.h"
class Trainer
{
public:
	std::vector<reference_wrapper<Layer>> layers;
	void train();
	void calculateOutputLayerError(TrainingSet& trainingSet, float& error);
	void setup(int inputSize);
	std::vector<float> getResult();
	Trainer(TrainingSetSet &trainingSetSet);
private:
	TrainingSetSet& trainingSetSet;
	void modifyNeuronWeights(float error);
};

