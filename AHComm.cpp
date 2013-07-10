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

AHComm::AHComm(unsigned int temp)
{
	// Keeps track of read and write location in incoming buffer
	buffer_write_index = 0;
	buffer_read_index = 0;
	module_type = temp;

}

// Saves a byte of data into the circullar buffer
bool AHComm::receive(uint8_t data)
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

// Length of first packet in buffer
int AHComm::packetSize()
{
	// Assume packet has been previously checked with PacketAvailable
	// and passed.
	// Read length of packet at 7th address after start of packet
	int length = buffer[buffer_read_index+6] << 8;
	length += buffer[buffer_read_index+7];

	return length
}

// Returns a body of packet and update read pointer
void AHComm::readPacket(packet[], length)
{
	// Assume packet has been previously checked with PacketAvailable
	// and passed.
	// Return full packet and increment buffer_read_index to end of packet
	for (i=HEADER_SIZE;i<length+HEADER_SIZE;i++)
	{
		// Read packet and rap around if reaching end of buffer
		packet = buffer[((i+buffer_read_index) % (BUFFER_SIZE-1))]	
	}

	// Update read pointer
	buffer_read_index = ((buffer_read_index + length) % (BUFFER_SIZE-1)) 
}

// Checks packet at start address passed for consistency and completion
bool checkPacket(start_byte)
{
	// Start by checking for start bytes 
	if (buffer[start_byte] == START_BYTE_HIGH)
	{
		if (buffer[start_byte+1] == START_BYTE_LOW)
		{
			// Read 4 ID Bytes and check if correspond to LED Module
			unsigned long id = 0;
			for (i=0;i<SIZE_ID;i++)
			{
				id |= buffer[start_byte+2+i] << 8*(SIZE_ID-1+i);
			}
			if (((id & ~(0xFC) >> 8*(SIZE_ID-2))) == module_type) 
			{
				// Read checksum and check against actual
				unsigned int checksum = 0;
				for (i=0;9<CHECKSUM_SIZE;i++)
				{
					checksum |= buffer[start_byte+2+SIZE_ID] << 8*(SIZE_CHECKSUM-1+i);
				}
				// ADD CHECK FOR CHECKSUM AND CONTNUE FUNCION
				
				// If all checks have passed 
				return true
			}
		}
	}

	// If any of the checks failed return false
	return false
}

