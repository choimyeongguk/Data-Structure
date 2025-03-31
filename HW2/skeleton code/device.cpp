#include "device.h"

/* Write your code here */
using namespace std;

// Device
Device::Device(int id, const string& type, const string& brand):
	device_id(id), device_type(type), brand(brand) {}
	
Device::~Device() {}	// do nothing

// virtual void print_device() const = 0; 순수 가상 함수는 구현하지 않음 

bool Device::operator==(const Device& other) const {
	return device_id   == other.device_id
		&& device_type == other.device_type
		&& brand       == other.brand;
}
bool Device::operator<(const Device& other) const {
	return device_id < other.device_id;
}
bool Device::operator>(const Device& other) const {
	return device_id > other.device_id;
}
bool Device::operator<=(const Device& other) const {
	return device_id <= other.device_id;
}
bool Device::operator>=(const Device& other) const {
	return device_id >= other.device_id;
}

// Phone
Phone::Phone(int id, const string& brand, int data_usage):
	Device(id, "Phone", brand), data_usage(data_usage) {}
	
Phone::~Phone() {}

void Phone::print_device() const {
	cout << device_type << " [ID: "         << device_id
		 				<< ", Brand: "      << brand
		 				<< ", Data Usage: " << data_usage
						<< " GB]\n";
}

bool Phone::operator<(const Phone& other) const {
	return data_usage < other.data_usage;
}
bool Phone::operator>(const Phone& other) const {
	return data_usage > other.data_usage;
}
bool Phone::operator<=(const Phone& other) const {
	return data_usage <= other.data_usage;
}
bool Phone::operator>=(const Phone& other) const {
	return data_usage >= other.data_usage;
}

// Watch
Watch::Watch(int id, const string& brand, int step_count):
	Device(id, "Watch", brand), step_count(step_count) {}
	
Watch::~Watch() {}

void Watch::print_device() const {
	cout << device_type << " [ID: "         << device_id
		 				<< ", Brand: "      << brand
		 				<< ", Step Count: " << step_count
						<< "]\n";
}

bool Watch::operator<(const Watch& other) const {
	return step_count < other.step_count;
}
bool Watch::operator>(const Watch& other) const {
	return step_count > other.step_count;
}
bool Watch::operator<=(const Watch& other) const {
	return step_count <= other.step_count;
}
bool Watch::operator>=(const Watch& other) const {
	return step_count >= other.step_count;
}

// Ring
Ring::Ring(int id, const string& brand, bool sleep_tracking):
	Device(id, "Ring", brand), sleep_tracking(sleep_tracking) {}
	
Ring::~Ring() {}

void Ring::print_device() const {
	cout << device_type << " [ID: "             << device_id
		 				<< ", Brand: "          << brand
		 				<< ", Sleep Tracking: " << (sleep_tracking ? "Enabled" : "Disabled")
						<< "]\n";
}

// Earbud
Earbud::Earbud(int id, const string& brand, bool noise_cancel):
	Device(id, "Earbud", brand), noise_cancellation(noise_cancel) {}
	
Earbud::~Earbud() {}

void Earbud::print_device() const {
	cout << device_type << " [ID: " << device_id
		 				<< ", Brand: " << brand
		 				<< ", Noise Cancellation: " << (noise_cancellation ? "Yes" : "No")
						<< "]\n";
}
