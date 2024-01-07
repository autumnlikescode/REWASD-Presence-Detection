# Detecting REWASD Driver using C++

## Overview

This documentation provides insights into detecting the REWASD driver using C++. The code sample provided utilizes Windows API functions to enumerate loaded drivers and check if the REWASD driver, specifically "hidgamemap.sys," is present. This detection method can be useful for identifying whether REWASD, a popular gamepad mapping tool, is actively running on a Windows system.

## How It Works

The code works by enumerating the loaded kernel-mode drivers using the `EnumDeviceDrivers` function. It then checks the base name of each driver using `GetDeviceDriverBaseNameA` and compares it with the target driver name ("hidgamemap.sys"). If a match is found, the code prints a message indicating that the driver is loaded; otherwise, it prints a message indicating that the driver is not loaded. This method relies on the fact that REWASD utilizes the "hidgamemap.sys" driver, and its presence indicates the running state of the REWASD software.

## Prerequisites

Before using the provided code, make sure you have the following:

- A Windows environment to run the code.
- A C++ compiler, such as Visual Studio or GCC.
- Git installed on your system.

## Usage

1. Clone the source repository by running the following command in your terminal or command prompt:

    ```bash
    git clone https://github.com/your-username/rewasd-detector.git
    ```

2. Navigate to the cloned directory:

    ```bash
    cd rewasd-detector
    ```

3. Compile the code using your preferred C++ compiler:

    ```bash
    g++ rewasd_detector.cpp -o rewasd_detector
    ```

   or using Visual Studio, open the solution file and build the project.

4. Run the executable to check whether the REWASD driver is loaded on your system.

    ```bash
    ./rewasd_detector
    ```

## Code Explanation

```cpp
#include <windows.h>
#include <psapi.h>
#include <iostream>

// Function to check if the specified driver is loaded
bool IsDriverLoaded(const char* driverName) {
    LPVOID drivers[1024];
    DWORD cbNeeded;

    // Enumerate the loaded drivers
    if (EnumDeviceDrivers(drivers, sizeof(drivers), &cbNeeded)) {
        // Check if the target driver is in the list
        for (unsigned i = 0; i < cbNeeded / sizeof(drivers[0]); ++i) {
            char driverPath[MAX_PATH];
            // Retrieve the base name of the driver
            if (GetDeviceDriverBaseNameA(drivers[i], driverPath, sizeof(driverPath))) {
                // Compare with the target driver name
                if (strcmp(driverPath, driverName) == 0) {
                    std::cout << "Driver found: " << driverName << std::endl;
                    return true;
                }
            }
        }
    }
    else {
        std::cerr << "Error: EnumDeviceDrivers failed" << std::endl;
    }

    std::cout << "Driver not found: " << driverName << std::endl;
    return false;
}

int main() {
    const char* targetDriver = "hidgamemap.sys";
    // Check if the driver is loaded and print the result
    if (IsDriverLoaded(targetDriver)) {
        std::cout << "The driver " << targetDriver << " is loaded." << std::endl;
    }
    else {
        std::cout << "The driver " << targetDriver << " is not loaded." << std::endl;
    }

    system("PAUSE");

    return 0;
}
```

## Conclusion

This code snippet provides a simple method to detect the presence of the REWASD driver on a Windows system. It can be integrated into larger projects or used as a standalone tool for identifying REWASD usage. Keep in mind that the effectiveness of this detection method may vary based on system configurations and potential updates to the REWASD software.
