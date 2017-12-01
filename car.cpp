#include <stdio.h>
#include "car.h"

#define AIXAM_MAX_ACCELERATION 1.0
#define FIAT_MULTIPLA_MAX_ACCELERATION 2.26
#define JEEP_MAX_ACCELERATION 3.14

#define AIXAM_MAX_SPEED 45
#define FIAT_MULTIPLA_MAX_SPEED 170
#define JEEP_MAX_SPEED 196

int round(double speed);

struct  CarType {
  enum type type;
  enum color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool is_rented;
};

static struct CarType a  = {AIXAM, RED, 16, 0.0, 0, false};
static struct CarType b1 = {FIAT_MULTIPLA, GREEN, 65, 0.0, 0, false};
static struct CarType b2 = {FIAT_MULTIPLA, BLUE, 65, 0.0, 0, false};
static struct CarType b3 = {FIAT_MULTIPLA, ORANGE, 65, 0.0, 0, false};
static struct CarType c1 = {JEEP, SILVER, 80, 0.0, 0, false};
static struct CarType c2 = {JEEP, BLACK, 80, 0.0, 0, false};

Car get_car(enum type type){
  Car car;
  if (type == AIXAM) {
    if (!a.is_rented) {
      car = &a;
      a.is_rented = true;
    }
    else car = 0;
  }
  else if (type == FIAT_MULTIPLA) {
    if (!b1.is_rented) {
      car = &b1;
      b1.is_rented = true;
    }
    else if (!b2.is_rented) {
      car = &b2;
      b2.is_rented = true;
    }
    else if (!b3.is_rented) {
      car = &b3;
      b3.is_rented = true;
    }
    else car = 0;
  }
  else {
    if (!c1.is_rented) {
      car = &c1;
      c1.is_rented = true;
    }
    else if (!c2.is_rented) {
      car = &c2;
      c2.is_rented = true;
    }
    else car = 0;
  }
  return car;
}

enum color get_color(Car car){
  return car->color;
}

enum type get_type(Car car){
  return car->type;
}

double get_fill_level(Car car){
  return car->fill_level;
}

int get_speed(Car car){
  return round(car->speed);
}

double get_acceleration_rate(Car car){
  return car->acceleration_rate;
}

void set_acceleration_rate(Car car, double rate){
  if (rate < -8) {
    car->acceleration_rate = -8;
    return;
  }
  if (car->type == AIXAM) {
    if (rate > AIXAM_MAX_ACCELERATION) car->acceleration_rate = AIXAM_MAX_ACCELERATION;
    else car->acceleration_rate = rate;
    return;
  }
  if (car->type == FIAT_MULTIPLA){
    if (rate > FIAT_MULTIPLA_MAX_ACCELERATION) car->acceleration_rate = FIAT_MULTIPLA_MAX_ACCELERATION;
    else car->acceleration_rate = rate;
    return;
  }
  if (car->type == JEEP) {
    if(rate > JEEP_MAX_ACCELERATION) car->acceleration_rate = JEEP_MAX_ACCELERATION;
    else car->acceleration_rate = rate;
    return;
  }
}

void init(){
  a.fill_level = 16;
  a.acceleration_rate = 0.0;
  a.speed = 0;
  a.is_rented = false;

  b1.fill_level = 65;
  b1.acceleration_rate = 0.0;
  b1.speed = 0;
  b1.is_rented = false;

  b2.fill_level = 65;
  b2.acceleration_rate = 0.0;
  b2.speed = 0;
  b2.is_rented = false;

  b3.fill_level = 65;
  b3.acceleration_rate = 0.0;
  b3.speed = 0;
  b3.is_rented = false;

  c1.fill_level = 80;
  c1.acceleration_rate = 0.0;
  c1.speed = 0;
  c1.is_rented = false;

  c2.fill_level = 80;
  c2.acceleration_rate = 0.0;
  c2.speed = 0;
  c2.is_rented = false;

}

void accelerate(Car car){
  if (car->type == AIXAM) {
    if (car->speed + 3.6 * car->acceleration_rate <= AIXAM_MAX_SPEED) {
      car->speed += 3.6*car->acceleration_rate;
    }
    else car->speed = AIXAM_MAX_SPEED;
    return;
  }

  if (car->type == FIAT_MULTIPLA) {
    if (car->speed + 3.6 * car->acceleration_rate <= FIAT_MULTIPLA_MAX_SPEED) {
      car->speed += 3.6*car->acceleration_rate;
    }
    else car->speed = FIAT_MULTIPLA_MAX_SPEED;
    return;
  }
  if (car->type == JEEP) {
    if (car->speed + 3.6 * car->acceleration_rate <= JEEP_MAX_SPEED){
      car->speed += 3.6*car->acceleration_rate;
    }
    else car->speed = JEEP_MAX_SPEED;
    return;
  }
}

int round(double speed){
  int final_speed = (speed + 0.5);
  return final_speed;
}
