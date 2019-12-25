/***************************
 * 循环顺序队列的头文件
 * 底层使用数组实现
 ***************************/

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H


#include <stdlib.h>
#include "stdio.h"
#include "ComCode.h"

//数据类型定义

#ifdef INT
typedef int elementType;
#define END_INPUT -9999
#endif


/**
 * 选择底层队列结构
 */
#ifdef ARRAY_QUEUE

#ifdef CHAR
typedef char elementType;
#define END_INPUT '$'
#endif


//队列最大容量为MAX_LEN - 1
#define MAX_LEN 30
//数据结构定义
typedef struct {
    elementType data[MAX_LEN];
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
int init(ArrayQueue *queue);

/**
 * 通过数组来初始化顺序栈
 * @param data 源数据
 * @param n 数组长度
 * @param *queue
 * @return SUCCESS 初始化成功
 *         FULL_QUEUE 队满
 *         NULL_POINT
 */
int initByArray(elementType data[], int n, ArrayQueue *queue);

/**
 * 通过键盘交互创建队列,以END_INPUT结束输入,若队已满,会强制结束输入
 * @param queue
 * @return NULL_POINT 空指针异常
 *         FULL_QUEUE 队满
 */
int initByInput(ArrayQueue *queue);

/**
 * 入队
 * @param elem
 * @param *queue
 * @return SUCCESS
 *         FULL_QUEUE 队满
 *         NULL_POINT
 */
int into(elementType elem, ArrayQueue *queue);

/**
 * 出队
 * @param *elem 用于接收出栈元素
 * @param *queue
 * @return SUCCESS
 *         NULL_POINT
 */
int out(elementType *elem, ArrayQueue *queue);

/**
 * 取队头元素
 * @param elem
 * @param queue
 * @return SUCCESS
 *         NULL_POINT
 */
int getFrontElem(elementType *elem, ArrayQueue *queue);

/**
 * 获取队列长队
 * @param queue
 * @return  SUCCESS
 *          NULL_POINT
 */
int size(ArrayQueue *queue);

/**
 * 队列是否为空
 * @param queue
 * @return 返回1为空,其他为非空
 *         NULL_POINT
 */
int isEmpty(ArrayQueue *queue);

/**
 * 队列是否已满
 * @param queue
 * @return 返回1为已满,其他为非满
 *         NULL_POINT
 */
int isFull(ArrayQueue *queue);

/**
 * 打印显示队列中所有元素
 *  ①初始化空循环队列；
 *  ②当键盘输入奇数时，此奇数入队；
 *  ③当键盘输入偶数时，队头出队；
 *  ④当键盘输入0时，算法退出；
 *  ⑤每当键盘输入后，输出当前队列中的所有元素。
 * @param queue
 * @return NULL_POINT
 * @param queue
 * @return SUCCESS
 *         NULL_POINT
 */
int showAll(ArrayQueue *queue);

/*************************
 * 操作结果码声明
 * SUCCESS 操作成功
 * NULL_POINT 空指针异常
 * FULL_QUEUE 队满
 */


int expByInput(ArrayQueue *queue);

enum CODE {
    SUCCESS = 1,
    NULL_POINT = -1,
    FULL_QUEUE = -2,
    EMPTY_QUEUE = -3,
};

#endif
#endif
