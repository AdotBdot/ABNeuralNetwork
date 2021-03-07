#pragma once

#include "NeuralNet.h"
#include "DataSet.h"

namespace abnn
{
	class TrainingStrategy
	{
	public:
		enum class LossFunction
		{
			MSE
		};

		TrainingStrategy();
		TrainingStrategy( NeuralNet* NeuralNetPtr, DataSet* DataSerPtr );
		~TrainingStrategy();

		void setLearningRate( float Rate );
		void setDesiredError( float Goal );

		void print();

	private:
		NeuralNet* m_NeuralNet;
		DataSet* m_DataSet;

		float m_LearningRate;
		float m_DesiredError;
	};
}
