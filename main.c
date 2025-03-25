#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int x, y;
    int distance;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;

struct Queue
{
    node *front, *rear;
};
typedef struct Queue queue;

node *new (int x, int y, int distance, node *prev)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->x = x;
    temp->y = y;
    temp->distance = distance;
    temp->next = NULL;
    temp->prev = prev;
    return temp;
}

queue *create()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int q_empty(queue **q)
{
    if ((*q)->front == NULL)
        return 1;
    else
        return 0;
}

void enqueue(queue **q, int x, int y, int distance, node *prev)
{
    node *temp = new (x, y, distance, prev);
    if ((*q)->rear == NULL)
    {
        (*q)->front = temp;
        (*q)->rear = temp;
        return;
    }
    (*q)->rear->next = temp;
    (*q)->rear = temp;
}

void dequeue(queue **q)
{
    if (q_empty(q))
        return;
    node *temp;
    (*q)->front = (*q)->front->next;

    if ((*q)->front == NULL)
        (*q)->rear = NULL;
}

int in_board(int x, int y, int n)
{
    if ((x >= 1 && x <= n) && (y >= 1 && y <= n))
        return 1;
    return 0;
}

node *knight_travel(int start[], int end[], int n)
{
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    queue *q = create();
    enqueue(&q, start[0], start[1], 0, NULL);

    node *temp;
    int x, y;
    int visited[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            visited[i][j] = 0;

    visited[start[0]][start[1]] = 1;

    while (!q_empty(&q))
    {
        temp = q->front;
        dequeue(&q);
        if ((temp->x == end[0]) && (temp->y == end[1]))
            return temp;

        for (int i = 0; i < 8; i++)
        {
            x = temp->x + dx[i];
            y = temp->y + dy[i];
            if (in_board(x, y, n) && !visited[x][y])
            {
                visited[x][y] = 1;
                enqueue(&q, x, y, temp->distance + 1, temp);
            }
        }
    }
}

void reverse_path(node **temp)
{
    node *prev = NULL;
    node *curr = *temp;
    node *next = NULL;
    while (curr != NULL)
    {
        next = curr->prev;
        curr->prev = prev;
        prev = curr;
        curr = next;
    }
    *temp = prev;
}

void delay(int seconds)
{
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

void main()
{
    int start[2], end[2];
    int n;
    int distance;
    printf("Enter the size of the board : ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Illegal board size");
        return;
    }
    printf("Enter the start_x position : ");
    scanf("%d", &start[0]);
    printf("Enter the start_y position : ");
    scanf("%d", &start[1]);
    printf("Enter the end_x position : ");
    scanf("%d", &end[0]);
    printf("Enter the end_y position : ");
    scanf("%d", &end[1]);
    if (start[0] <= 0 || start[1] <= 0 || end[0] <= 0 || end[1] <= 0 || start[0] > n || start[1] > n || end[0] > n || end[1] > n)
    {
        printf("\nIllegal coordinates\n");
        return;
    }

    char arr[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = ' ';

    node *temp = knight_travel(start, end, n);
    distance = temp->distance;

    reverse_path(&temp);
    node *t = temp;

    while (temp != NULL)
    {
        system("cls");

        arr[temp->x - 1][temp->y - 1] = 'X';

        printf("\n   ");
        for (int i = 1; i <= n; i++)
            printf("   %d  ", i);
        printf("\n   ");
        for (int i = 0; i < n; i++)
            printf("------");
        printf("-\n");

        for (int i = 0; i < n; i++)
        {
            printf("%d  ", i + 1);
            for (int j = 0; j < n; j++)
                printf("|  %c  ", arr[i][j]);
            printf("|\n   ");
            for (int j = 0; j < n; j++)
                printf("------");
            printf("-\n");
        }
        temp = temp->prev;
        delay(1);
    }

    printf("\nShortest distance from (%d,%d) to (%d,%d) : %d\n", start[0], start[1], end[0], end[1], distance);
    printf("\nShortest Path : ");
    while (t != NULL)
    {
        if (t->prev == NULL)
            printf("(%d,%d)", t->x, t->y);
        else
            printf("(%d,%d) -> ", t->x, t->y);
        t = t->prev;
    }
    printf("\n\n");
}
