#include <stdio.h>

#define MAX 1000

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

// Enqueue operation
void enqueue(int val) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    size++;
}

// Dequeue operation
int dequeue() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = queue[front];
    front = (front + 1) % MAX;
    size--;
    return val;
}

// Peek operation
int peek() {
    if (size == 0)
        return -1;
    return queue[front];
}

// Function to find the winner
int findTheWinner(int n, int k) {
    // Initialize queue with players 1 to n
    for (int i = 1; i <= n; i++) {
        enqueue(i);
    }

    // Eliminate every k-th person
    while (size > 1) {
        // Move k-1 players to the back of the queue
        for (int i = 0; i < k - 1; i++) {
            int temp = dequeue();
            enqueue(temp);
        }
        // Eliminate the k-th person
        dequeue();
    }

    return peek();  // The last remaining player
}

int main() {
    int n, k;
    printf("Enter number of players (n): ");
    scanf("%d", &n);
    printf("Enter step count (k): ");
    scanf("%d", &k);

    int winner = findTheWinner(n, k);
    printf("The winner is: %d\n", winner);

    return 0;
}
