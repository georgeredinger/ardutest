/*
 * MockSerialTest.cpp
 *
 *  Created on: Oct 5, 2011
 *      Author: nick
 */

#include "CppUTest/TestHarness.h"
#include "WPlatform.hpp"

TEST_GROUP(MockSerial) {

	void setup() {
		Serial.reset();
	}

	void teardown(){

	}
};

TEST(MockSerial, AvailableReturnsCorrectValue){
	uint8_t buffer[32] = { 0x00 };
	Serial.set_input_buffer(buffer, 32);
	uint32_t available = Serial.available();
	CHECK_EQUAL(32, available);
}

TEST(MockSerial, ReadReturnsCorrectValueForNoData){
	uint32_t available = Serial.available();
	CHECK_EQUAL(0, available);
	int val = Serial.read();
	CHECK_EQUAL(-1, val);
}

TEST(MockSerial, WriteBytePutsCorrectValuesInBuffer){
	uint8_t val = Serial._out_buf[0];
	CHECK_EQUAL(0, val);
	Serial.write(0x55);
	uint8_t new_val = Serial._out_buf[0];
	CHECK_EQUAL(0x55, new_val);
}

TEST(MockSerial, WriteArrayPutsCorrectValuesInBuffer){
	uint8_t array[5] = {1, 2, 3, 4, 5};
	Serial.write(array, 5);
	// Check the written values.
	for(int i = 0; i < 5; i++){
		CHECK_EQUAL(array[i], Serial._out_buf[i]);
	}
	// Check we haven't run off the array end.
	CHECK_EQUAL(0, Serial._out_buf[6]);
}

TEST(MockSerial, WriteBytePutsValuesInCorrectPlaceAfterWrite){
	Serial.write(5);
	Serial.write(10);
	CHECK_EQUAL(10, Serial._out_buf[1]);
}

TEST(MockSerial, WriteArrayPutsValuesInCorrectPlaceAfterWrite){
	Serial.write(20);
	uint8_t array[5] = {1, 2, 3, 4, 5};
	Serial.write(array, 5);
	// Check the written values.
	for(int i = 0; i < 5; i++){
		CHECK_EQUAL(array[i], Serial._out_buf[i+1]);
	}
	CHECK_EQUAL(20, Serial._out_buf[0]);
}
