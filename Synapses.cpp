#include "Synapses.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

#include "Config.h"
#include "Utility.h"

using std::generate;
using std::move;
using std::vector;

namespace abnn
{
	Synapses::Synapses()
		:m_SizeX( move( 0 ) )
		, m_SizeY( move( 0 ) )
		, m_Connections( 0 )
	{
	}

	Synapses::Synapses( size_t SizeX, size_t SizeY, bool InitRandomly )
		: m_SizeX( move( SizeX ) )
		, m_SizeY( move( SizeY ) )
	{
		for( size_t x = 0; x < SizeX; x++ )
		{
			std::vector<nn_t> Col( SizeY, 1.f );
			m_Connections.push_back( Col );
			if( InitRandomly )
			{
				initRandomly();
			}
		}
	}

	size_t Synapses::sizeX()
	{
		return m_SizeX;
	}

	size_t Synapses::sizeY()
	{
		return m_SizeY;
	}

	size_t Synapses::getConnectionsCount()
	{
		return m_SizeX * m_SizeY;
	}

	nn_t Synapses::getWeight( size_t x, size_t y )
	{
		if( x > m_SizeX || y > m_SizeY )
		{
			//TODO: exception
			return nn_t();
		}
		return m_Connections.at( x ).at( y );
	}

	void Synapses::setWeight( size_t x, size_t y, nn_t weight )
	{
		m_Connections.at( x ).at( y ) = move( weight );
	}


	void Synapses::initRandomly()
	{
		for( vector<nn_t>v : m_Connections )
		{
			for( nn_t n : v )
			{
				n = random();
			}
		}
	}
}