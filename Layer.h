#pragma once
#include <vector>
#include "Neuron.h"
class Layer
{
public:
	void execute();
	Layer(std::vector<float> input, int neuronCount, bool isOutput);
	std::vector<float> input;
	std::vector<float> output;
	void modifyNeuronWeights(float error);

private:
	std::vector<std::reference_wrapper<Neuron>> neuronList;
	void executeNeurons();
	bool isOutput;
};

