#include <windows.h>
#include <psapi.h>
#include <iostream>

#include "obfuscate.h"


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
                    std::cout << OBF("Driver found: ") << driverName << std::endl;
                    

                    if (SimulateGame)
                        MessageBox(
                            NULL,
                            (LPCWSTR)OBF(L"Not-Vanguard has detected the following incompatible software on your system: \n\n hidgamemap.sys \n\n\n To play Not-Vanguard protet games you will need to remove any incompatible software. \n\n Would you like to learn more?"),
                            (LPCWSTR)OBF(L"Not-Riot Not-Vanguard"),
                            MB_ICONWARNING | MB_YESNO
                        );

                    return true;
                }
            }
        }
    }
    else {
        std::cerr << OBF("Error: EnumDeviceDrivers failed") << std::endl;
    }



    std::cout << OBF("Driver not found: ") << driverName << std::endl;
    return false;
}

void mainCode()
{
    const char* targetDriver = "hidgamemap.sys";
    if (IsDriverLoaded(targetDriver)) {
        std::cout << OBF("The driver ") << targetDriver << OBF(" is loaded.") << std::endl;
    }
    else {
        std::cout << OBF("The driver ") << targetDriver << OBF(" is not loaded.") << std::endl;
    }

    system(OBF("PAUSE"));
}
int main() {

    WATERMARK("                                       .      .     .  .                                            ",
        "                                  .  .  . ..  .  .  .  .  .  ..  .                                  ",
        "                            .        .  .  .  .. .. .. .  ..  .  .                                  ",
        "                               .  .  ..  . .. ..  .  .  .  .  .    .. .                             ",
        "                         .    ..  ..  .  .. .  .. ........  . ..       .                            ",
        "                           .    .  .. .. .. ........ .. ... .  .. ..  .  .                          ",
        "                       .   .    .  .. .. ...... .... ..  ..... ..  . ..  ..  .                      ",
        "                      . .  ........ ........................... ..  .  .     .                      ",
        "                     .   .       .  .. ..........:;:...... ... ... ..  ..  .  .  .                  ",
        "                  .      ... .. ...............:+xxx;........ ... .... ..  .                        ",
        "                   . ..  .  ..................+x+;.;+x;......... ... ..  . ..  .   .                ",
        "             .       .  ..  .. .. ..........;++:.:;:.;x+:........... .. ..  . ..  .                 ",
        "                ..  .  .. ... ............;x+:...:+:...;x+:............ ..  .  .  .  .              ",
        "                 . ..  .  .. ...........:+x;....::+:....:+x+:................  .     .              ",
        "              .     .. ...............:++;.....::++;......:+x;:............  ...  .                 ",
        "               . .  ..  ............:+x+:......:;+;+:.......:+x;...........  ..  ..                 ",
        "            .    ..  .............:+x+:.......::++:+:.........;+x;.............  .  . .             ",
        "             .    .. ............;++:.........::+;:++..........:;x+:........... ..  .  .            ",
        "              ..  .. ..........;+x;..........::;x;:;x:...........:+x+:......... ..                  ",
        "                .   .........:+x;:;..........::++;::++...........;;:+x+........  .   .              ",
        "             .  ..  ........+x+:.:;:........::;x+:::++...........;;::;x+:........ .  .              ",
        "                . .  ........;x+::;..........:;x+::;x:...........;;;++;......... ..                 ",
        "                  .. .........:+x+;..........::+x;:;+............;xx+..........   .  .              ",
        "            ..  .  . ...........:+x;:.........:;x;:+;..........:+x+:.......... .    .               ",
        "                .  .  . ..........:+x;........::++:+:........:;x+:........... ...  .   .            ",
        "                 ...  ..............:+x;.......:;+;;........;x+:............   .  .   .             ",
        "              .   .  .  . ............;x+:.....::++;......;++;............. ...  .   .              ",
        "              .     ..  . ..............;x+:....:;+:....:+x;............ ..  .  .                   ",
        "                .  .   ..  . ............:+x+:...:+:..:+x+............ .  .  .  .  .                ",
        "                .  .  .   . . .. ..........:+x;:.::::+x+:.......... .. .. .  .  .  .                ",
        "                     ..  . .   ..............:x+;::+x+:............. . .. .  .  .                   ",
        "                        .   .. .  .. ..........;xxx+:...........  .  .  .  .                        ",
        "                .  .   . .  .. ..  .. ...........;;.......... ... .. .  .  .  .                     ",
        "                    .     .    ..  .. .. .. .............. ..  .. .. ..    .  .  .                  ",
        "                          .      . .  .. ............ ..  . .  .      .  .                          ",
        "                      ..    ..  ..  . . ..  . ..  . . .. ... .. .. .   .                            ",
        "                                    ..   . ..  . .. ..  . .  .  .  .   .                            ",
        "                          .   .  .    .   . .  .. .  .  .  .               .                        ",
        "                              .  .    ..     . .  .  .. .  .  ..  .  .                              ",
        "                                   ..     .       .        .                                        ",
        "                                .        .    .    .    .        .  .                               ",
        "                                              .        .     .                                   ")

    mainCode();
    return 0;
}
