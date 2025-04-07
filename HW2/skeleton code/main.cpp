/* 
    Test your implementation with some example test cases here.
    Feel free motify this file.
*/

#include "manager.h"
#include <iostream>
#include <exception>

int main() {
    Manager deviceManager;

    // Adding devices
    try {
        deviceManager.add_device(new Watch(1, "Apple", 10000));
        deviceManager.add_device(new Phone(2, "Samsung", 128));
        deviceManager.add_device(new Ring(3, "Amazon", true));
        deviceManager.add_device(new Earbud(4, "Sony", true));

        // Attempt to add a duplicate device
        deviceManager.add_device(new Watch(1, "Apple", 10000));  // This should throw an exception
    }
    catch (const DuplicateDevice& e) {
        std::cout << e.what() << std::endl;
        e.print_device_info();  // Print the device info directly
    }
    
    // Adding over 100 devices
    for(int i = 5; i <= 102; i++) {
    	deviceManager.add_device(new Phone(i, "GoodByeLG", 100));
	}

    // Print all devices
    std::cout << "All devices:" << std::endl;
    deviceManager.print_all_devices();

    // Test the compare_device function
    std::cout << "\nTesting compare_device function:" << std::endl;
    if (deviceManager.compare_device(1, Phone(2, "Samsung", 128))) {
        std::cout << "Device at index 1 matches the specified device." << std::endl;
    } else {
        std::cout << "Device at index 1 does not match the specified device." << std::endl;
    }
    
    if (deviceManager.compare_device(100, Phone(2, "Samsung", 128))) {
        std::cout << "Device at index 1 matches the specified device." << std::endl;
    } else {
        std::cout << "Device at index 1 does not match the specified device." << std::endl;
    }
    

    // Find a device
    Device* foundDevice = deviceManager.find_device(Phone(2, "Samsung", 128));
    if (foundDevice != nullptr) {
        std::cout << "\nFound device:" << std::endl;
        foundDevice->print_device();
    } else {
        std::cout << "\nDevice not found." << std::endl;
    }

    // Compare two phones
    Phone* applePhone = new Phone(1, "Apple", 128);
    Phone* samsungPhone = new Phone(2, "Samsung", 64);
    if (*applePhone < *samsungPhone) {
        std::cout << "\nApple phone has less data usage than Samsung phone." << std::endl;
    } else {
        std::cout << "\nApple phone has more data usage than Samsung phone." << std::endl;
    }

    // Compare one phone and one watch
    Device* newApplePhone = new Phone(1, "Apple", 128);
    Device* samsungWatch = new Watch(2, "Samsung", 10000);
    if (*newApplePhone < *samsungWatch) {
        std::cout << "\nThe ID of the new Apple phone is less than the ID of the Samsung watch." << std::endl;
    } else {
        std::cout << "\nThe ID of the new Apple phone is greater than the ID of the Samsung watch." << std::endl;
    }
    
    // Compare two phone and one watch
    Device* phone1 = new Phone(1, "Apple", 100);
    Device* phone2 = new Phone(2, "Samsung", 10);
    Device* watch = new Watch(3, "Xiaomi", 5);
    if(*phone1 < *phone2) {
    	std::cout << "���� Phone ������ ������ ��뷮�� ���Ѵ�!\n";
	}
	else {
		std::cout << "������� �ٷ� id�� ���ع���!!\n";
	}
	if(*phone2 < *watch) {
		std::cout << "�ٸ� �ڽ� ������ id�� ���Ѵ�!!\n";
	}
	else {
		std::cout << "��� ���� �ٷ� ���� �߻�����!!\n"; 
	} 

    // Compare two rings
    Device* amazonRing = new Ring(3, "Amazon", true);
    Device* samsungRing = new Ring(4, "Samsung", false);
    if (*amazonRing < *samsungRing) {
        std::cout << "\nThe ID of the Amazon ring is less than the ID of the Samsung ring." << std::endl;
    } else {
        std::cout << "\nThe ID of the Amazon ring is greater than the ID of the Samsung ring." << std::endl;
    }

    // Delete a device
    deviceManager.delete_device(Phone(2, "Samsung", 128));
    std::cout << "\nAfter deletion:" << std::endl;
    deviceManager.print_all_devices();
    
    // Call destructor
    std::cout << "\nAfter destruction:" << std::endl;
    deviceManager.~Manager();
    deviceManager.print_all_devices();
    return 0;
}
