#include <windows.h>
#include <stdio.h>
#include <../include/types.h>
#include <../include/ringz_ss.h> //start stop 
#include <../include/utils.h>
 
typedef struct
{
    DWORD driverstatus;
}DRIVER_LOADER, *PDRIVER_LOADER;

int checkPath(const char *driverpath)
{
    FILE *fExists = fopen(driverpath, "r");
    if(!fExists)
        return 0;
 
    fclose(fExists);
    return 1;
}

int startDriver(char *drivername)
{
    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    SC_HANDLE hService; = OpenService(hSCManager, drivername, SERVICE_ALL_ACCESS);
    int ret = 1;

    if(!hSCManager)
        Rec(ret, -1, c);
 
    if(!hService)
        Rec(ret, -2, c);
 
    if(!StartService(hService, 0, NULL))
        Rec(ret, -3, c);
 
c:
    if(hService) CloseServiceHandle(hService);
    if(hSCManager) CloseServiceHandle(hSCManager);
    return ret;
}
 
int stopDriver(char *drivername)
{
    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    SC_HANDLE hService = OpenService(hSCManager, drivername, SERVICE_ALL_ACCESS);
    SERVICE_STATUS ss;
    int ret = 1;

    if(!hSCManager)
        Rec(ret, -1, c);
 
    if(!hService)
        Rec(ret, -2, c);
 
    if(!ControlService(hService, SERVICE_CONTROL_STOP, &ss))
        Rec(ret, -3, c);
c:
    if(hService) CloseServiceHandle(hService);
    if(hSCManager) CloseServiceHandle(hSCManager);
    return ret;
}