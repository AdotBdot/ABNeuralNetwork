#include "DataSet.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using std::vector;
using std::to_string;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using json = nlohmann::json;

namespace abnn
{
	DataSet::DataSet()
	{
	}

	DataSet::DataSet( string PathToDataSet )
	{
		load( PathToDataSet );
	}

	void DataSet::load( string PathToDataSet )
	{
		string ext = PathToDataSet.substr( PathToDataSet.rfind( "." ), PathToDataSet.size() - 1 );

		if( ext == ".json" )
		{
			loadFromJson( PathToDataSet );
			return;
		}
		cout << "Unsupported data set file extension" << endl;
	}

	void DataSet::save( string OutputFile, bool Overwrite )
	{
	}
	void DataSet::destroy()
	{
		delete m_Sets1d;
	}
	void DataSet::loadFromJson( string PathToDataSet )
	{
		ifstream file;
		file.open( PathToDataSet );
		if( !file.good() )
		{
			//TODO: Error with file
			return;
		}

		json j;
		file >> j;

		size_t NumOfDS = j[ "NumOfDataSets" ];
		size_t NumOfInputs = j[ "NumOfInputs" ];
		size_t NumOfOutputs = j[ "NumOfOutputs" ];

		for( size_t i = 0; i < NumOfDS; i++ )
		{
			Data DT;

			DT.In = j[ "DT" + to_string( i ) ][ "In" ].get< vector<nn_t> >();
			DT.Out = j[ "DT" + to_string( i ) ][ "Out" ].get< vector<nn_t> >();

			m_Sets1d->push_back( DT );
		}


	}
	void DataSet::saveToJson( string OutputFile )
	{
		json j;

		j[ "NumOfDataSets" ] = m_Sets1d->size();
		j[ "NumOfInputs" ] = m_1dInputsCount;
		j[ "NumOfOutputs" ] = m_1dOutputsCount;

		for( size_t i = 0; i < m_Sets1d->size(); i++ )
		{
			j[ "DT" + to_string( i ) ][ "In" ] = m_Sets1d->at( i ).In;
			j[ "DT" + to_string( i ) ][ "Out" ] = m_Sets1d->at( i ).Out;
		}

		std::ofstream file( OutputFile, std::ios::trunc );
		file << j;
	}
}
