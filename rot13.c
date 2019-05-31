#include <pthread.h>
#include <unistd.h>


typedef struct _rot13_args {
    char *in, *out;
    size_t start, step, stop;
} rot13_args;

void *rot13_kernel(void *args) {
    rot13_args *data = (rot13_args *)args;
    rot13_args arg = *data;

    for (size_t i = arg.start; i < arg.stop; i += arg.step) {
        if (isalpha(arg.in[i])) {
            if ((tolower(arg.in[i]) - 'a') < 13) {
                arg.out[i] = arg.in[i] + 13;
            } else {
                arg.out[i] = arg.in[i] - 13;
            }
        } else {
            arg.out[i] = arg.in[i];
        }
    }

    if (arg.start == 0) {
        arg.out[arg.stop] = '\0';
    }

    pthread_exit(NULL);
}

char *rot13(char *s) {
    const size_t s_len = strlen(s);
    char *result = malloc(s_len * sizeof(char));

    const size_t NUM_THREADS = sysconf(_SC_NPROCESSORS_ONLN);

    rot13_args args[NUM_THREADS];
    pthread_t thr[NUM_THREADS];
    for (size_t i = 0; i < NUM_THREADS; i++) {
        args[i].in = s;
        args[i].out = result;
        args[i].start = i;
        args[i].step = NUM_THREADS;
        args[i].stop = s_len;

        pthread_create(&thr[i], NULL, rot13_kernel, &args[i]);
    }

    for (size_t i = 0; i < NUM_THREADS; i++) {
        pthread_join(thr[i], NULL);
    }

    return result;
}
