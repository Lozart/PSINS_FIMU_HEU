#pragma once

#define WM_SERIALMSG WM_USER+100		// SerialPort Msg
#define WM_DATAERRMSG WM_USER+101		// ���ݴ����쳣����

class SerialPort
{
public:
	CString ComNum;
	int bdr;
	int stopb;
	int checkb;
	DCB COMPara;
	CString ComNumG;
	int bdrG;
	int stopbG;
	int checkbG;
	DCB COMParaG;
	HANDLE hCOM, hCOMG;
	UCHAR pkgHead[2] = { 0xAA, 0x55 };		// FIMU֡ͷ
	CHAR  pkgHeadPOS[5] = { 'G','N','G','G','A' }; // GPGGA
	CHAR  pkgHeadVEL[8] = { 'B','E','S','T','V','E','L','A' }; // BESTVEL
	BOOL GPSPOSVEL[2] = { FALSE, FALSE };
	BOOL isOpen = FALSE;
	BOOL isIMUOpen = FALSE;
	BOOL isGPSOpen = FALSE;
	BOOL isResolving = FALSE;

	unsigned int pkgLen = 50;		//���ݰ���Ч���ȣ���ȥ֡ͷ��
	UCHAR rByte1;			// FIMUʮ������������
	CHAR  rByte2;			// GPS�ַ�������
	UCHAR buffer[2][64];		//���ݰ�˫������
	CHAR gpsbuffer0[512];		// GPS���ݻ�����(GPGGA)
	CHAR gpsbuffer1[512];		// GPS���ݻ�����(BESTVEL)
	char buftagR = 0;
	char buftagW = 0;
	BOOL ReadPkg = FALSE;
	
	HWND hwndOfComm;
	UINT msg_getpkg = 101;
	UINT msg_getpkgfail = 102;
	UINT msg_getGPGGA = 201;
	UINT msg_getBESTVEL = 301;

	int OpenCOM();
	BOOL CloseCOM();
	BOOL findHead();
	void readPkg();

	int OpenGPSCOM();
	BOOL CloseGPSCOM();
	BOOL findGPSHead();
	void readGPSPkg();
};

