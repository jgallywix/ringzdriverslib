#ifndef _RINGSLU_H_
#define _RINGSLU_H_

int loadDriver(const char *drivername, const char *driverpath);
/* @brief
 *  load a driver 
 *
 * @param drivername
 *  the name of the driver (Ex: driver1.sys)
 * @param driverpath
 *  the path of the driver
 * @return
 *  buff without CRLF.
 * */
int unloadDriver(const char *drivername);

#endif /* _RINGSLU_H_ */