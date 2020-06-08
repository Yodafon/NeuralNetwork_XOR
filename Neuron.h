#include <vector>

using namespace std;

class Neuron
{
public:
	vector<float> &input, *output;
	float transferFunction();
	Neuron(vector<float> &input, int index);
	void modifyWeights(float error);
private: 
	vector<float> weight;
	int index;
	float sumWeightsAndInputs();
	void initWeights();
	float error;
};
