#include "manager.h"

/* Write your code here */

// Manager
Manager::Manager(): device_count(0) {}

Manager::~Manager() {
	for(int i = 0; i < device_count; i++)
		delete devices[i];
}

void Manager::add_device(Device* device) {
	if(device_count == MAX_DEVICES) {
		std::cout << "�� �̻� Device�� �߰��� �� �����ϴ�.\n";
		delete device;
		return;
	}
	for(int i = 0; i < device_count; i++)
		if(*devices[i] == *device)
			throw DuplicateDevice(device);
	devices[device_count++] = device;
}

bool Manager::compare_device(int index, const Device& other) const {
	return *devices[index] == other;
}

Device* Manager::find_device(const Device& search_device) const {
	for(int i = 0; i < device_count; i++)
		if(*devices[i] == search_device)
			return devices[i];
	return nullptr;
}

void Manager::delete_device(const Device& device) {
	int i;
	for(i = 0; !(*devices[i] == device) && i < device_count; i++);
	if(i == device_count) return;	// �ش��ϴ� device ���� 
	delete devices[i];
	for(++i; i < device_count; i++)
		devices[i - 1] = devices[i];
	--device_count;
}

void Manager::print_all_devices() const {
	for(int i = 0; i < device_count; i++)
		devices[i]->print_device();
}
