#include <stdio.h>
#include <omp.h>
#define NUM_THREAD 4

int main(int argc, char const *argv[]) {
  int idme = 0;
  int nb = NUM_THREAD;
  omp_set_num_threads(NUM_THREAD);

  #pragma omp parallel private(nb, idme)
  {
    nb = omp_get_num_threads();
    int me = omp_get_thread_num();

    printf("Hello World n°%d!\n",me);

    if (me == 0) {
      sleep(1);// Permet de voir la parallelisation du programme
      printf("En parallel !\n");
    }
  }
  return 0;
}
