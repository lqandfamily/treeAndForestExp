
#include "ArrayQueue.h"

#ifdef ARRAY_QUEUE



int init(ArrayQueue *queue) {
    if (queue == NULL) {
        return NULL_POINT;
    }
    printf("**************based is Array Queue*******************\n");
    queue->front = 0;
    queue->rear = 0;
    return SUCCESS;
}

int initByArray(elementType data[], int n, ArrayQueue *queue) {
    int i;
    if (queue == NULL || data == NULL) {
        return NULL_POINT;
    }
    if (n > MAX_LEN - 1) {
        return FULL_QUEUE;
    }
    init(queue);

    for (i = 0; i < n; i++) {
        into(data[i], queue);
    }
    return SUCCESS;
}

#ifdef CHAR
int initByInput(ArrayQueue *queue) {
    elementType elem;
    if (queue == NULL) {
        return NULL_POINT;
    }
    init(queue);

    printf("交互式创建队列,以%c结束:\n", END_INPUT);
    do {
        scanf("%c", &elem);
//        elem = getchar();
        if (elem == '\n') {
            continue;
        }
        if (elem == END_INPUT) {
            return SUCCESS;
        }
        into(elem, queue);
    } while (!isFull(queue));
    printf("栈已满,无法继续输入\n");
    return FULL_QUEUE;
}

#endif

#ifdef INT
int initByInput(ArrayQueue *queue) {
    elementType elem;
    if (queue == NULL) {
        return NULL_POINT;
    }
    init(queue);

    printf("交互式创建队列,以%d结束:\n", END_INPUT);
    do {
        scanf("%d", &elem);
//        elem = getchar();
        if (elem == '\n') {
            continue;
        }
        if (elem == END_INPUT) {
            return SUCCESS;
        }
        into(elem, queue);
    } while (!isFull(queue));
    printf("栈已满,无法继续输入\n");
    return FULL_QUEUE;
}

#endif

int into(elementType elem, ArrayQueue *queue) {
    if (queue == NULL) {
        return NULL_POINT;
    }

    if (isFull(queue)) {
        return FULL_QUEUE;
    }

    //入队
    queue->data[queue->rear] = elem;
    queue->rear = (queue->rear + 1) % MAX_LEN;
    return SUCCESS;
}

int out(elementType *elem, ArrayQueue *queue) {
    if (queue == NULL) {
        return NULL_POINT;
    }
    //队空
    if (isEmpty(queue)) {
        return EMPTY_QUEUE;
    }

    //出队
    *elem = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_LEN;
    return SUCCESS;
}

int getFrontElem(elementType *elem, ArrayQueue *queue) {
    if (queue == NULL) {
        return NULL_POINT;
    }
    *elem = queue->data[queue->front];
    return SUCCESS;
}

int size(ArrayQueue *queue) {
    int size = queue->rear - queue->front;
    return size >= 0 ? size : -size;
}

int isEmpty(ArrayQueue *queue) {
    return queue->front == queue->rear;
}

int isFull(ArrayQueue *queue) {
    //队满,入队时始终保持当前rear所指向单元不存储数据,用于区分队满,队空
    return (queue->rear + 1) % MAX_LEN == queue->front;
}


#ifdef CHAR
int showAll(ArrayQueue *queue) {
    elementType elem;
    int mFront;
    if (queue == NULL) {
        return NULL_POINT;
    }

    printf("队中元素:\n");
    //不能出队!!!!!!!
    mFront = queue->front;
    while (mFront != queue->rear) {
        printf("%c, ", queue->data[mFront]);
        mFront++;
    }

    printf("\n");
    return SUCCESS;
}
#endif

#ifdef INT
int showAll(ArrayQueue *queue) {
    elementType elem;
    int mFront;
    if (queue == NULL) {
        return NULL_POINT;
    }

    printf("队中元素:\n");
    //不能出队!!!!!!!
    mFront = queue->front;
    while (mFront != queue->rear) {
        printf("%d, ", queue->data[mFront]);
        mFront++;
    }

    printf("\n");
    return SUCCESS;
}
#endif

int expByInput(ArrayQueue *queue) {
    elementType elem;
    if (queue == NULL) {
        return NULL_POINT;
    }

    init(queue);

    printf("队列交互实验:\n");

    while ((elem = getchar()) != '0') {
        if (elem == '\n') continue;
        if (elem % 2 == 1) {
            into(elem - '0', queue);
        } else {
            if (isEmpty(queue)) {
                printf("空队列!");
                continue;
            }
            out(&elem, queue);
            printf("出队:%d\n", elem);
        }
        showAll(queue);
    }

    printf("算法结束\n");

    return SUCCESS;
}

#endif

