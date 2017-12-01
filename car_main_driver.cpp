#include<stdio.h>
#include "car.h"
#include <stdlib.h>

struct  CarType {
  enum type type;
  enum color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool is_rented;
};

void print_cars();
void race();

static struct CarType a = {AIXAM, RED, 16, 0.0, 0, false};
static struct CarType f1 = {FIAT_MULTIPLA, GREEN, 65, 0.0, 0, false};
static struct CarType f2 = {FIAT_MULTIPLA, BLUE, 65, 0.0, 0, false};
static struct CarType f3 = {FIAT_MULTIPLA, ORANGE, 65, 0.0, 0, false};
static struct CarType j1 = {JEEP, SILVER, 80, 0.0, 0, false};
static struct CarType j2 = {JEEP, BLACK, 80, 0.0, 0, false};

int main(int argc, char const *argv[]) {
  printf("Hello world!\n" );
  print_cars();
  race();
  return 0;
}
void race(){

}
void print_cars(){
  printf("Car: a\nCar: f1\nCar: f2\nCar: f3\nCar: j1\nCar: j2\n");
}
