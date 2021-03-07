#include "Utility.h"

#include <random>

namespace abnn
{
	nn_t random()
	{
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen( rd() ); // seed the generator
		std::uniform_real_distribution<nn_t> distr( -1.f, 1.f );//define range

		return distr(gen);
	}
}
