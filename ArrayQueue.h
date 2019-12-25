/***************************
 * 循环顺序队列的头文件
 * 底层使用数组实现
 ***************************/

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include "createTree.h"

/*************************
 * 操作结果码声明
 * SUCCESS 操作成功
 * NULL_POINT 空指针异常
 * FULL_QUEUE 队满
 */
enum CODE {
    SUCCESS = 1,
    NULL_POINT = -1,
    FULL_QUEUE = -2,
    EMPTY_QUEUE = -3,
};

//数据类型定义
typedef csNode *dataType;

#define MAX_LEN 30
//数据结构定义
typedef struct {
    dataType data[MAX_LEN];
    int front;  //队头指针
    int rear;   //队尾指针
} ArrayQueue;

/*************************
 * 函数声明
 */
/**
 * 初始化顺序栈
 * @param *queue
 * @return SUCCESS 初始化成功
 *         NULL_POINT
 */
int init(ArrayQueue *queue) {
    if (queue == NULL) {
        return NULL_POINT;
    }
    printf("**************based is Array Queue*******************\n");
    queue->front = 0;
    queue->rear = 0;
    return SUCCESS;
}

/**
 * 队列是否为空
 * @param queue
 * @return 返回1为空,其他为非空
 *         NULL_POINT
 */
int isEmpty(ArrayQueue *queue) {
    return queue->front == queue->rear;
}

/**
 * 队列是否已满
 * @param queue
 * @return 返回1为已满,其他为非满
 *         NULL_POINT
 */
int isFull(ArrayQueue *queue) {
    //队满,入队时始终保持当前rear所指向单元不存储数据,用于区分队满,队空
    return (queue->rear + 1) % MAX_LEN == queue->front;
}

/**
 * 入队
 * @param elem
 * @param *queue
 * @return SUCCESS
 *         FULL_QUEUE 队满
 *         NULL_POINT
 */
int into(dataType elem, ArrayQueue *queue) {
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

/**
 * 出队
 * @param *elem 用于接收出栈元素
 * @param *queue
 * @return SUCCESS
 *         NULL_POINT
 */
int out(dataType *elem, ArrayQueue *queue) {
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

/**
 * 取队头元素
 * @param elem
 * @param queue
 * @return SUCCESS
 *         NULL_POINT
 */
int getFrontElem(dataType *elem, ArrayQueue *queue) {
    if (queue == NULL) {
        return NULL_POINT;
    }
    *elem = queue->data[queue->front];
    return SUCCESS;
}

/**
 * 获取队列长队
 * @param queue
 * @return  SUCCESS
 *          NULL_POINT
 */
int size(ArrayQueue *queue) {
    int size = queue->rear - queue->front;
    return size >= 0 ? size : -size;
}


#endif
