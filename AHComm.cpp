/**
 * AUTO HOME COMMUNICATIONS LIBRARY
 * A library that will create SPI-based communications between to connected
 * devices to transfer AutoHome data such as status reports from modules and
 * commands from the motherboard.
 *
 * By João Soares, Paulo Carvalho
 * July 2013
 */


#include <AutoHomeComm.h>

// Captures addressa and size of struct
void AutoHomeComm::begin(uint8_t * ptr, uint8_t length)
{
	address = prt;
	size = length;

	// dynamic creation of rx parsing buffer in RAM
	rx_buffer = (uint8_t *) malloc(size);
}

// Sends out struct in binary, with header, length info and checksum
void AutoHomeComm::sendData()
{
	uint8_t CS = size;
	
}