
#ifndef __COMMON_H__
#define __COMMON_H__

typedef unsigned char   u8,U8, U8_t,INT8U;
typedef unsigned short  U16_t, u16,U16,INT16U;
typedef unsigned int     U32_t, u32,U32,INT32U;
typedef signed char      s8, S8,INT8S;
typedef signed short     S16_t, s16,S16,INT16S;
typedef signed int        S32_t, s32,S32,INT32S;
typedef unsigned char   BYTE;

#define BOOL    int
#define TRUE    1
#define FALSE   0

#define IN
#define OUT


#define WAIT_DATA_TIMEOUT    			0
#define WAIT_DATA_READY        			1
#define WAIT_DATA_ERROR        			-1
#define WAIT_DATA_EXCEPT       			-2

#define MAX_WAIT_INTERVAL				5	//the maximum wait time in seconds.

#define SELECT_MAX_WAIT_INTERVAL		MAX_WAIT_INTERVAL	// second

int WaitFileReadable(int fd, int nmsTimeOut /* milliseconds*/);

int WaitFileWritable(int fd, int nmsTimeOut/* milliseconds*/);

void Sleep( long milliseconds );

unsigned long char2short(unsigned char *msb_mlb);

#define DEBUG

#ifdef DEBUG
#define DEBUG_INFO(...) 		printf(__VA_ARGS__)
#define DEBUG_EXINFO(...)	printf("[%s:%d] -- ", __FUNCTION__, __LINE__),printf(__VA_ARGS__)
#else
#define DEBUG_INFO(...)
#define DEBUG_EXINFO(...)
#endif

#ifndef ASSERT	// Protocol defined in assert.h
#define ASSERT	assert
#endif


#endif //__COMMON_H__

