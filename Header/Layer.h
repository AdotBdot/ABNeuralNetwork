#pragma once

#include "Config.h"

#include <string>

namespace abnn
{
	class Layer
	{
	public:
		enum class Configuration
		{
			Input,
			Hidden,
			Output
		};

		enum class Type
		{
			Perceptron
		};

		Layer();
		Layer( Type _Type, Configuration _Configuration = Configuration::Hidden );
		virtual ~Layer();

		Configuration getConfigType();
		std::string getConfigString();
		Type getType();
		std::string getTypeString();

		virtual size_t getNeuronsCount() = 0;
		virtual size_t getConnectionsCount() = 0;

		virtual void initRandomly() = 0;
		virtual void feedLayer() = 0;
		virtual void input_1d( Vector1d<nn_t> Input ) = 0;
		virtual Vector1d<nn_t> getOutput_1d() = 0;

	protected:
		virtual void activateNeurons() = 0;

	protected:
		Configuration m_Configuration;
		Type m_Type;
	};
}
