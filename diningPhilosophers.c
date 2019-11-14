/*
DINING PHILOSOPHERS

Group members:
Alliance Mbonigaba
Regis Ishimwe

*/

#include<stdio.h>
#include<pthread.h>

pthread_t philosopher[5]; //creating a data type for philosophers thread

pthread_mutex_t chopstick[5]; //chopsticks that will be locked


void *process(int n){
    printf("\n philosopher %d is thinking !!",n);

    // defining the chopsticks that are to be used.
    int chopstick_left = n-1;
    int chopstick_right = (n + 1)%5;

    pthread_mutex_lock(&chopstick[chopstick_left]);
    pthread_mutex_lock(&chopstick[chopstick_right]);


    printf("\n philosopher %d is eating using chopstick[%d] and chopstick[%d]!!",n,chopstick_left,chopstick_right);
    sleep(2);

    pthread_mutex_unlock(&chopstick[chopstick_left]);
    pthread_mutex_unlock(&chopstick[chopstick_right]);
    printf("\n philosopher %d finished eating !!",n);

}

int main(){

    int i;

    for(i=1;i<=5;i++){
        pthread_mutex_init(&chopstick[i],NULL);


    }

    for(i=1;i<=5;i++){

        pthread_create(&philosopher[i],NULL,(void *)process,(int *)i );	// dinning process

    }

    for(i=1;i<=5;i++){
        pthread_join(philosopher[i],NULL);
    }

    return 0;

}