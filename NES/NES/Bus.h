#pragma once
#include <cstdint>
#include "pch.h"

#include "cpu_6502.h"

class Bus
{

public:
	Bus();
	~Bus();


public:
	// DEVICES
	cpu_6502 cpu;

	std::array<uint8_t, 64 * 1024> ram;

public: // READ AND WRITE
	void Write(uint16_t addr, uint8_t data);
	uint8_t Read(uint16_t addr, bool bReadOnly = false);
};