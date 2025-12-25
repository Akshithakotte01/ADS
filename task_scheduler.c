#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Structure for Task
struct Task {
    int id;
    char name[30];
    int priority;
};

// Max Heap and size
struct Task heap[MAX];
int size = 0;

// Function to swap two tasks
void swap(struct Task *a, struct Task *b) {
    struct Task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a task into the heap
void insertTask(int id, char name[], int priority) {
    struct Task newTask;
    newTask.id = id;
    strcpy(newTask.name, name);
    newTask.priority = priority;

    heap[++size] = newTask;
    int i = size;

    // Heapify up
    while (i > 1 && heap[i / 2].priority < heap[i].priority) {
        swap(&heap[i / 2], &heap[i]);
        i = i / 2;
    }

    printf("Task inserted successfully!\n");
}

// Function to delete the highest priority task
void deleteTask() {
    if (size == 0) {
        printf("No tasks to execute!\n");
        return;
    }

    printf("\nExecuting Task: ID=%d, Name=%s, Priority=%d\n",
           heap[1].id, heap[1].name, heap[1].priority);

    heap[1] = heap[size--];

    // Heapify down
    int i = 1;
    while (2 * i <= size) {
        int max = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= size && heap[left].priority > heap[max].priority)
            max = left;

        if (right <= size && heap[right].priority > heap[max].priority)
            max = right;

        if (max != i) {
            swap(&heap[i], &heap[max]);
            i = max;
        } else {
            break;
        }
    }
}

// Function to display the current task queue
void displayTasks() {
    if (size == 0) {
        printf("No tasks in the queue!\n");
        return;
    }
int i;
    printf("\nCurrent Task Queue (Max Heap Order):\n");
    for (i = 1; i <= size; i++) {
        printf("Task ID: %d, Name: %s, Priority: %d\n",
               heap[i].id, heap[i].name, heap[i].priority);
    }
}

// Main Function
int main() {
    int choice, id, priority;
    char name[30];

    printf("=== Task Scheduling Simulator Using Max Heap ===\n");

    while (1) {
        printf("\n1. Insert Task");
        printf("\n2. Execute Highest Priority Task");
        printf("\n3. Display Task Queue");
        printf("\n4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Task ID: ");
                scanf("%d", &id);
                printf("Enter Task Name: ");
                scanf("%s", name);
                printf("Enter Task Priority: ");
                scanf("%d", &priority);
                insertTask(id, name, priority);
                break;

            case 2:
                deleteTask();
                break;

            case 3:
                displayTasks();
                break;

            case 4:
                printf("Exiting Simulator...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


