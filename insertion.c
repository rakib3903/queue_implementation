#include<stdio.h>
#define capacity 100

int queue[capacity];
int front = -1,rear = -1;

void inqueue(int item) {
    if((front == 0 && rear == capacity - 1) || (front == rear + 1 )) {
        printf("overflow!\n");
    } else if(front == -1) {
        rear = 0;
        front = 0;
        queue[rear] = item;
    } else if(rear == capacity - 1) {
        rear = 0;
        queue[rear] = item;
    } else {
        rear = rear + 1;
        queue[rear] = item;
    }
}

int dequeue() {
    int item = -1;
    if(front == -1 && rear == -1) {
        printf("underflow!");
    } else if(front == 0 && rear == 0) {
        rear = -1;
        front = -1;
        item = queue[rear+1];
    } else if(front == capacity - 1) {
        item = queue[front];
        front = 0;
    } else {
        item = queue[front];
        front = front + 1;
    }
    return item;
}

void showQueue(){

}

int main() {
inqueue(5);
inqueue(6);
inqueue(7);
int x = dequeue();
printf("%d\n",x);
return 0;
}
