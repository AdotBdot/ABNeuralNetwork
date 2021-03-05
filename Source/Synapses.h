#pragma once

#include "Config.h"

namespace abnn
{
	class Synapses
	{
	public:
		Synapses();
		Synapses( size_t SizeX, size_t SizeY, bool InitRandomly = false );

		size_t sizeX();
		size_t sizeY();
		size_t getConnectionsCount();

		nn_t getWeight( size_t x, size_t y );

		void setWeight( size_t x, size_t y, nn_t weight );
		void initRandomly();

	private:
		size_t m_SizeX;
		size_t m_SizeY;
		Vector2d<nn_t>m_Connections;
	};
}
