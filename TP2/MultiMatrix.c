#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREAD 4

int main(int argc, char const *argv[]) {

  omp_set_num_threads(NUM_THREAD);

  int nb = NUM_THREAD;

  if (argv[1] == NULL) {
    printf("Veuillez entrer une taille de matrice\n");
    exit(-1);
  }

  int tailleMatr = atoi(argv[1]);
  int matrix[tailleMatr][tailleMatr];
  int matric[tailleMatr][tailleMatr];
  int result[tailleMatr][tailleMatr];
  int i;
  int j;
  srand(time(NULL));

#pragma omp parallel for schedule(dynamic)
  for (i = 0; i < tailleMatr; i++) {
    for (j = 0; j < tailleMatr; j++) {
      matrix[i][j] = rand() % 50;
      matric[i][j] = rand() % 50;
    }
  }

#pragma omp parallel for schedule(dynamic)
  for (int i = 0; i < tailleMatr; i++) {
    for (int j = 0; j < tailleMatr; j++) {
      for (int k = 0; k < tailleMatr; k++) {
        result[i][j] += matrix[i][k] * matric[k][j];
      }
    }
  }

  return 0;
}
