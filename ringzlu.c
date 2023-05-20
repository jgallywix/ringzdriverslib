#include <windows.h>
#include <stdio.h>
#include <types.h>
#include <utils.c>

typedef struct
{
    DWORD driverstatus;
}DRIVER_LOADER, *PDRIVER_LOADER;

int loadDriver(const char *drivername, const char *driverpath)
{
    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    SC_HANDLE hService = CreateService(hSCManager, drivername, drivername, SERVICE_ALL_ACCESS, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL, driverpath, NULL,NULL, NULL,NULL, NULL);
    int ret = 1;
 
    if(!checkPath(driverpath))
        Rec(ret, -1, c);
 
    if(!hSCManager)
        Rec(ret, -2, c);
 
    if(!hService)
        Rec(ret, -3, c);
 
c:
    if(hService) CloseServiceHandle(hService);
    if(hSCManager) CloseServiceHandle(hSCManager);
    return ret;
}

int unloadDriver(const char *drivername)
{
    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    SC_HANDLE hService = OpenService(hSCManager, drivername, SERVICE_ALL_ACCESS);
    SERVICE_STATUS ss;
    int ret = 1;
 
    if(!hSCManager)
        Rec(ret, -1, c);
 
    if(!hService)
        Rec(ret, -2, c);
 
    // try to stop service first
    ControlService(hService, SERVICE_CONTROL_STOP, &ss);
 
    if(!DeleteService(hService))
        Rec(ret, -4, c);
c:
    if(hService) CloseServiceHandle(hService);
    if(hSCManager) CloseServiceHandle(hSCManager);
    return ret;
}