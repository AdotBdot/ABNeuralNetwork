#pragma once

#include "Config.h"
#include "Layer.h"
#include "Neuron.h"

#include <string>
#include <vector>

namespace abnn
{
	class NeuralNet
	{
	public:
		enum class Type
		{
			Perceptron,
			Convolutional
		};

		explicit NeuralNet();

		void setActivationFuncLayer( size_t Layer, Neuron::ActFunc ActivationFunc );
		void setActivationFuncGlobal( Neuron::ActFunc ActivationFunc );
		void createPerceptron( std::vector<size_t> Topology, bool initRandomly = true );

		void feedNetwork_1d( Vector1d<nn_t> InputVector );
		Vector1d<nn_t> getOutput_1d();

		NeuralNet::Type getType();
		std::string getTypeString();

	private:
		Type m_Type;
		std::vector<Layer*>m_Layers;
	};
}
