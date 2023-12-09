#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SeqQueue;

// ��ʼ������
void InitQueue(SeqQueue* q) {
    q->front = q->rear = -1;
}

// �ж϶����Ƿ�Ϊ��
bool IsEmpty(SeqQueue* q) {
    if (q->front == -1) {
        printf("����Ϊ�ա�\n");
        return -1;
    }
}

// ���
bool EnQueue(SeqQueue* q, ElemType x) {
    // �������Ƿ�����
    if ((q->rear + 1) % MaxSize == q->front) {
        printf("��������\n");
        return false;
    }

    // �������Ϊ�գ���ʼ��front
    if (q->front == -1) {
        q->front = 0;
    }

    // ���
    q->rear = q->rear + 1;
    q->data[q->rear] = x;

    return true;
}

// ����
bool DeQueue(SeqQueue* q, ElemType* x) {
    // �������Ƿ�Ϊ��
    if (q->front == -1) {
        printf("����Ϊ�ա�\n");
        return false;
    }

    // ����
    *x = q->data[q->front];

    // ���front����rear����ʾ������ֻ��һ��Ԫ�أ����Ӻ����Ϊ��
    if (q->front == q->rear) {
        InitQueue(q);
    }
    else {
        q->front = q->front + 1;
    }

    return true;
}
//ȡ��ͷԪ��
int getFront(SeqQueue* q) {
    if (q->front == -1) {
        printf("����Ϊ��\n");
        return -1; // ����һ������ֵ��ʾ��������Ϊ��
    }

    printf("��ͷԪ�أ�%d ", q->data[q->front]);
}

// ��ȡ��βԪ��
int getRear(SeqQueue* q) {
    if (q->front == -1) {
        printf("����Ϊ�ա�\n");
        return -1; // ����һ������ֵ��ʾ��������Ϊ��
    }
    printf("��βԪ�أ�%d ", q->data[q->rear]);
    
}


// ��ӡ�����е�Ԫ��
void PrintQueue(SeqQueue* q) {
    if (q->front == -1) {
        printf("����Ϊ��.\n");
        return;
    }

    printf("�����е�Ԫ��Ϊ�� ");
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
    printf("����Ԫ��Ϊ: %d\n", removedElement);

    PrintQueue(&myQueue);
    getFront(&myQueue);
    getRear(&myQueue);
    return 0;
}
