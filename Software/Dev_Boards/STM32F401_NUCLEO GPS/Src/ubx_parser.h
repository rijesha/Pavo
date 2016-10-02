#include <stdbool.h>
#include "stm32f4xx_hal.h"


struct NAV_POSLLH {
  unsigned char cls;
  unsigned char id;
  unsigned short len;
  unsigned long iTOW;
  long lon;
  long lat;
  long height;
  long hMSL;
  unsigned long hAcc;
  unsigned long vAcc;
};

struct NAV_POSLLH posllh;
uint8_t raw_gps_buffer[100];



typedef bool (*char_available_t)(void *);
typedef uint8_t (*get_byte_t)(void *);

/** Device structure
 */
struct ubx_device {
  char_available_t char_available;      ///< check if a new character is available
  get_byte_t get_byte;                  ///< get a new char

  void *periph;                         ///< pointer to parent implementation

};

void calcChecksum(unsigned char* CK);
bool processGPS(struct ubx_device *gps_dev);
