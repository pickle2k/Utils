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

TON::TON()
{
  ulACC = 0;
}

void TON::Main()
{
  ulCurrent_time = millis();

  if(bEN)
  {
    if((ulACC < 0)||(ulPRE < 0))
    {
      // major fault
    } else {
      // set timer timing to true
      bTT = true;
 
      if(bDN)
      {
        // if done clear timer timing
        bTT = false;
        ulLast_time = ulCurrent_time;
      } else {
        ulDeltaT = ulCurrent_time - ulLast_time;
        ulLast_time = ulCurrent_time;
        ulACC = ulACC + ulDeltaT;

        if(ulACC >= ulPRE)
        {
          bTT = false;
          bDN = true;
        }
      } // bDN
    } // ACC < 0
  } else {
    ulLast_time = ulCurrent_time;
    ulACC = 0;
    bTT = false;
    bDN = false;
  } // bEN

}

bool TON::DN()
{
  Main();
  return bDN;
}

void TON::EN(bool value)
{
  bEN = value;
}

bool TON::EN()
{
  return bEN;
}

bool TON::TT()
{
  return bTT;
}

void TON::RES()
{
  ulACC = 0;
  bTT = false;
  bDN = false;
}

long TON::ACC()
{
  return ulACC;
}

void TON::PRE(long value)
{
  ulPRE = value;
}

/*******************************************************************************
*
*******************************************************************************/
TOF::TOF()
{
  ulACC = 0;
}

void TOF::Main()
{
  ulCurrent_time = millis();

  if(!bEN)
  {
    if((ulACC < 0)||(ulPRE < 0))
    {
      // major fault
    } else {
      // set timer timing to true
      bTT = true;
 
      if(bDN)
      {
        // if done clear timer timing
        bTT = false;
        ulLast_time = ulCurrent_time;
      } else {
        ulDeltaT = ulCurrent_time - ulLast_time;
        ulLast_time = ulCurrent_time;
        ulACC = ulACC + ulDeltaT;

        if(ulACC >= ulPRE)
        {
          bTT = false;
          bDN = true;
        }
      } // bDN
    } // ACC < 0
  } else {
    ulLast_time = ulCurrent_time;
    ulACC = 0;
    bTT = false;
    bDN = false;
  } // bEN

}


RTO::RTO()
{
    ulACC = 0;
}

void RTO::Main()
{
 ulCurrent_time = millis();

  if(bEN)
  {
    if((ulACC < 0)||(ulPRE < 0))
    {
      // major fault
    } else {
      // set timer timing to true
      bTT = true;
 
      if(bDN)
      {
        // if done clear timer timing
        bTT = false;
        ulLast_time = ulCurrent_time;
      } else {
        ulDeltaT = ulCurrent_time - ulLast_time;
        ulLast_time = ulCurrent_time;
        ulACC = ulACC + ulDeltaT;

        if(ulACC >= ulPRE)
        {
          bTT = false;
          bDN = true;
        }
      } // bDN
    } // ACC < 0
  } else {
    ulLast_time = ulCurrent_time;
    bTT = false;
    bDN = false;
  } // bEN

}
