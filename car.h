/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: <your class>
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.h
* Author:			P. Bauer
* Due Date:		January 9, 2015
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

enum type{AIXAM, FIAT_MULTIPLA, JEEP};
enum color{RED, GREEN, BLUE, ORANGE, SILVER, BLACK};
typedef struct CarType* Car;

Car get_car(enum type type);
enum color get_color(Car car);
enum type get_type(Car car);
double get_fill_level(Car car);
int get_speed(Car car);
double get_acceleration_rate(Car car);
void set_acceleration_rate(Car car, double rate);
void init();
void accelerate(Car car);
#endif
