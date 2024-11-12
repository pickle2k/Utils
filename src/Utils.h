/*
  Utils.h - My library of usefull stuff
  Original Copyright (c) 2024 John P. Green. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
  Prefix | Data type     | Bytes | Range
  -------+---------------+-------+------------------------------------------------------
  i      | int           |   2   | -32768 to 32767
  ui     | unsigned int  |   2   | 0 to 65535
  l      | long          |   4   | -2147483648 to 2147483647
  ul     | unsigned long |   4   | 4294967295
  f      | float         |   4   | 3.4028235e+38 to -3.4028235e+38
  b      | boolean       |   1   | false(0) or true(1)
  ch     | char          |   1   | -128 to 127
  by     | byte          |   1   | 0 to 255
*/

#ifndef Utils_h
#define Utils_h

#include "Arduino.h"

#define D1 B0000001
#define D2 B0000010


/* All timers use the same data structure */
struct dtTimer {
  bool bEN;                      // Enable
  bool bTT;                      // Timer Timing
  bool bDN;                      // Done
  bool bErr;                     // Error
  unsigned long ulPRE;           // Preset
  unsigned long ulACC;           // Accumulator
  unsigned long ulDeltaT;        // Difference between current and last time
  unsigned long ulLast_time;     // Last time calculation was executed
  unsigned long ulCurrent_time;  // Current time from millis()
};

struct dtButton {
  unsigned long ulDeltaT;        // Difference between current and last time
  unsigned long ulLast_time;     // Last time calculation was executed
  unsigned long ulCurrent_time;  // Current time from millis()
};

/*!
 * @class TON
 * @brief On-delay timer class
 */
class TON : public dtTimer {
public:
  TON();
  /*!
   * @brief Returns the done state of the timer
   * @return Returns true if the timer is complete
   */
  bool DN();
  /*!
   * @brief Sets the enable state of the timer
   * @param Value Set to true to enable timer, false to disable
   */
  void EN(bool value);
  /*!
   * @brief Returns the enable state of the timer
   * @return Returns true if the timer is enabled
   */
  bool EN();
  /*!
   * @brief Returns the timing state of the timer
   * @return Returns true if the timer is timing
   */
  bool TT();
  /*!
   * @brief Resets the timer
   */
  void RES();
  /*!
   * @brief Sets the preset timer value of the timer
   * @param Value The required timer value in milliseconds
   */
  void PRE(unsigned long value);
  /*!
   * @brief Returns the preset timer value of the timer
   * @return Returns the preset time in milliseconds
   */
  unsigned long PRE();
  /*!
   * @brief Returns the accrued time of the timer
   * @return Returns the accrued time in milliseconds
   */
  unsigned long ACC();
private:
  /*!
   * @brief Main timer function
   * Main is declared as virtual as it is redefined in subsequent inheritance
   * (polymorphism)
   */
  virtual void Main();
};

/*!
 * @class TOF
 * @brief Off-delay timer class
 * Inherits from TON.
 */
class TOF : public TON {
public:
  TOF();
private:
  void Main();
};

/*!
 * @class RTO
 * @brief Retentive On-delay timer class
 * Inherits from TON.
 */
class RTO : public TON {
public:
  RTO();
private:
  void Main();
};

/*!
 * @class Button
 * @brief Push button class
 */
class Button : public dtButton {
public:
  Button(int Pin, int Pullup);

  bool Pressed();

  bool Pressed(unsigned long value);

  bool Released();

  bool Released(unsigned long value);

private:
};


#endif