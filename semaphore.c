/*
#include <stdio.h>
int mutex = 1;
int full = 0;
int empty = 5,x=0;
void producer(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces " "item %d",x);
    ++mutex;
}
void consumer(){
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes ""Item %d",x);
    x--;
    ++mutex;
}
void main(){
    int optn,i;
    printf("\n1.Producer\n2.Consumer\n3.EXIT");
    do{
        printf("\nEnter your choice");
        scanf("%d",&optn);
        switch(optn){
            case 1: 
                if((mutex==1)&&(empty!=0)){
                    producer();
                }else{
                    printf("Buffer is full");
                }
                break;
            case 2:
                if((mutex==1)&&(full!=0)){
                    consumer();
                }else{
                    printf("Buffer is empty");
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid Entry");
        }
    }while(optn!=3);
}
*/
#include <stdio.h>

#define BUFFER_SIZE 5

int mutex = 1;
int full = 0,x=0;
int empty = BUFFER_SIZE;
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    buffer[in] = ++x; // Produce item (in this case, increment x)
    in = (in + 1) % BUFFER_SIZE;
    printf("\nProducer produces item %d", buffer[in - 1]);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes Item %d", buffer[out]);
    buffer[out] = 0; // Reset consumed item
    out = (out + 1) % BUFFER_SIZE;
    --x;
    ++mutex;
}

int main() {
    int optn;
    printf("\n1.Producer\n2.Consumer\n3.EXIT\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &optn);
        switch (optn) {
            case 1: 
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full\n");
                }
                break;
            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty\n");
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid Entry\n");
        }
    } while (optn != 3);

    return 0;
}
