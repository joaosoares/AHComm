/**
 * AUTO HOME COMMUNICATIONS LIBRARY
 * A library that will create SPI-based communications between to connected
 * devices to transfer AutoHome data such as status reports from modules and
 * commands from the motherboard.
 *
 * By João Soares, Paulo Carvalho
 * July 2013
 */


#include <AHComm.h>

AHComm::AHComm()
{



}

// Saves a byte of data into the circullar buffer
bool AHComm::receive(data)
{
	// Save data into buffer
	buffer[buffer_write_index] = data;

	// Increment write pointer
	buffer_write_index++;

	// If write pointer is out of range start from beginning
	if (buffer_write_index == 255)
	{
		buffer_write_index = 0;
	}

	return true
}

