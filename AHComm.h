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

#ifndef AutoHomeComm_h
#define AutoHomeComm_h


#define details(name) (byte*)&name,sizeof(name)

#include "Arduino.h"

class AHComm
{
  public:
    bool packetAvailable();
    int getPacketSize();
    void receive(uint8_t byte);
    void transmit(uint8_t array[]);
    uint8_t * readPacket(uint8_t packet[]);

};

#endif