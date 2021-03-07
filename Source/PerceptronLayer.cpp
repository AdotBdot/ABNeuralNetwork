#include "PerceptronLayer.h"

#include "Utility.h"

#include <algorithm>

using std::move;
using std::generate;

namespace abnn
{
	PerceptronLayer::PerceptronLayer()
		:Layer( Type::Perceptron )
		, m_UseBias( true )
		, m_ActFunc( Neuron::ActFunc::Linear )
		, m_PrevLayer( nullptr )
		, m_Neurons( 0 )
		, m_Biases( nullptr )
		, m_InWeights( nullptr )
	{
	}

	PerceptronLayer::PerceptronLayer( Configuration Configuration, PerceptronLayer* PrevLayer, size_t Size )
		:Layer( Type::Perceptron, move( Configuration ) )
		, m_UseBias( true )
		, m_ActFunc( Neuron::ActFunc::Linear )
		, m_PrevLayer( move( PrevLayer ) )
	{
		//Neurons Creation
		for( size_t n = 0; n < Size; n++ )
		{
			m_Neurons.push_back( new Neuron() );
		}

		if( m_Configuration == Configuration::Input )
		{
			m_InWeights = nullptr;
			m_Biases = nullptr;
		}
		else
		{
			//Connections Creation
			m_InWeights = new Synapses( m_PrevLayer->getNeuronsCount(), Size );

			//Biases Creation
			if( m_UseBias )
			{
				m_Biases = new Vector1d<nn_t>( Size, 0.f );
			}
			else
				m_Biases = nullptr;
		}
	}

	PerceptronLayer::~PerceptronLayer()
	{
		for( Neuron* n : m_Neurons )
			delete n;
		delete m_Biases;
		delete m_InWeights;
	}

	size_t PerceptronLayer::getNeuronsCount()
	{
		return m_Neurons.size();
	}

	size_t PerceptronLayer::getConnectionsCount()
	{
		return m_InWeights->getConnectionsCount();
	}

	void PerceptronLayer::activateNeurons()
	{
		for( Neuron* n : m_Neurons )
			n->activate( m_ActFunc );
	}

	void PerceptronLayer::initRandomly()
	{
		if( m_Configuration != Layer::Configuration::Input )
		{
			m_InWeights->initRandomly();
			for( nn_t n : *m_Biases )
				n = random();
		}
	}

	void PerceptronLayer::feedLayer()
	{
		if( m_Configuration != Configuration::Input )
		{
			input_1d( m_PrevLayer->getOutput_1d() );
			activateNeurons();
		}
	}

	void PerceptronLayer::input_1d( Vector1d<nn_t> Input )
	{
		if( m_Configuration == Configuration::Input )
			for( size_t i = 0; i < m_Neurons.size(); i++ )
			{
				m_Neurons[ i ]->input( Input.at( i ) );
			}
		else
			for( size_t n = 0; n < m_Neurons.size(); n++ )
			{
				nn_t InVal = 0.f;

				for( size_t prev_n = 0; prev_n < m_PrevLayer->getNeuronsCount(); prev_n++ )
				{
					InVal += Input[ prev_n ] * m_InWeights->getWeight( prev_n, n );
					if( m_UseBias )
						InVal += m_Biases->at( n );
				}

				m_Neurons[ n ]->input( InVal );
			}
	}

	void PerceptronLayer::setActFunc( Neuron::ActFunc ActFunc )
	{
		m_ActFunc = move( ActFunc );
	}

	Neuron::ActFunc PerceptronLayer::getActFunc()
	{
		return m_ActFunc;
	}

	Vector1d<nn_t> PerceptronLayer::getOutput_1d()
	{
		Vector1d<nn_t> Output;

		for( Neuron* n : m_Neurons )
			if( m_Configuration == Layer::Configuration::Input )
				Output.push_back( n->getInVal() );
			else
				Output.push_back( n->getActVal() );

		return Output;
	}
}