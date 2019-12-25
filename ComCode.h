/********************************************************
 * 公用属性定义
 *
 *******************************************************/

#ifndef COM_CODE_H
#define COM_CODE_H


/**
 * 通过注释或启用
 * #define ARRAY_QUEUE_TYPE
 * 来选择底层栈类型
 */
//#define ARRAY_QUEUE_TYPE

#ifdef ARRAY_QUEUE_TYPE
#define ARRAY_QUEUE
#else
#define LINKED_QUEUE
#endif

/**
 * 通过注释或启用
 * #define CHAR_TYPE
 * 来选择底层数据类型
 */
#define CHAR_TYPE

#ifdef CHAR_TYPE
#define CHAR
#else
#define INT
#endif

#endif
