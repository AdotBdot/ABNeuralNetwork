#pragma once

#include <string>

#include "Config.h"

namespace abnn
{
	class DataSet
	{
	public:
		explicit DataSet();
		explicit DataSet( std::string PathToDataSet );

		void load( std::string PathToDataSet );
		void save( std::string OutputFile, bool Overwrite );
		void destroy();

	private:
		void loadFromJson( std::string PathToDataSet );
		void saveToJson( std::string OutputFile );
		struct Data
		{
			Vector1d<nn_t>In;
			Vector1d<nn_t>Out;
		};

		Vector1d<Data>* m_Sets1d;
		size_t m_1dInputsCount;
		size_t m_1dOutputsCount;
	};
}
