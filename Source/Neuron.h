#pragma once

#include "Config.h"

namespace abnn
{
	class Neuron
	{
	public://methods
		enum class ActFunc
		{
			Threshold,
			Linear,
			Sigmoid,
			Tanh,
			ReLu,
			ExpLinear
		};

		Neuron();
		virtual ~Neuron();

		void input( nn_t inValue );
		void activate( ActFunc ActivationFunction );
		void derive( ActFunc ActivationFunction );

		nn_t getInVal();
		nn_t getActVal();
		nn_t getDerivVal();

	protected://values
		nn_t x;//Input Value
		nn_t y;//Activated Value
		nn_t d;//Derivated Value
	};
}
