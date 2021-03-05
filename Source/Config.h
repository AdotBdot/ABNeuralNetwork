#pragma once

#include <vector>

namespace abnn
{
#ifdef ABNN_USE_DOUBLE
	typedef double nn_t;
#else
	typedef float nn_t;
#endif

	template<typename T>
	using Vector1d = std::vector<T>;

	template<typename T>
	using Vector2d = std::vector<std::vector<T>>;

	

}
