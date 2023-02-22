#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "common_threads.h"

typedef struct {
    int a;
    int b;
} myarg_t;

typedef struct {
    int x;
    int y;
} myret_t;


/*Complete Structure Here*/

typedef struct {
    myarg_t val1;
    myarg_t val2;
} data_t;

/*Complete Structure Here*/

void *mythread(void *arg) {
    data_t *args = (data_t *) arg;

    myret_t *rvals = malloc(sizeof(myret_t));
    assert(rvals != NULL);
    rvals->x = abs(args->val1.a - args->val2.a);
    rvals->y = abs(args->val1.b - args->val2.b);
    return (void *) rvals;
}

int main(int argc, char *argv[]) {

    int arg1x = atoi(argv[1]);
    int arg1y = atoi(argv[2]);
    int arg2x = atoi(argv[3]);
    int arg2y = atoi(argv[4]);
    printf("arg1 x:%d y:%d\n", arg1x, arg1y);

    pthread_t p;
    myret_t *rvals;

    myarg_t args1 = { arg1x, arg1y };
    myarg_t args2 = { arg2x, arg2y };
    data_t data = { args1, args2 };

    /*Complete Create Here*/

    pthread_create(&p, NULL, mythread, &data);

    /*Complete Create Here*/
    Pthread_join(p, (void **) &rvals);

    printf("returned %d %d\n", rvals->x, rvals->y);
    free(rvals);
    return 0;
}


