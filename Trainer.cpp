#include "Trainer.h"

void Trainer::train() {
	//while (1)
	{
		float error = 0;
		for (TrainingSet trainingSet : trainingSetSet.trainingSetVector) {
			layers.front().get().input = trainingSet.input;
			puts((const char *)&trainingSet.input);
				for (Layer layer : this->layers) {
					layer.execute();
				}
		}
		calculateOutputLayerError(trainingSet, error);
		modifyNeuronWeights(error);
	}
}

void Trainer::calculateOutputLayerError(TrainingSet& trainingSet, float& error)
{
	const std::vector<float>& output = getResult();
	const Layer outputLayer = layers.back().get();
	for (size_t j = 0; j < output.size(); j++) {
		float expectedOutput = trainingSet.output.at(j);
		float actualOutput = output.at(j);
		error = expectedOutput - actualOutput;
		outputLayer.neurons.at(j).setError(error);
	}
}

void Trainer::setup(int inputSize) { //input as input layer
	layers.push_back(new Layer(trainingSetSet.trainingSetVector.front().input, inputSize, false)); //1. hidden layer with TrainingSetSet's first input
	layers.push_back(new Layer(layers.at(layers.size() - 1).get().output, inputSize, false)); //2. hidden layer with 1. hidden layers's output as input
	layers.push_back(new Layer(layers.at(layers.size()-1).get().output, inputSize, false)); //3. hidden layer with 2. hidden layer's output as input
	layers.push_back(new Layer(layers.at(layers.size()-1).get().output, inputSize, false)); //4. hidden layer with 3. hidden layer's output as input
	layers.push_back(new Layer(layers.at(layers.size()-1).get().output, 1, true)); //output layer with 3. hidden layer's output as input
}

std::vector<float> Trainer::getResult() {
	return layers.back().get().output;
}

Trainer::Trainer(TrainingSetSet &trainingSetSet) : trainingSetSet(trainingSetSet) {
}

void Trainer::modifyNeuronWeights(float error)
{
	for (size_t i = layers.size(); i > 0; i--)
	{
		this->layers.at(i).get().modifyNeuronWeights(error);
	}
}
