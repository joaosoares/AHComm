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

#include "Arduino.h"

class AHComm
{
  public:
    bool packetAvailable();
    int getPacketSize();
    void receive(uint8_t byte);
    void transmit(uint8_t array[]);
    void readPacket(uint8_t packet[]);

  private:
    // Declare variables
	uint8_t buffer[BUFFER_SIZE]; // Buffer for storing packets
	int buffer_write_index; // Location of current write to buffer
	int buffer_read_index; // Location of first read to buffer
	// Declare Function
	bool checkPacket(startByte);
};

#endif