#include "ABNN.h"

#include <iostream>
#include <ctime>

using namespace std;
using namespace abnn;

int main()
{
	srand( time( NULL ) );

	NeuralNet nn;
	nn.createPerceptron( { 2, 3, 1 } );
	nn.setActivationFuncGlobal( Neuron::ActFunc::Tanh );
	nn.feedNetwork_1d( { 1, 1 } );
	Vector1d<nn_t>Output = nn.getOutput_1d();
	for( nn_t n : Output )
	{
		cout << n;
	}

	return 0;
}