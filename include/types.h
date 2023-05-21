#ifndef _TYPES_H_
#define _TYPES_H_

#include <windows.h>
#include <stdio.h>

// https://learn.microsoft.com/en-us/windows-hardware/drivers/ifs/what-determines-when-a-driver-is-loaded#driver-start-types
#define DRIVER_LOADED       0x00000001
#define DRIVER_UNLOADED     0x00000004
#define DRIVER_STARTED      0x00000002
#define DRIVER_STOPPED      0x00000003
#define DRIVER_LOADING_ERR    0x00000010
#define DRIVER_UNLOADING_ERR  0x00000040
#define DRIVER_START_ERR   0x00000020
#define DRIVER_STOP_ERR    0x00000030
#define BUFFER_SIZE 256

#define Rec(a, b, c) {a = b; goto c;}

int loadDriver(const char *drivername, const char *driverpath);
int unloadDriver(const char *drivername);
int startDriver(char *drivername);
int stopDriver(char *drivername);

typedef struct
{
    DWORD driverstatus;
}DRIVER_LOADER, *PDRIVER_LOADER;

#endif /* _TYPES_H_ */