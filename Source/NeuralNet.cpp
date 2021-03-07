#include "NeuralNet.h"

#include "Layer.h"
#include "PerceptronLayer.h"

#include <string>

using std::string;

namespace abnn
{
	NeuralNet::NeuralNet()
		:m_Type( Type::Perceptron )
	{
	}

	void NeuralNet::setActivationFuncLayer( size_t Layer, Neuron::ActFunc ActivationFunc )
	{
		switch( m_Layers.at(Layer)->getType() )
		{
		case Layer::Type::Perceptron:
		{
			PerceptronLayer* pl = dynamic_cast<PerceptronLayer*>( m_Layers.at( Layer ) );
			pl->setActFunc( ActivationFunc );
		}
		default:
			break;
		}
	}

	void NeuralNet::setActivationFuncGlobal( Neuron::ActFunc ActivationFunc )
	{
		for( size_t i = 0;i<m_Layers.size();i++ )
		{
			setActivationFuncLayer( i, ActivationFunc );
		}
	}

	void NeuralNet::createPerceptron( std::vector<size_t> Topology, bool initRandomly )
	{
		m_Type = Type::Perceptron;

		for( size_t i = 0; i < Topology.size(); i++ )
		{
			Layer* l;
			if( i == 0 )
				l = new PerceptronLayer( Layer::Configuration::Input, nullptr, Topology.at( i ) );
			else if( i < Topology.size() - 1 )
				l = new PerceptronLayer( Layer::Configuration::Hidden, dynamic_cast<PerceptronLayer*>( m_Layers.back() ), Topology.at( i ) );
			else
				l = new PerceptronLayer( Layer::Configuration::Output, dynamic_cast<PerceptronLayer*>( m_Layers.back() ), Topology.at( i ) );
			m_Layers.push_back( l );
		}

		if( initRandomly )
		{
			for( Layer* l : m_Layers )
			{
				l->initRandomly();
			}
		}
	}

	void NeuralNet::feedNetwork_1d( Vector1d<nn_t> InputVector )
	{
		m_Layers.front()->input_1d( InputVector );
		for( Layer* l : m_Layers )
		{
			l->feedLayer();
		}
	}

	Vector1d<nn_t> NeuralNet::getOutput_1d()
	{
		return m_Layers.back()->getOutput_1d();
	}

	NeuralNet::Type NeuralNet::getType()
	{
		return m_Type;
	}

	std::string NeuralNet::getTypeString()
	{
		switch( m_Type )
		{
		case abnn::NeuralNet::Type::Perceptron:
			if( m_Layers.size() > 3 )
				return "Multilayer Perceptron";
			else
				return "Perceptron";
			break;
		case abnn::NeuralNet::Type::Convolutional:
			return "Convolutional";
			break;
		default:
			return string();
			break;
		}
	}
}