/**
 * AUTO HOME COMMUNICATIONS LIBRARY
 * A library that will create SPI-based communications between to connected
 * devices to transfer AutoHome data such as status reports from modules and
 * commands from the motherboard.
 *
 * By João Soares, Paulo Carvalho
 * July 2013
 *
 * Code for this is taken from madsci1016's EasyTransfer library,
 * available in the GNU Public License.
 */

#ifndef AHComm_h
#define AHComm_h

#define BUFFER_SIZE 255
#define START_BYTE_HIGH 254
#define START_BYTE_LOW 254
#define HEADER_SIZE 9
#define ID_SIZE 4
#define CHECKSUM_SIZE 2

#include "Arduino.h"

class AHComm
{
  public:
    AHComm(uint16_t);
  	unsigned int module_type; // Used for checking ID
    bool packetAvailable();
    int packetSize();
    bool receive(uint8_t byte);
    void transmit(uint8_t array[]);
    void readPacket(uint8_t packet[], uint16_t length);

  private:
    // Declare variables
	uint8_t buffer[BUFFER_SIZE]; // Buffer for storing packets
	int buffer_write_index; // Location of current write to buffer
	int buffer_read_index; // Location of first read to buffer
	// Declare Function
	bool checkPacket(uint16_t start_byte);
};

#endif