#pragma once

#include "ABNN.h"

#include <string>

using std::string;

namespace abnn
{
	class DataSet
	{
	public:
		explicit DataSet();
		explicit DataSet( string PathToDataSet );

		void load( string PathToDataSet );
		void save( string OutputFile, bool Overwrite );

	};
}
