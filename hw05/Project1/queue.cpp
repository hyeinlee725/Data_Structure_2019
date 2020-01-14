#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(QUEUE * q)
{
	q->front = q->rear = 0;
}

void print_queue(QUEUE * q)
{
	int i = 0;
	if (q->rear < q->front) {
		printf("(%d|%d|%d: ", q->front, q->rear, (q->rear + MAX_QUEUE_SIZE) - q->front % MAX_QUEUE_SIZE);
	}
	else {
		printf("(%d|%d|%d: ", q->front, q->rear, q->rear % MAX_QUEUE_SIZE - q->front % MAX_QUEUE_SIZE);
	}
	if (q->front < q->rear)
	{
		for (i = q->front + 1; i < q->rear; i++)
		{
			printf("%d,", q->data[i]);
		}
		printf("%d", q->data[q->rear]);
	}
	else if (q->front > q->rear)
	{
		for (i = q->front + 1; i < q->rear + MAX_QUEUE_SIZE; i++)
		{
			printf("%d,", q->data[i%MAX_QUEUE_SIZE]);
		}
		printf("%d", q->data[q->rear]);
	}
	printf(")\n");
}

int empty_queue(QUEUE * q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int full_queue(QUEUE * q)
{
	if (q->front == (q->rear + 1) % MAX_QUEUE_SIZE)
		return 1;
	else
		return 0;
}

int en_queue(QUEUE * q, int item)
{
	if (full_queue(q) == 1)
		return -1;
	else
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
		return q->rear;
	}
}

int de_queue(QUEUE * q)
{
	if (empty_queue(q) == 1)
		return -1;
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

int main()
{
	int item = 10, r;
	QUEUE q1;

	printf("===== test-queue =====\n");

	init_queue(&q1);
	print_queue(&q1);

	for (;;) {
		if (en_queue(&q1, item++) == ERROR)
			break;
		print_queue(&q1);
		if (en_queue(&q1, item++) == ERROR)
			break;
		print_queue(&q1);
		if (de_queue(&q1) == ERROR)
			break;
		print_queue(&q1);
	}

	r = full_queue(&q1);
	if (r != 1)
		printf("ERROR: full_queue\n");
	else
		printf("OK: full_queue\n");

	for (;;) {
		if (de_queue(&q1) == ERROR)
			break;
		print_queue(&q1);
		if (de_queue(&q1) == ERROR)
			break;
		print_queue(&q1);
		if (en_queue(&q1, item++) == ERROR)
			break;
		print_queue(&q1);
	}

	r = empty_queue(&q1);
	if (r != 1)
		printf("ERROR: empty_queue\n");
	else
		printf("OK: empty_queue\n");

	return EXIT_SUCCESS;
}
