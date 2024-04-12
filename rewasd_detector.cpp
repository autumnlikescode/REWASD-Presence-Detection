#include <windows.h>
#include <psapi.h>
#include <iostream>


bool SimulateGame = false;

INLINE bool IsDriverLoaded(const char* driverName) {
    // Enumerate the loaded drivers
    LPVOID  drivers[1024];
    DWORD cbNeeded;

    if (EnumDeviceDrivers(drivers, sizeof(drivers), &cbNeeded)) {
        // Check if the target driver is in the list
        for (unsigned i = 0; i < cbNeeded / sizeof(drivers[0]); ++i) {
            char driverPath[MAX_PATH];
            if (GetDeviceDriverBaseNameA(drivers[i], driverPath, sizeof(driverPath))) {
                if (strcmp(driverPath, driverName) == 0) {
                    std::cout << "Driver found: " << driverName << std::endl;
                    

                    if (SimulateGame)
                        MessageBox(
                            NULL,
                            (LPCWSTR)L"Not-Vanguard has detected the following incompatible software on your system: \n\n hidgamemap.sys \n\n\n To play Not-Vanguard protet games you will need to remove any incompatible software. \n\n Would you like to learn more?",
                            (LPCWSTR)L"Not-Riot Not-Vanguard",
                            MB_ICONWARNING | MB_YESNO
                        );

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

void mainCode()
{
    const char* targetDriver = "hidgamemap.sys";
    if (IsDriverLoaded(targetDriver)) {
        std::cout << "The driver " << targetDriver << " is loaded." << std::endl;
    }
    else {
        std::cout << "The driver " << targetDriver << " is not loaded." << std::endl;
    }

    system("PAUSE");
}
int main() {
    mainCode();
    return 0;
}
