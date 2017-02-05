
#ifndef __LIBSAM_H
#define __LIBSAM_H

#include "common.h"

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct
{
	unsigned char CLA;
	unsigned char INS;
	unsigned char P1;
	unsigned char P2;

	unsigned char LC;
	unsigned char DATA[240];

	unsigned char LE;

}ISO7816_ADPU_SEND;

typedef struct
{
	unsigned char LE;
	unsigned char DATA[240];

	unsigned char SW1;
	unsigned char SW2;
	
}ISO7816_ADPU_RESPONSE;


#define  RESET_VOLTAGE_18V		1
#define  RESET_VOLTAGE_33V		2
#define  RESET_VOLTAGE_50V		3

/*******************************************************************************
FUNCTION: 复位指令
IN   ：
	CardSelect ---卡槽选择1 ~ 4
	uiRate ----波特率9600、38400、115200
	ucVoltage----电压1、2、3
	inf_len
OUT :   
	ATR---复位信息 
	rLen -返回数据长度
RETURN: 0---成功；其他---失败
********************************************************************************/
int IccSimReset(IN INT32U CardSelect,IN INT32U uiRate, IN INT8U ucVoltage,OUT INT8U *rLen,OUT INT8U *ATR,IN INT8U mode);


/*******************************************************************************
FUNCTION: APDU指令
IN   ：
	Slot ---卡槽选择1 ~ 4
	buffer ----APDU命令
	length---发送数据长度

OUT :   
	rbuffer---APDU 返回信息 
	Revlen----接收数据长度
	SW-----APDU 状态码
RETURN: 0---成功；其他---失败
********************************************************************************/
int Sim_Apdu(IN INT8U Slot, IN INT8U *buffer, IN INT16U length, OUT INT8U *rbuffer, OUT INT16U *Revlen, OUT INT16U *SW);


/*******************************************************************************
FUNCTION: APDU指令
IN   ：
	Slot ---卡槽选择1 ~ 4
	ApduSend ----APDU命令

OUT :   
	ApduRecv---APDU 返回信息 
RETURN: 0---成功；其他---失败
********************************************************************************/

int SimSendAPDUT0(unsigned char Slot,ISO7816_ADPU_SEND *ApduSend,ISO7816_ADPU_RESPONSE *ApduRecv);

/*******************************************************************************
FUNCTION: 打开SAM 模块
IN   ：
OUT :   
RETURN: 0---成功；其他---失败
********************************************************************************/
int OpenSimMoudle (void);

/*******************************************************************************
FUNCTION: 关闭SAM 模块
IN   ：
OUT :   
RETURN: 0---成功；其他---失败
********************************************************************************/
int CloseSimModule(void);


/*******************************************************************************
FUNCTION: 获取SAM 模块版本
IN   ：
OUT :   
	DevVer--设备版本
	SofVer---软件版本
RETURN: 0---成功；其他---失败
********************************************************************************/
int GetSamVersion(char  *DevVer, char *SofVer);

#ifdef	__cplusplus
}
#endif

#endif //__LIBSAM_H

