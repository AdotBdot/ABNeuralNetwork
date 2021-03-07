#include "ABNN.h"

#include <iostream>

using namespace std;
using namespace abnn;

int main()
{
	NeuralNet nn;
	nn.createPerceptron( { 2, 3, 1 } );
	nn.setActivationFuncGlobal( Neuron::ActFunc::ExpLinear );
	nn.feedNetwork_1d( { 0.f, 1.f } );
	Vector1d<nn_t>Output = nn.getOutput_1d();
	for( nn_t n : Output )
	{
		cout << n;
	}

	return 0;
}