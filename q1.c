#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

int n,m;
int *t, *w;
time_t *p;
pthread_t *student;
sem_t semaphore;
time_t global=0;
int left=0;

void* routine(void* arg)
{
    int index=*(int *)arg;
    int flag=0;
    time_t start;
    start=time(NULL);
    sleep(t[index]);
    printf("%ld: Student %d arrives\n",time(NULL)-start,index+1);
    time_t gstart=time(NULL);
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec+=p[index];
    ts.tv_nsec+=100000000;
    if(sem_timedwait(&semaphore,&ts)==0) {
        global+=time(NULL)-gstart;
        printf("%ld: Student %d started washing\n",time(NULL)-start, index + 1);
        sleep(w[index]);
        sem_post(&semaphore);
        printf("%ld: Student %d left after washing\n", time(NULL)-start, index + 1);
    }
    else{
        printf("%ld: Studden %d left without washing\n",time(NULL)-start, index+1);
        global+=time(NULL)-gstart;
        left++;
    }
        free(arg);
}

int main() {
    scanf("%d %d", &n, &m);
    t = (int*)malloc(n*sizeof(int));
    w = (int*)malloc(n*sizeof(int));
    p = (time_t*)malloc(n*sizeof(time_t));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %ld", &t[i], &w[i], &p[i]);
    }
    student = (pthread_t*)malloc(n*sizeof(pthread_t));
    sem_init(&semaphore,0,m);
    for(int i=0;i<n;i++)
    {
        int* a=malloc(sizeof(int));
        *a=i;
//        pthread_mutex_init(&lock[i],NULL);
        pthread_create(&student[i],NULL,routine,a);
    }
    for(int i=0;i<n;i++)
    {
        pthread_join(student[i],NULL);
//        pthread_mutex_destroy(&lock[i]);
    }
    sem_destroy(&semaphore);
    printf("%d\n%ld",left,global);
    if(4*left<n)
        printf("\nNo");
    else
        printf("\nYes");
    return 0;
}
