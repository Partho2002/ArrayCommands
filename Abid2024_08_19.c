#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int arr[16], s, n, c;

void show() {
    printf("\n{");
    for(int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b}");
}

void insertion() {
    if(n < s) {
        printf("Inserting index: ");
        int p;
        scanf("%d", &p);

        if(p <= n) {
            for(int i = n; i > p; i--) {
                arr[i] = arr[i-1];
            }
            n++;

            printf("New Value: ");
            scanf("%d", &arr[p]);
            printf("%d has been added in arr[%d].", arr[p], p);
        } else {
            printf("Out of box error!");
        }
    } else {
        printf("Full space!");
    }
}

void confirm(int p) {
    printf("Do you want to remove %d?\n", arr[p]);
    printf("1: Yes\n");
    printf("2: No\n");
    printf("3: Change\n");
    printf("Choose a command: ");
    scanf("%d", &c);
    switch(c) {
        case 1: {
            printf("%d", arr[p]);
            for(int i = p; i <= n; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            printf(" has been removed from arr[%d].", p);
            break;
        }

        case 2: {
            printf("Deletion cancel.");
            break;
        }

        case 3: {
            printf("New deleting index: ");
            scanf("%d", &p);
            confirm(p);
            break;
        }

        default: printf("Invalid Integer! Choose from 1-3.");
    }
}

void deletion() {
    if(n >= 0) {
        printf("Deleting index: ");
        int p;
        scanf("%d", &p);

        if(p <= n) {
            confirm(p);
        } else {
            printf("Out of box error!");
        }
    } else {
        printf("Empty space!");
    }
}

void swiping(int i1, int i2) {
    int tmp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = tmp;
}

bool permit(int i1, int i2) {
    switch(c) {
        case 1: {
            if(i1 > i2) return true;
            break;
        }

        case 2: {
            if(i1 < i2) return true;
            break;
        }
    }
    return false;
}

void searching() {}

void bubbleSort() {
    printf("Bubble Sort!");
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(permit(arr[j], arr[j+1])) swiping(j, j+1);
        }
    }
}

void selectionSort() {
    printf("Selection Sort!");
    int m;
    for(int i = 0; i < n-1; i++) {
        m = i;
        for(int j = i+1; j < n; j++) {
            if(permit(arr[m], arr[j])) m = j;
        }
        swiping(i, m);
    }
}

void insertionSort() {
    printf("Insertion Sort!");
    int temp, j;
    for(int i = 1; i < n; i++) {
        temp = arr[i];
        for(j = i-1; j >= 0 && permit(arr[j], temp); j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

void sortType() {
    int r = rand()%3;

    switch(r) {
        case 0: {
            bubbleSort();
            break;
        }

        case 1: {
            selectionSort();
            break;
        }

        case 2: {
            insertionSort();
            break;
        }
    }
}

void sorting() {
    printf("1: Ascending\n");
    printf("2: Descending\n");
    printf("Select an order: ");
    scanf("%d", &c);

    switch(c) {
        case 1: {
            printf("Ascending by ");
            sortType();
            break;
        }

        case 2: {
            printf("Descending by ");
            sortType();
            break;
        }

        default: printf("Invalid Integer!");
    }
}

void unsorting() {
    for(int i = 0; i < n; i++) {
        swiping(i, rand()%n);
    }
    printf("Array unsorted!");
}

void main() {
    s = sizeof(arr)/sizeof(arr[0]);
    srand(time(NULL));

    printf("Array Max Size: %d\n", s);
    printf("Array Size: ");
    scanf("%d", &n);

    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    c = -1;
    while (c != 0) {
        printf("\n\n");
        printf("0: Exit\n");
        printf("1: Show Array\n");
        printf("2: Insert Value\n");
        printf("3: Remove Value\n");
        printf("4: Swiping Value\n");
        printf("5: Searching Value\n");
        printf("6: Sorting\n");
        printf("7: Unsorting\n");
        printf("Choose a command: ");
        scanf("%d", &c);
        switch(c) {
            case 0: {
                printf("Programe Closed!");
                break;
            }

            case 1: {
                show();
                break;
            }

            case 2: {
                insertion();
                break;
            }

            case 3: {
                deletion();
                break;
            }

            case 4: {
                int i1, i2;
                printf("1st index: ");
                scanf("%d", &i1);
                printf("2nd index: ");
                scanf("%d", &i2);

                swiping(i1, i2);

                printf("%d & %d, has been swiped!", arr[i1], arr[i2]);
                break;
            }


            case 5: {
                searching();
                break;
            }

            case 6: {
                sorting();
                break;
            }

            case 7: {
                unsorting();
                break;
            }

            default: printf("Invalid Integer! Choose a command between 0-7.");
        }
    }
}
