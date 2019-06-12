#include <stdio.h>
#include <pthread.h>
#include <math.h>

void* primo(void* init){
    int i,j;
    int* k = (int*)init;

    for(i = *k; i < ((*k)+1000);i++){
        j = 2;
        int r = sqrt(i);
        while(j < r){
            if(i % j == 0)
            break;
            j++;
        }

        if (j == r)
        printf("%d\n",i);
    }
}

int main(){
    int i,k;
    pthread_t thread_id[100];

    for (i = 0; i < 100; ++i){
        k = i*1000;
        if(k == 0){
            k = 2;
        }   
        pthread_create(&thread_id[i], NULL, primo, &k);
    }
    pthread_exit(NULL);
    return 0;
}