#ifndef MATHF_H //queste due righe devono SEMPRE essere all'inizio
#define MATHF_F

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float Polynomial(float* coeff, int size, float in);
void Rectangular(float* values, int size, float stepsize, float* integ1, float* integ2);
float Trapezoidal(float* values, int size, float stepsize);

#endif