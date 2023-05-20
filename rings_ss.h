#ifndef _RINGS_SS_H_
#define _RINGS_SS_H_

int startDriver(char *drivername);
/* @brief
 *  start selected driver
 *
 * @param drivername
 *  name of the driver you wanna start
 *
 * @return
 *  1 if everything is ok
 * */
int stopDriver(char *drivername);
/* @brief
 *  stop a driver (must be loaded and started ofc)
 *
 * @param buff
 *  name of the driver you wanna stop
 *
 * @return
 *  1 if everything is okey
 * */

#endif /* _RINGS_SS_H_ */