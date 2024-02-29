#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "mathf.h" //dichiaro le mie funzioni

#define NUM_POLYNOMIALS 4 // Numero di polinomi
#define NUM_XMIN 2 // Numero di valori di xmin
#define NUM_XMAX 2 // Numero di valori di xmax
#define NUM_INTERVALS 3 // Numero di valori di intervals

/*! \brief the main function

	here we define the polynomial, set the integration range and set the number of equally spaced intervals in which the range should be divided
	the points delimiting the intervals are defined and then the integration is finalized

*/
int main() {
	/* setting all the parameters */
	float fcoeff[NUM_POLYNOMIALS][5] = {
		{-10.0, 1.0, 0.0, 2.0, 7.0},
		{2.0, 0.0, -1.0, 3.0, 0.0},
		{0.0, 0.0, 1.0, -5.0, 0.0}
	}; // Gli array dei coefficienti dei polinomi
	float xmin[NUM_XMIN] = { 0.0, -2.0 }; //Valori Xmin
	float xmax[NUM_XMAX] = { 5.0, 3.0 }; //Valori di Xmax
	int intervals[NUM_INTERVALS] = { 500, 1000, 2000 }; //Intervalli

	float integ1, integ2;
	int i, j, k, l;

	for (i = 0; i < NUM_POLYNOMIALS; i++) 
	{
		for (j = 0; j < NUM_XMIN; j++) 
		{
			for (k = 0; k < NUM_XMAX; k++) 
			{
				for (l = 0; l < NUM_INTERVALS; l++) 
				{
					float in = xmin[j];
					float gap = (xmax[k] - xmin[j]) / (float)intervals[l];
					float* fvalues = NULL;

					fvalues = (float*)malloc(sizeof(float) * (intervals[l] + 1));
					if (fvalues == NULL)
					{
						printf("\nERROR: cannot allocate memory\n");
						exit(-1);
					}

					for (int m = 0; m <= intervals[l]; m++)
					{
						fvalues[m] = Polynomial(fcoeff[i], 4, in);
						in += gap;
					}

					integ1 = 0.;
					integ2 = 0.;

					//Rectangular rule
					Rectangular(fvalues, intervals[l] + 1, gap, &integ1, &integ2);
					printf("\nPolynomial %d, Xmin: %f, Xmax: %f, Intervals: %d - Rectangular rule - The integral is in the interval: [%f,%f]\n", i, xmin[j], xmax[k], intervals[l], integ1, integ2);

					//Trapezoidal rule
					integ1 = Trapezoidal(fvalues, intervals[l] + 1, gap);
					printf("Polynomial %d, Xmin: %f, Xmax: %f, Intervals: %d - Trapezoidal rule - The integral is: %f\n", i, xmin[j], xmax[k], intervals[l], integ1);

					if (fvalues != NULL)
						free(fvalues);
				}
			}
		}
	}

	return 0;
}
