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
	buffer_write_index = 0;
	buffer_read_index = 0;
}

// Saves a byte of data into the circullar buffer
bool AHComm::receive(data)
{
	// Save data into buffer
	buffer[buffer_write_index] = data;

	// Increment write pointer
	buffer_write_index++;

	// If write pointer is out of range start from beginning
	if (buffer_write_index == BUFFER_SIZE)
	{
		buffer_write_index = 0;
	}

	return true
}

// Returns true if a complete packet is found in buffer
int AHComm::packetAvailable()
{
	// Declare variables
	packet_found = false; // Used to stop while loop when complete

	// Iterate through buffer searching for packet
	while (!packet_found && ite<BUFFER_SIZE)
	{
		// Check if first two bytes in buffer are starting int
		if (buffer[buffer_read_index] == START_BYTE_HIGH)
		{
			// Check next byte
			if (buffer[buffer_read_index+1] == START_BYTE_LOW)
			{
				// Check if packet is complete
				packet_found = checkPacket(buffer_read_index);
			}
		}
		// If pointer does not refer to start byte move through buffer
		else 
		{
			buffer_read_index++;
		}
	}

	return packet_found
}

