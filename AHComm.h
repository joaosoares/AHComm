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

class AutoHomeComm
{
  public:
  	void begin(uint8_t *, uint8_t);
  	void sendData();
  	void receiveData();
  private:
  	uint8_t * address; // address of the struct
  	uint8_t size; // size of the struct
  	uint8_t * rx_buffer; // address for temporary storage and parsing buffer
  	uint8_t rx_array_inx; // index for RX parsing buffer
  	uint8_t rx_len // RX packet length according to the packer
  	uint8_t calc_CS; // calculated checksum
  	enum Commands {
  		STATUS_REPORT
  	}
};

#endif