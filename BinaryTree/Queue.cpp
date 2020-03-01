#include<iostream>
using namespace std;

class Queue{
    public:
    int front, rear, currentSize, capacity; // currentSize is the number of element in the queue
    int *array;
  

};

Queue *createQueue(int size){
     Queue *myQueue = new Queue();
     myQueue -> capacity = size;
     myQueue -> array = new int[myQueue -> capacity * sizeof(int)];
     myQueue -> front = -1;
     myQueue -> rear = -1;
     myQueue -> currentSize = 0;

    return myQueue;

}

bool isFull(Queue *q){

    return q -> capacity == q -> currentSize;
}


bool isEmpty(Queue *q){

    return q -> currentSize == 0;
}

void enqueueOperation(Queue *q, int item){
    if(isFull(q)){
        cout << "Queue is full" << endl;
        return;
    }
    if(q -> front == -1)
        q -> front++;

    q -> rear = q -> rear + 1;
    q ->array[q -> rear] = item;
    q -> currentSize++;

    cout << item << " is in queue" << endl;    

}
int main(){

    Queue *q = createQueue(5);
    enqueueOperation(q, 10);
    enqueueOperation(q, 20);
    enqueueOperation(q, 30);
    enqueueOperation(q, 40);
    enqueueOperation(q, 50);
    enqueueOperation(q, 60);



    

}