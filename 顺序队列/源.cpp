#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SeqQueue;

// 初始化队列
void InitQueue(SeqQueue* q) {
    q->front = q->rear = -1;
}

// 判断队列是否为空
bool IsEmpty(SeqQueue* q) {
    if (q->front == -1) {
        printf("队列为空。\n");
        return -1;
    }
}

// 入队
bool EnQueue(SeqQueue* q, ElemType x) {
    // 检查队列是否已满
    if ((q->rear + 1) % MaxSize == q->front) {
        printf("队列已满\n");
        return false;
    }

    // 如果队列为空，初始化front
    if (q->front == -1) {
        q->front = 0;
    }

    // 入队
    q->rear = q->rear + 1;
    q->data[q->rear] = x;

    return true;
}

// 出队
bool DeQueue(SeqQueue* q, ElemType* x) {
    // 检查队列是否为空
    if (q->front == -1) {
        printf("队列为空。\n");
        return false;
    }

    // 出队
    *x = q->data[q->front];

    // 如果front等于rear，表示队列中只有一个元素，出队后队列为空
    if (q->front == q->rear) {
        InitQueue(q);
    }
    else {
        q->front = q->front + 1;
    }

    return true;
}
//取队头元素
int getFront(SeqQueue* q) {
    if (q->front == -1) {
        printf("队列为空\n");
        return -1; // 返回一个特殊值表示错误或队列为空
    }

    printf("队头元素：%d ", q->data[q->front]);
}

// 获取队尾元素
int getRear(SeqQueue* q) {
    if (q->front == -1) {
        printf("队列为空。\n");
        return -1; // 返回一个特殊值表示错误或队列为空
    }
    printf("队尾元素：%d ", q->data[q->rear]);
    
}


// 打印队列中的元素
void PrintQueue(SeqQueue* q) {
    if (q->front == -1) {
        printf("队列为空.\n");
        return;
    }

    printf("队列中的元素为： ");
    int i = q->front;
    do {
        printf("%d ", q->data[i]);
        i = i + 1;
    } while (i != (q->rear + 1) % MaxSize);
    printf("\n");
}

int main() {
    SeqQueue myQueue;
    InitQueue(&myQueue);
    IsEmpty(&myQueue);
    for (int i =0; i < 5; i++) {
        EnQueue(&myQueue, i );
    }

   
    PrintQueue(&myQueue);

    int removedElement;
    DeQueue(&myQueue, &removedElement);
    printf("出队元素为: %d\n", removedElement);

    PrintQueue(&myQueue);
    getFront(&myQueue);
    getRear(&myQueue);
    return 0;
}
