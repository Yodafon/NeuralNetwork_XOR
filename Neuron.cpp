#include "Neuron.h"
#include <cmath>
#include <numbers>
#include <random>
using namespace std;

float Neuron::transferFunction()
{
    float inputSum = sumWeightsAndInputs();
    float result = 1.0f / (1 + exp(-inputSum));
    return result;
}

float Neuron::sumWeightsAndInputs()
{
    float result = 0.0f;
    for (size_t i = 0; i < this->input.size(); i++) {
        result += this->input.at(i)*this->weight.at(i);
    }
    return result;
}

void Neuron::initWeights()
{
    random_device rd;
    mt19937_64 mt(rd());
    uniform_real_distribution<float> dist(0.0f, nextafterf(1.0f, FLT_MAX));
    for (size_t i = 0; i < this->input.size(); i++)  this->weight.push_back(dist(mt));
}

Neuron::Neuron(vector<float>& input, int index) : input(input)
{
    this->input = input;
    this->index = index;
    initWeights();
    
}

void Neuron::modifyWeights(float error) {

}

