#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define LATTICE_SIZE 3 // Lattice size L
#define LATTICE_VOLUME 27 // L^3
#define MAX_ITERATIONS 1000000 // Max No. of Iterations
#define TOLERANCE 1e-6 // Stopping tolerance criterion
#define MU 0.1
#define LAMBDA 0.2
#define K (0.5/LAMBDA)

typedef struct {
  double real;
  double imag;
} Complex;

double magnitude(Complex z) {
  return sqrt(z.real * z.real + z.imag * z.imag);
}

int main() {
  Complex Ø[LATTICE_VOLUME];
  Complex Ø_new[LATTICE_VOLUME];
  double s = 1.0;

  for (int i = 0; i < LATTICE_VOLUME; i++) {
    Ø[i].real = (double)rand() / RAND_MAX;
    Ø[i].imag = (double)rand() / RAND_MAX;
  }

  int iterations = 0;
  double delta = 1e6;
  while (sqrt(delta / LATTICE_VOLUME) > TOLERANCE) {
    delta = 0.0;
    for (int x = 0; x < LATTICE_VOLUME; x++) {
      double old_real = Ø[x].real;
      double old_imag = Ø[x].imag;
      for (int mu = 0; mu < 3; mu++) {
    //    update_Ø(x, mu);
      }
      delta += (Ø[x].real - old_real) * (Ø[x].real - old_real) + (Ø[x].imag - old_imag) * (Ø[x].imag - old_imag);
    }
    iterations++;
  }
  
 printf("Solution:\n");
for (int x = 0; x < LATTICE_VOLUME; x++) {
  printf("x = %d, Ø.real = %f, Ø.imag = %f\n", x, Ø[x].real, Ø[x].imag);
}

  
  return 0;
}
