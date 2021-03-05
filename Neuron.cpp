#include "Neuron.h"

#include "Config.h"

#include <algorithm>
#include <cmath>

using std::exp;
using std::move;

namespace abnn
{
	Neuron::Neuron()
		: x( move( 0.f ) )
		, y( move( 0.f ) )
		, d( move( 0.f ) )
	{
	}

	Neuron::~Neuron()
	{
	}

	void Neuron::input( nn_t inValue )
	{
		x = move( inValue );
	}

	void Neuron::activate( ActFunc ActivationFunction )
	{
		switch( ActivationFunction )
		{
		case ActFunc::Threshold:
			y = ( x >= 0 ) ? 1.f : 0.f;
			break;
		case ActFunc::Linear:
			y = x;
			break;
		case ActFunc::Sigmoid:
			y = 1.f / ( 1.f + exp( x * -2.f ) );
			break;
		case ActFunc::Tanh:
			y = 2.f / ( 1.f + exp( x * -2.f ) ) - 1.f;
			break;
		case ActFunc::ReLu:
			y = ( x >= 0 ) ? x : 0.f;
			break;
		case ActFunc::ExpLinear:
			y = ( x >= 0 ) ? x : ( exp( x ) - 1.f );
			break;
		default:
			break;
		}
	}

	void Neuron::derive( ActFunc ActivationFunction )
	{
		switch( ActivationFunction )
		{
		case ActFunc::Threshold:
			d = 0.f;
			break;
		case ActFunc::Linear:
			d = 1.f;
			break;
		case ActFunc::Sigmoid:
			d = 2.f * y * ( 1.f - y );
			break;
		case ActFunc::Tanh:
			d = 1.f - ( y * y );
			break;
		case ActFunc::ReLu:
			d = ( x >= 0 ) ? 1.f : 0.f;
			break;
		case ActFunc::ExpLinear:
			d = ( x >= 0 ) ? 1.f : y;
			break;
		default:
			break;
		}
	}

	nn_t Neuron::getInVal()
	{
		return x;
	}

	nn_t Neuron::getActVal()
	{
		return y;
	}

	nn_t Neuron::getDerivVal()
	{
		return d;
	}
}