#pragma once

namespace abnn
{
	class TrainingStrategy
	{
	public:
		enum class LossFunction
		{
			MSE
		};

	private:
		float m_LearningRate;
	};
}
