
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
FUNCTION: ��λָ��
IN   ��
	CardSelect ---����ѡ��1 ~ 4
	uiRate ----������9600��38400��115200
	ucVoltage----��ѹ1��2��3
	inf_len
OUT :   
	ATR---��λ��Ϣ 
	rLen -�������ݳ���
RETURN: 0---�ɹ�������---ʧ��
********************************************************************************/
int IccSimReset(IN INT32U CardSelect,IN INT32U uiRate, IN INT8U ucVoltage,OUT INT8U *rLen,OUT INT8U *ATR,IN INT8U mode);


/*******************************************************************************
FUNCTION: APDUָ��
IN   ��
	Slot ---����ѡ��1 ~ 4
	buffer ----APDU����
	length---�������ݳ���

OUT :   
	rbuffer---APDU ������Ϣ 
	Revlen----�������ݳ���
	SW-----APDU ״̬��
RETURN: 0---�ɹ�������---ʧ��
********************************************************************************/
int Sim_Apdu(IN INT8U Slot, IN INT8U *buffer, IN INT16U length, OUT INT8U *rbuffer, OUT INT16U *Revlen, OUT INT16U *SW);


/*******************************************************************************
FUNCTION: APDUָ��
IN   ��
	Slot ---����ѡ��1 ~ 4
	ApduSend ----APDU����

OUT :   
	ApduRecv---APDU ������Ϣ 
RETURN: 0---�ɹ�������---ʧ��
********************************************************************************/

int SimSendAPDUT0(unsigned char Slot,ISO7816_ADPU_SEND *ApduSend,ISO7816_ADPU_RESPONSE *ApduRecv);

/*******************************************************************************
FUNCTION: ��SAM ģ��
IN   ��
OUT :   
RETURN: 0---�ɹ�������---ʧ��
********************************************************************************/
int OpenSimMoudle (void);

/*******************************************************************************
FUNCTION: �ر�SAM ģ��
IN   ��
OUT :   
RETURN: 0---�ɹ�������---ʧ��
********************************************************************************/
int CloseSimModule(void);


/*******************************************************************************
FUNCTION: ��ȡSAM ģ��汾
IN   ��
OUT :   
	DevVer--�豸�汾
	SofVer---����汾
RETURN: 0---�ɹ�������---ʧ��
********************************************************************************/
int GetSamVersion(char  *DevVer, char *SofVer);

#ifdef	__cplusplus
}
#endif

#endif //__LIBSAM_H

