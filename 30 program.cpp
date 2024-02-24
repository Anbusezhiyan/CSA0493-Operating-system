#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *thread_func(void *arg) {
    printf("Inside the thread function\n");
    pthread_exit(NULL);
}
int main() {
    pthread_t thread;
    pthread_attr_t attr;
    int ret;
    pthread_attr_init(&attr);
    ret = pthread_create(&thread, &attr, thread_func, NULL);
    if (ret != 0) {
        perror("pthread_create");
        return 1;
    }
    ret = pthread_join(thread, NULL);
    if (ret != 0) {
        perror("pthread_join");
        return 1;
    }
    pthread_t self = pthread_self();
    if (pthread_equal(thread, self)) {
        printf("The threads are equal\n");
    } else {
        printf("The threads are not equal\n");
    }
    printf("Main thread exiting\n");
    return 0;
}
