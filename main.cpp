/** This program moves the mouse by one pixel in a cycle (right, down, left, up) and waits for a random amount of time up to 10 seconds.
 *  Written for K64F. Not tested on other platforms.
 *  Stelian Saracut 2020
 */

#include "mbed.h"
#include "USBMouse.h"

// psuedo random number generator
unsigned int rnd()
{
    static uint32_t m_z = 12434, m_w = 33254;

    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);

    return ((m_z << 16) + m_w);
}

typedef struct
{
  int16_t x;
  int16_t y;
} pair_t;

// right, down, left, up
const pair_t moves[] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

USBMouse mouse;

int main()
{
  while (1)
  {
    for (uint32_t i = 0; i < 4; i++)
    {
      mouse.move(moves[i].x, moves[i].y);
      wait_ms(rand() % 10000);
    }
  }
}
