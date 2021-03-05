#include "Utility.h"

#include <random>

namespace abnn
{
	nn_t random()
	{
		return std::rand() / static_cast<nn_t>( RAND_MAX );
	}
}
