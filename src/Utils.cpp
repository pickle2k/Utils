/*
Utils library of usefull stuff

Original Copyright (c) 2024 John P. Green. All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include <Arduino.h>
#include "Utils.h"

TON::TON() {
  ulACC = 0;
}

void TON::Main() {
  ulCurrent_time = millis();

  if (bEN) {
    if ((ulACC < 0) || (ulPRE < 0)) {
      // major fault
    } else {
      // set timer timing to true
      bTT = true;

      if (bDN) {
        // if done clear timer timing
        bTT = false;
        ulLast_time = ulCurrent_time;
      } else {
        ulDeltaT = ulCurrent_time - ulLast_time;
        ulLast_time = ulCurrent_time;
        ulACC = ulACC + ulDeltaT;

        if (ulACC >= ulPRE) {
          bTT = false;
          bDN = true;
        }
      }  // bDN
    }    // ACC < 0
  } else {
    ulLast_time = ulCurrent_time;
    ulACC = 0;
    bTT = false;
    bDN = false;
  }  // bEN
}

bool TON::DN() {
  Main();
  return bDN;
}

void TON::EN(bool value) {
  bEN = value;
}

bool TON::EN() {
  Main();
  return bEN;
}

bool TON::TT() {
  Main();
  return bTT;
}

void TON::RES() {
  ulACC = 0;
  bTT = false;
  bDN = false;
}

unsigned long TON::ACC() {
  Main();
  return ulACC;
}

void TON::PRE(unsigned long value) {
  ulPRE = value;
}

unsigned long TON::PRE() {
  Main();
  return ulPRE;
}
/*******************************************************************************
*
*******************************************************************************/
TOF::TOF() {
  ulACC = 0;
}

void TOF::Main() {
  ulCurrent_time = millis();

  if (!bEN) {
    if ((ulACC < 0) || (ulPRE < 0)) {
      // major fault
    } else {
      // set timer timing to true
      bTT = true;

      if (bDN) {
        // if done clear timer timing
        bTT = false;
        ulLast_time = ulCurrent_time;
      } else {
        ulDeltaT = ulCurrent_time - ulLast_time;
        ulLast_time = ulCurrent_time;
        ulACC = ulACC + ulDeltaT;

        if (ulACC >= ulPRE) {
          bTT = false;
          bDN = true;
        }
      }  // bDN
    }    // ACC < 0
  } else {
    ulLast_time = ulCurrent_time;
    ulACC = 0;
    bTT = false;
    bDN = false;
  }  // bEN
}


RTO::RTO() {
  ulACC = 0;
}

void RTO::Main() {
  ulCurrent_time = millis();

  if (bEN) {
    if ((ulACC < 0) || (ulPRE < 0)) {
      // major fault
    } else {
      // set timer timing to true
      bTT = true;

      if (bDN) {
        // if done clear timer timing
        bTT = false;
        ulLast_time = ulCurrent_time;
      } else {
        ulDeltaT = ulCurrent_time - ulLast_time;
        ulLast_time = ulCurrent_time;
        ulACC = ulACC + ulDeltaT;

        if (ulACC >= ulPRE) {
          bTT = false;
          bDN = true;
        }
      }  // bDN
    }    // ACC < 0
  } else {
    ulLast_time = ulCurrent_time;
    bTT = false;
    bDN = false;
  }  // bEN
}

Button::Button(int Pin, int STATE) {
  // https://docs.arduino.cc/retired/hacking/software/PortManipulation/
  switch (Pin) {
    case 0 ... 7:
      // PORTD maps to Arduino digital pins 0 to 7
      // DDRD - The Port D Data Direction Register - read/write
      // PORTD - The Port D Data Register - read/write
      // PIND - The Port D Input Pins Register - read only
      // DDRD = DDRD | B11111100; this is safer as it sets pins 2 to 7 as outputs without changing the value of pins 0 & 1, which are RX & TX
      DDRD = DDRD | ~Pin;
      break;
    case 8 ... 13:
      // PORTB
      DDRB = DDRB | ~Pin;
      break;

    default:
      // do nothing
      break;
  }
}

bool Button::Pressed() {
  return true;
}