#include <stdio.h>

#define BufferSize 10   // Define the buffer size

int circularBuffer[BufferSize];   // Declare the circular buffer
int head = 0;                     // Points to the next position to write
int tail = 0;                     // Points to the next position to read
int isFull_flag = 0;              // Flag to check if the buffer is full

// Check if the buffer is full
int isBuffer_full() {
    return isFull_flag;
}

// Check if the buffer is empty
int isBuffer_Empty() {
    return (head == tail && !isFull_flag);
}

// Write to the circular buffer (Overwrite old data if buffer is full)
void API_writeToBuffer(int data_element) {
    circularBuffer[head] = data_element;
    printf("\nAPI_writeBuffer: %d", circularBuffer[head]);
    head = (head + 1) % BufferSize;  // Move the head pointer circularly

    // If the buffer is full, move the tail to prevent data loss
    if (isBuffer_full()) {
        tail = (tail + 1) % BufferSize;  // Advance the tail when overwriting
    }

    // If the head catches up with the tail, the buffer is now full
    if (head == tail) {
        isFull_flag = 1;
    }
}

// Read from the circular buffer
void API_ReadFromBuffer(int *data_element) {
    if (isBuffer_Empty()) {
        printf("\nBuffer is empty, cannot read data");
    } else {
        *data_element = circularBuffer[tail];
        printf("\nAPI_ReadBuffer: %d", circularBuffer[tail]);
        tail = (tail + 1) % BufferSize;  // Move the tail pointer circularly
        isFull_flag = 0;  // Buffer is no longer full after reading
    }
}

int main() {
    int data;

    // Write data to the buffer
    for (int i = 1; i <= 12; i++) {
        API_writeToBuffer(i);
    }

    // Read some data from the buffer
    for (int i = 0; i < 5; i++) {
        API_ReadFromBuffer(&data);
    }

    // Write more data to the buffer
    for (int i = 13; i <= 15; i++) {
        API_writeToBuffer(i);
    }

    // Read all data from the buffer
    while (!isBuffer_Empty()) {
        API_ReadFromBuffer(&data);
    }

    return 0;
}
