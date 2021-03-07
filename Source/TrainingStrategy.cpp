#include "TrainingStrategy.h"

#include <algorithm>

using std::move;

abnn::TrainingStrategy::TrainingStrategy()
	:m_NeuralNet( nullptr )
	, m_DataSet( nullptr )
	, m_LearningRate( 0.7f )
	, m_DesiredError( 0.1f )
{
}

abnn::TrainingStrategy::TrainingStrategy( NeuralNet* NeuralNetPtr, DataSet* DataSerPtr )
	:m_NeuralNet( NeuralNetPtr )
	, m_DataSet( DataSerPtr )
	, m_LearningRate( 0.7f )
	, m_DesiredError( 0.1f )
{
}

abnn::TrainingStrategy::~TrainingStrategy()
{
}

void abnn::TrainingStrategy::setLearningRate( float Rate )
{
	m_LearningRate = move( Rate );
}

void abnn::TrainingStrategy::setDesiredError( float Goal )
{
	m_DesiredError = move( Goal );
}

void abnn::TrainingStrategy::print()
{
}
