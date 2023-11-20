#include "Bus.h"

Bus::Bus() {
	// clear RAM for no overlap of memory

	for (auto& i : ram) i = 0x00;

	// Create instance of bus to connect with CPU

	cpu.ConnectBus(this);
}

Bus::~Bus() {

}


void Bus::Write(uint16_t addr, uint8_t data) {

	if (addr >= 0x0000 and addr <= 0xFFFF)
		ram[addr] = data;
}


uint8_t Bus::Read(uint16_t addr, bool bReadOnly = false) {
	if (addr >= 0x0000 and addr <= 0xFFFF)
		return ram[addr];

	return 0x00;
}