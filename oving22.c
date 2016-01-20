#include <pthread.h>
#include <stdio.h>


int i=1;

pthread_mutex_t minMutex;

// Note the return type: void*
void* one(){

    for (int x=0;x<1000000;x+=1){
        pthread_mutex_lock(&minMutex);
	i+=1;
	pthread_mutex_unlock(&minMutex);    
    }
}

void* two(){

    for (int x=0;x<1000000;x+=1){
        pthread_mutex_lock(&minMutex);
	i-=1;
	pthread_mutex_unlock(&minMutex);     
    }
}

int main(){
    pthread_mutex_init(&minMutex,NULL);
    pthread_t ThreadOne;
    pthread_t ThreadTwo;

    pthread_create(&ThreadOne, NULL, one, NULL);
    pthread_create(&ThreadTwo, NULL, two, NULL);

    
    pthread_join(ThreadOne, NULL);
    pthread_join(ThreadTwo, NULL);
	pthread_mutex_destroy(&minMutex);
    printf("%d \n",i);
    return 0;
    
}
