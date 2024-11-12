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

#ifndef Utils_h
#define Utils_h

#include "Arduino.h"

/* All timers use the same data structure */
struct dtTimer {
  bool bEN;                       // Enable
  bool bTT;                       // Timing
  bool bDN;                       // Done
  bool bErr;                      // Error
  unsigned long ulPRE;            // Preset
  unsigned long ulACC;            // Accumulator
  unsigned long ulDeltaT;         // 
  unsigned long ulLast_time;      //
  unsigned long ulCurrent_time;   // 
};


class TON : public dtTimer
{
  public:
    TON();
    bool DN();
    void EN(bool value);
    bool EN();
    bool TT();
    void RES();
    void PRE(long value);
    long ACC();
  private:
    virtual void Main();
};

class TOF : public TON
{
  public:
    TOF();
  private:
    void Main();
};

class RTO : public TON
{
  public:
    RTO();
  private:
    void Main();
};

#endif
