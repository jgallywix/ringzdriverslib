#include <stdio.h>
#include <utils.h>

int checkPath(const char *driverpath)
{
    FILE *fExists = fopen(driverpath, "r");
    if(!fExists)
        return 0;
 
    fclose(fExists);
    return 1;
}