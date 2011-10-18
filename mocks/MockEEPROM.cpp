/*
 MockEEPROM.cpp
 
 Mock EEPROM functionality implementation.

 Created on: Oct 4, 2011
 Author: Nick
 */

#include "MockEEPROM.hpp"
#include "inttypes.h"

// Accessor functions for the mock.

uint8_t eeprom_read_byte(uint8_t * location) {
	return eeprom_data.read_byte(location);
}

uint16_t eeprom_read_word(uint16_t * location) {
	uint16_t val = (uint16_t) eeprom_data.read_byte((uint8_t *) location);
	val += (uint16_t) (eeprom_data.read_byte((uint8_t *) location + 1) << 8);
	return val;
}

uint32_t eeprom_read_dword(uint32_t * location) {
	uint32_t val = (uint32_t) eeprom_data.read_byte((uint8_t *) location);
	val += (uint32_t) (eeprom_data.read_byte((uint8_t *) location + 1) << 8);
	val += (uint32_t) (eeprom_data.read_byte((uint8_t *) location + 2) << 16);
	val += (uint32_t) (eeprom_data.read_byte((uint8_t *) location + 3) << 24);
	return val;
}

void eeprom_write_byte(uint8_t * location, uint8_t val) {
	eeprom_data.write_byte(location, val);
}

void eeprom_write_word(uint16_t * location, uint16_t val) {
	eeprom_data.write_byte((uint8_t *) location, (uint8_t) (val));
	eeprom_data.write_byte((uint8_t *) location + 1, (uint8_t) (val >> 8));
}

void eeprom_write_dword(uint32_t * location, uint32_t val) {
	eeprom_data.write_byte((uint8_t *) location, (uint8_t) (val));
	eeprom_data.write_byte((uint8_t *) location + 1, (uint8_t) (val >> 8));
	eeprom_data.write_byte((uint8_t *) location + 2,
			(uint8_t) (val >> 16));
	eeprom_data.write_byte((uint8_t *) location + 3,
			(uint8_t) (val >> 24));
}

// EEPROMBuffer method declarations.

EEPROMBuffer::EEPROMBuffer(void) {
	clear();
}

void EEPROMBuffer::clear(void) {
	_buffer = {0x00};
}

uint8_t EEPROMBuffer::read_byte(uint8_t * location) {
	return _buffer[(uint32_t) location];
}

void EEPROMBuffer::write_byte(uint8_t * location, uint8_t val) {
	_buffer[(uint32_t) location] = val;
}

// Preinstantiate the EEPROM buffer.

EEPROMBuffer eeprom_data = EEPROMBuffer();
