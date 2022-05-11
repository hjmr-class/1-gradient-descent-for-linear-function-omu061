#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
​
double alpha = 0.001;
double a, b, c;
​
​
double func_y_hat(double x) {
  double y_hat = 5.0 * pow(x,2.0) + 4 * x - 3;
  return y_hat;
}
​
double func_y(double x) {
  double y = a * pow(x,2.0) + b * x + c;
  return y;
}
​
double func_error(double y, double y_hat) {
  double e = 0.5 * (y - y_hat) * (y - y_hat);
  return e;
}
​
double func_da(double x) {
  double y = func_y(x);
  double y_hat = func_y_hat(x);
  double da = (y - y_hat) * pow(x,2.0);
  return da;
}
​
double func_db(double x) {
  double y = func_y(x);
  double y_hat = func_y_hat(x);
  double db = (y - y_hat) * x;
  return db;
}
​
double func_dc(double x) {
  double y = func_y(x);
  double y_hat = func_y_hat(x);
  double dc = (y - y_hat) * 1;
  return dc;
}
double rand_one() {
  double r = random() / (double)RAND_MAX;
  return r;
}
​
void init_parameters() {
  srand((unsigned int)time(NULL));
  /* random numbers between 0-1 */
  a = rand_one();
  b = rand_one();
  c = rand_one();
  printf("a = %f, b = %f, c = %g\n", a, b, c);
}
​
int main(void) {
  int i = 0, j = 0;
  init_parameters();
​
  for (i = 0; i < 500; i++) {
    double e_sum = 0.0;
    for (j = 0; j < 100; j++) {
      double x = rand_one() * 10 - 5;
      a -= alpha * func_da(x);
      b -= alpha * func_db(x);
      c -= alpha * func_dc(x);
      e_sum += func_error(func_y(x), func_y_hat(x));
    }
    double e_ave = e_sum / 100;
    printf("%d, %f\n", i, e_ave);
  }
​
  printf("a = %f, b = %f, c = %g\n", a, b, c);
​
}