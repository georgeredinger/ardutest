/*!
  Unit tests for the EEPROM mock object.
 */

#include "CppUTest/TestHarness.h"
#include "mocks/MockEEPROM.hpp"

TEST_GROUP(MockEEPROM) {

	void setup() {

	}

	void teardown(){
		eeprom_data.clear();
	}
};

TEST(MockEEPROM, TestWriteByteWritesByte){
	uint8_t initial_val = eeprom_read_byte(0);
	CHECK_EQUAL(0, initial_val);
	eeprom_write_byte(0, 54);
	uint8_t new_val = eeprom_read_byte(0);
	CHECK_EQUAL(54, new_val);
}

TEST(MockEEPROM, TestWriteWordWritesWord){
	uint16_t initial_val = eeprom_read_word(0);
	CHECK_EQUAL(0, initial_val);
	eeprom_write_word(0, 512); // Want to write something that takes 2 bytes
	uint16_t new_val = eeprom_read_word(0);
	CHECK_EQUAL(512, new_val);
}

TEST(MockEEPROM, TestWriteDWordWritesDWord){
	uint32_t initial_val = eeprom_read_dword(0);
	CHECK_EQUAL(0, initial_val);
	uint32_t test_val = 1155905152;
	eeprom_write_dword(0, test_val); // A bit for each byte
	uint32_t new_val = eeprom_read_dword(0);
	CHECK_EQUAL(test_val, new_val);
}
