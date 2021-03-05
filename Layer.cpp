#include "Layer.h"

#include <algorithm>
#include <string>

using std::move;
using std::string;

namespace abnn
{
	Layer::Layer()
		:m_Configuration( Configuration::Hidden )
		, m_Type( Type::Perceptron )
	{
	}

	Layer::Layer( Type _Type, Configuration _Configuration )
		: m_Configuration( move( _Configuration ) )
		, m_Type( move( _Type ) )
	{
	}

	Layer::~Layer()
	{
	}

	Layer::Configuration Layer::getConfigType()
	{
		return m_Configuration;
	}

	std::string Layer::getConfigString()
	{
		switch( m_Configuration )
		{
		case Configuration::Input:
			return "Input";
		case Configuration::Hidden:
			return "Hidden";
		case Configuration::Output:
			return "Output";
		default:
			return std::string();
			break;
		}
	}

	Layer::Type Layer::getType()
	{
		return m_Type;
	}

	std::string Layer::getTypeString()
	{
		switch( m_Type )
		{
		case abnn::Layer::Type::Perceptron:
			return "Perceptron";
			break;
		default:
			return string();
			break;
		}
	}
}