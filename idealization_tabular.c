/********************************************************
    Idealization Cayley Table LaTeX Converter
    Author: Nickolas Spear
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int RING_MOD;
int MOD_MOD;

typdef struct {
  int r;
  int n;
} idele;

int module_scalar(int r, int n);
int module_add(int a, int b);
int ring_mult(int a, int b);
int ring_add(int a, int b);
idele idealization_mult(idele a, idele b);
idele idealization_add(idele a, idele b);
int iszero(idele value);
idele make_idele_from_mult(int r1, int n1, int r2, int n2);

idele ** idealization_cayley();
int free_cayley( idele ** cayley );

int main (int argc, char ** argv) {
  if (argc < 3) {
    printf("Please enter ring and module modulo numbers.");
    exit(0);
  }

  RING_MOD = (int)strtol(argv[1]);
  MOD_MOD = (int)strtol(argv[2]);
  printf("Ring will be modulo %d.\n Module will be modulo %d.\n", RING_MOD, MODULE_MOD);

  idele ** cayley = idealization_cayley();
  output
}

idele ** idealization_cayley() {

  idele retcalyey[RING_MOD * MOD_MOD][RING_MOD * MOD_MOD];
  for ( int r1 = 0; r1 < RING_MOD; r1++) {
    for ( int n1 = 0; n1 < MOD_MOD; n1++) {
      for ( int r2 = 0; r2 < RING_MOD; r2++) {
        for ( int n2 = 0; n2 < MOD_MOD; n2++) {
         retcayley[(r1*RING_MOD) + n1][(r2*RING_MOD) + n2] = make_idele_from_mult(r1, n1, r2, n2);
        }
      }
    }
  }
  free(cayley);
  return 1;
}

void cayley_to_file(idele ** cayley) {
/*
  \begin{table}[h!]
    \begin{center}
      \begin{tabular}{c|cccccc}
        %
        $\cdot$ & [1] & [2] & [3] & [4] & [5]\\
        \hline
        {}  [1] & [1] & [2] & [3] & [4] & [5] \\
        {} [2] & [2] & [4] & [0] & [2] & [4] \\
        {} [3] & [3] & [0] & [3] & [0] & [3] \\
        {} [4] & [4] & [2] & [0] & [4] & [2] \\
        {} [5] & [5] & [4] & [3] & [2] & [1] \\
      \end{tabular}
    \end{center}
  \end{table}
*/
}

int freecayley(idele ** cayley) {
  for ( int i = 0; i < RING_MOD * MOD_MOD; i++) {
    for ( int j = 0; j < RING_MOD * MOD_MOD; j++) {
      free(cayley[i][j]
    }
  }
  return 1;
}

/********* OPERATION DEFINITIONS *********/
int module_scalar(int r, int n) { return (r * n) % MOD_MOD; }
int module_add(int a, int b) { return (a + b) % MOD_MOD; }
int ring_mult(int a, int b) { return (a * b) % RING_MOD; }
int ring_add(int a, int b) { return (a + b) % RING_MOD; }
idele idealization_mult(idele a, idele b) { 
  idele retval;
  
  retval.r = ring_mult(a.r, b.r);
  retval.n = module_add(module_scalar(a.r, b.n),module_scalar(b.r,a.n));

  return retval;
}
idele idealization_add(idele a, idele b) { 
  idele retval;
  
  retval.r = ring_add(a.r, b.r);
  retval.n = module_add(a.n, b.n);

  return retval;
}
int iszero(idele value) {
  return (value.r % RING_MOD == 0) && (value.n & MOD_MOD == 0) ? 1 : 0; 
}
idele make_idele_from_mult(int r1, int n1, int r2, int n2) {
  idele retval;
  
  retval.r = ring_mult(r1, r2);
  retval.n = module_add(module_scalar(r1, n2),module_scalar(r2,n1));

  return retval;
}
