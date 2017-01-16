/**
 * Binary data processor base
 * This class could be inherited to be data processor.
 * ex) Data Compressor
 * ex) FFT
 *
 * This class provides basic binary read and write function.
 *
 * @author	Yuhei Horibe
 * @date	2017/1/8
 *
 **/

#include <iostream>
#include <fstream>
#include <vector>

// Base class definition of 
// Data Processor
class DataProcessorBase{
protected:
	typdef	std::vector<uint8_t>	DATA;

	// Input data and Output data
	DATA	m_inputData;
	DATA	m_outputData;

public:
	// Start reading data from file
	DataProcessorBase(std::string fileName);

	// Start reading data from input stream
	DataProcessorBase();

	// *****************************************
	// This is data processing method.
	// Need to be overriden.
	// *****************************************
	virtual bool StartProcess()	= 0;

	// Write down the output data.
	bool	WriteDown(std::string fileName);

	// Destructor
	~DataProcessorBase();
};

