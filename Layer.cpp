#include "Layer.h"

void Layer::execute(){
	executeNeurons();
}


Layer::Layer(std::vector<float> input, int neuronCount, bool isOutput): input(input), isOutput(isOutput)
{
	for (size_t i = 0; i < neuronCount; i++) {
		this->neuronList.push_back(*new Neuron(this->input, i));
	}
	this->output.resize(neuronCount);
}

void Layer::modifyNeuronWeights(float error)
{
	for (Neuron neuron : this->neuronList)
		neuron.modifyWeights(error);
}

void Layer::executeNeurons() {
	for (int i = 0; i < this->neuronList.size(); i++)
		this->output[i] = this->neuronList[i].get().transferFunction();
}
