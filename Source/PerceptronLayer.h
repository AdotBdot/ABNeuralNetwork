#pragma once

#include <vector>

#include "Config.h"
#include "Layer.h"
#include "Synapses.h"
#include "Neuron.h"

namespace abnn
{
	class PerceptronLayer
		: public Layer
	{
	public:
		PerceptronLayer();
		PerceptronLayer( Configuration Configuration, PerceptronLayer* PrevLayer, size_t Size );
		virtual ~PerceptronLayer();

		size_t getNeuronsCount();
		size_t getConnectionsCount();

		void initRandomly();
		void feedLayer();
		void input_1d( Vector1d<nn_t> Input );
		void setActFunc( Neuron::ActFunc ActFunc );
		Neuron::ActFunc getActFunc();
		Vector1d<nn_t>getOutput_1d();

	protected:
		void activateNeurons();

	protected:
		bool m_UseBias;
		Neuron::ActFunc m_ActFunc;
		PerceptronLayer* m_PrevLayer;
		Vector1d<Neuron*> m_Neurons;
		Vector1d<nn_t>* m_Biases;
		Synapses* m_InWeights;
	};
}
