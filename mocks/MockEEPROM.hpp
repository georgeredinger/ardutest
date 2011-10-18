/*
    Ardutest - An Arduino mocks library for unit testing.  

    Copyright (C) 2011 Mind Studios, Inc.

    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Lesser General Public License as published by the
    Free Software Foundation; either version 2.1 of the License, or (at your
    option) any later version.

    This library is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
    for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this library; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

    Mind Studios, Inc., hereby disclaims all copyright interest in the library
    Ardutest (an Arduino mocks library for unit testing) written by Nick
    Pascucci.
 */

/*!
  \file
  Mock EEPROM functionality for unit testing.
 */

#ifndef MOCKEEPROM_HPP_
#define MOCKEEPROM_HPP_

#include "inttypes.h"

/*!
  Size of the EEPROM buffer.
 */
const int EEPROM_SIZE = 1024; // We have 1k EEPROM memory in an atmega328p.

// We'll store our data here, so all of our functions can get to it.
/*!
  Simplified storage for EEPROM test data.
 */
class EEPROMBuffer {
private:
  uint8_t _buffer[EEPROM_SIZE];

public:
  /*!
    \brief Instantiate a new EEPROM buffer with the default size (1024).
   */
  EEPROMBuffer(void);

  /*!
    \brief Clear the contents of the EEPROM buffer.
   */
  void clear(void);

  /*!
    \brief Read one byte from the EEPROM buffer.

    This function takes an int pointer; this is to mimic the arguments of the 
    avr-libc EEPROM library. These addresses run from 0 to the size of the 
    buffer - 1. You can create these by casting an int to a uint8_t*.

    \param location A pointer to the EEPROM location.
    \return The byte stored at the given location.
   */
  uint8_t read_byte(uint8_t * location);

  /*!
    \brief Write one byte into the EEPROM buffer.

    This function takes an int pointer; this is to mimic the arguments of the 
    avr-libc EEPROM library. These addresses run from 0 to the size of the 
    buffer - 1. You can create these by casting an int to a uint8_t*.

    \param location A pointer to the location to write to.
    \param val The value to write.
   */
  void write_byte(uint8_t * location, uint8_t val);
};

/*!
  \brief Global EEPROM buffer object.
 */
extern EEPROMBuffer eeprom_data;

/*!
  \brief Read a byte from EEPROM.

  \param location A pointer to the EEPROM location.
  \return The value at the given location.
 */
uint8_t eeprom_read_byte(uint8_t * location);

/*!
  \brief Read a 16-bit word from EEPROM.

  \param location A pointer to the EEPROM location.
  \return The value at the given location.
 */
uint16_t eeprom_read_word(uint16_t * location);

/*!
  \brief Read a 32-bit double word from EEPROM.

  \param location A pointer to the EEPROM location.
  \return The value at the given location.
 */
uint32_t eeprom_read_dword(uint32_t * location);

/*!
  \brief Write a byte to EEPROM.

  \param location A pointer to the location to write to.
  \param value The value to write.
 */
void eeprom_write_byte(uint8_t * location, uint8_t value);

/*!
  \brief Write a 16-bit word to EEPROM.

  \param location A pointer to the location to write to.
  \param value The value to write.
 */
void eeprom_write_word(uint16_t * location, uint16_t value);

/*!
  \brief Write a 32-bit double word to EEPROM.

  \param location A pointer to the location to write to.
  \param value The value to write.
 */
void eeprom_write_dword(uint32_t * location, uint32_t value);

#endif /* MOCKEEPROM_HPP_ */
