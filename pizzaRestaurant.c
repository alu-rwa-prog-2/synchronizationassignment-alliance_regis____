/*
DINING PHILOSOPHERS

Group members:
Alliance Mbonigaba
Regis Ishimwe
Christian Rebero Twahirwa

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()

int NumberOfPizza=0;
pthread_mutex_t lock;

void *producePizza(void *vargp)
{
    pthread_mutex_lock(&lock);



    if(NumberOfPizza<=10)
    {


            NumberOfPizza= NumberOfPizza+1;
            printf("one pizza is produced now we have a total of:  %d  pizza\n",NumberOfPizza);
            sleep(2);
            if(NumberOfPizza == 10){
                printf("The tray is full with:  %d  pizza\n",NumberOfPizza);
                sleep(2);

            }


    }
    pthread_mutex_unlock(&lock);
    return NULL;
}


   void *myConsumingThread(void *vargp)
{
    pthread_mutex_lock(&lock);

    if(NumberOfPizza>0)
    {
            NumberOfPizza= NumberOfPizza-1;
            printf("one pizza is consumed, now there is a total of:  %d  pizza\n",NumberOfPizza);
            sleep(2);

    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t supplyThread_id,  consumeThrea_id;

    while(1)
    {

        pthread_create(&supplyThread_id, NULL, producePizza,NULL);


        pthread_create(&consumeThrea_id,NULL,myConsumingThread,NULL);

    }


    pthread_join(supplyThread_id, NULL);
    pthread_join(consumeThrea_id, NULL);

    exit(0);
}
