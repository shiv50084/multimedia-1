/*********************************************************************************
[File information]
FileName = PublicDef.h
Description =  head file
Corp.= Tianjin Tiandy Tech
Author = george
Date= 2006-09-01
[History] 	
XH1=XM20060901,george
*********************************************************************************/
#ifndef _PUBLICDEF_H_
#define _PUBLICDEF_H_

#include <assert.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#ifdef MEMWATCH
#include "memwatch.h"
#endif

#define UILOCALSET -1
#define SYSTEMSTAT -2 

//#define OverLapBurn
#define VIOLENCE_DEBUG
#define DOUBLE_TEST
#define AUDIO_MAXCHN		(4) 
#define AUDIO_LEFTCHN		0x02
#define AUDIO_RIGHTCHN	0x01

#define AUDIO_LEFTCHN1		0x02
#define AUDIO_RIGHTCHN1	0x01


#define AO_DEVICE_LEFT(Device)	((AUDIO_LEFTCHN << 16) | Device)  //左声道
#define AO_DEVICE_RIGHT(Device)	((AUDIO_RIGHTCHN << 16) | Device)  //右声道
#define AO_DEVICE_DUALTRACK(Device)	(((AUDIO_LEFTCHN |AUDIO_RIGHTCHN) << 16) | Device) //双声道

#define IN const
#define OUT

#define HI3510		3510
#define HI3511		3511
#define HI3512		3512	
#define HI3515		3515
#define HI3515A		35150
#define HI3520		3520
#define HI3521		3521
#define HI3520A		35200
#define HI3520D		35203
#define HI3531		3531
#define HI3535		3535
//陶永亮 100727 blade_all
#define HI3520SC		35201

#define ALIGN_UP(x, a)				((x+a-1)&(~(a-1)))
#define ALIGN_BACK(x, a)			((a) * (((x) / (a))))

/*
 * The basic data type defination
 */
#define PRODUCT_CHN_1	1
#define PRODUCT_CHN_4	4
#define PRODUCT_VGA		6
#define PRODUCT_DVR_4	14
#define PRODUCT_DVR_8	18
#define PRODUCT_DVR_16	26
#define		CRE 	"^M^[[K"                                                                    
#define 	NORMAL	"[0;39m"                                                               
#define		RED		"[1;31m"                                                                  
#define		GREEN	"[1;32m"                                                                
#define		YELLOW	"[1;33m"                                                               
#define		BLUE	"[1;34m"                                                                 
#define		MAGENTA	"[1;35m"                                                              
#define		CYAN	"[1;36m"                                                                 
#define		WHITE	"[1;37m"

//string length
#define SHORT_PATH_LEN		16		//短路径长度
#define FILE_NAME_LEN		32		//文件名长度
#define MIDDLE_PATH_LEN		32		//中路径长度
#define	FULL_PATH_LEN		64		//全路径长度
#define MAX_ALIAS_LEN		64		//别名长度，包括视频通道、报警输入、报警输出

#define INT_NUM_STR_LEN		16		//整数字符串长度 dxl 20110722

#define MAX_EXTNAME_LEN     15		//最大录像扩展名长度
//disk num
#define MAX_SATA_NUM		8		//支持最大的SATA硬盘个数
#define MAX_USB_NUM			4		//支持最大的USB磁盘个数
#define MAX_NFS_NUM			1		//支持最大的NFS个数
#define MAX_ESATA_NUM		1		//支持最大的eSATA个数
#define MAX_HDD_NUM	        8		//支持最大的本地硬盘个数
#define MAX_RECORDER_NUM	2		//支持最大的刻录机数
#define MAX_SD_NUM			1		//支持最大的SD数
#define MAX_PART_NUM		4		//每个磁盘支持的最大分区数
#define MAX_DISK_NUM		(MAX_SATA_NUM + MAX_USB_NUM + MAX_NFS_NUM + MAX_ESATA_NUM + MAX_SD_NUM)
									//支持的最大磁盘个数
//device parameter
#define MAX_CHANNEL_NUM		32					//最大通道数目
#define MAX_INPORT_NUM		64					//最大报警输入端口数
#define MAX_OUTPORT_NUM		32					//最大报警输出端口数
#define MAX_SERIAL_NUM		5					//最大串口数,其实只有前4个串口是用于PTZ控制的，最后一个预留

#define MAX_VIDEO_COVER_NUM	4					//最大视频遮挡区域数
#define MAX_TIME_SEGMENT	4					//最大时间段个数

#define MAX_VCHN_CNT		32					//虚拟合成通道最大的合成画面数
#define ENCRYPT_PWD_LENGTH		16			//视频加密密码长度
//20120913 王磊add
#define LOG_ITEM_LEN		(FULL_PATH_LEN + 8)	//log文件保存的每个条目的长度，为录像文件全路径加上录像大小
//add end

//limits
#define MAX_VIDEO_QUALITY	14					//最大视频质量
#define MIN_VIDEO_QUALITY	6					//最小视频质量

#define RETURN_NONE			0x12345678			//Magic Number,用其判断在td_assert中是否需要返回值

#define ENCRYPT_PWD_LENGTH		16				//视频加密的密码最大为16字节	
#define ENCRYPT_VIDEO_LENGTH	64				//对视频帧中的前64字节进行加密

//陶永亮 100322 非法的字符叠加位置。合法的位置为0~15
#define INVALID_OSD_POS				0xFF


// dxl 20110307 从assiatan.h移到此处
#define VIDEO_WIDTH_BASE	1000
#define VIDEO_HEIGHT_BASE	1000

//added by wanzy 20110902
//shihc mod 20130222
#define CHNNAME_LEN	65
#define CHNNAME_LEN_OLD 33

#define MAX_FRAMERATE_NTSC (Cfg_gMaxFrameSupport())
#define MAX_FRAMERATE_PAL (MAX_FRAMERATE_NTSC - (Cfg_gMaxFrameSupport() / 30) * 5)
#define MAX_FRAMERATE MAX_FRAMERATE_NTSC

#define ENCRYPT_STRING	"\1"
#define ENCRYPT_CHAR	'\1'
//运行状态，心跳时发送,Add by Leeon Tonie, 081219
typedef enum
{
	STATUS_NORMAL = 0,		//正常运行
	STATUS_EXIT,			//退出程序
	STATUS_RESTART,			//重启程序
	STATUS_HOST_READY,		//主片启动完毕，开始心跳
}THeartBeat;

extern FILE* fpDebugFile;
extern FILE* fpThreadFile;
extern unsigned int g_iProcThreadNum;
#define MAX_CDROMSERIALNO_LEN 32
//从net_public.h中移动到public_def.h中，以后所用函数都可以调用
#define ClearString(str, size)	*((char *)(str)) = '\0'
//陶永亮 091117 合法的内存地址范围
#define valid_logic_addr(pointer)	((void*)pointer >= (void*)0x00008000 && (void*)pointer <= (void*)0xc0000000)
//#define debug_info(string)	printf(MAGENTA"[%s || %d || %s || PID = %d || errno = %d] %s\r\n"NORMAL, __FILE__, __LINE__, __func__, getpid(), errno, string)
#if 0
#define get_tid()	pthread_self()
#else
#define get_tid()	syscall(224)
#endif

#ifdef TD_DEBUG
#define func_info()\
	do{\
		time_t tUniqueName = time(NULL);\
		printf(BLUE"%s"NORMAL, ctime(&tUniqueName));\
		printf(BLUE"PID = %d, PPID = %d, Thread ID = %lu, Thread Name: %s\r\n"NORMAL, getpid(),getppid(), get_tid(), __func__);\
		printf(BLUE"Created at line %d, file %s\r\n"NORMAL, __LINE__, __FILE__);\
		printf(BLUE"=================================================================================\r\n"NORMAL);\
	}while(0)


		
#define start_exec(name)\
		struct timeval unique_start ## name;\
		gettimeofday(&unique_start ## name, (struct timezone *)NULL);
		
#define stop_exec(name)\
	do{\
		struct timeval unique_stop ## name;\
		gettimeofday(&unique_stop ## name, (struct timezone *)NULL);\
		printf(CYAN"In function : %s, tid : %d your test %s costs %d microseconds\r\n"NORMAL,\
		__func__, (int)pthread_self(), #name, (int)(1000000*(unique_stop ## name.tv_sec - unique_start ## name.tv_sec) + \
		(unique_stop ## name.tv_usec - unique_start ## name.tv_usec)));\
	}while(0)
		
#define td_show(color, msg) printf(color"[%s || %d || %s] : %s\r\n"NORMAL, __FILE__, __LINE__, __func__, msg)
	#ifdef VIOLENCE_DEBUG
	#define debug_info(string)	printf(MAGENTA"[%s || %d || %s || PID = %d || errno = %d] %s\r\n"NORMAL, __FILE__, __LINE__, __func__, getpid(), errno, string)
	#endif

//陶永亮 091029 DEBUG下断言，打印出出错信息并发送SIGABRT信号
#define td_assert(exp, errorno)	assert(exp)
//陶永亮 100208 在void型的函数中使用该宏
#define td_assert_s(exp) td_assert(exp, RETURN_NONE)
//陶永亮 100210 新增td_perror
#define td_perror(string) \
	td_printf(0xFF00000, "[%s]%s : %s", __func__, string, strerror(errno))
#else

#define func_info()\
	do{\
		if(fpThreadFile != NULL )\
		{\
			if(g_iProcThreadNum++ <= 200)\
			{\
				time_t tUniqueNameInFuncInfo = time(NULL);\
				fprintf(fpThreadFile, "%s", ctime(&tUniqueNameInFuncInfo));\
				fprintf(fpThreadFile, "%d, PID = %d, PPID = %d, Thread ID = %lu(%lu), Thread Name: %s\r\n", g_iProcThreadNum,getpid(),getppid(), get_tid(), pthread_self(), __func__);\
				fprintf(fpThreadFile, "Created at line %d, file %s\r\n", __LINE__, __FILE__);\
				fprintf(fpThreadFile, "=================================================================================\r\n");\
				fflush(fpThreadFile);\
			}\
		}\
	}while(0)

#define start_exec(name)
#define stop_exec(name)
#define td_show(color, msg)
	#ifdef VIOLENCE_DEBUG
	#define debug_info(string)
	#endif
	
//陶永亮 091029 RELEASE下断言，将出错信息记录到debug_info.txt并返回errorno
#define td_assert(exp, errorno)\
	do{\
		if (!(exp))\
		{\
			if (fpDebugFile != NULL)\
			{\
				time_t tUniqueNameInTdAssert = time(NULL);\
				fprintf(fpDebugFile, "%s%s: %d: %s: Assertion \'%s\' failed.\r\n",\
				ctime(&tUniqueNameInTdAssert), __FILE__, __LINE__, __func__, #exp);\
			}\
			return (errorno);\
		}\
	}while(0)
//陶永亮 100208 在void型的函数中使用该宏
#define td_assert_s(exp)\
	do{\
		if (!(exp))\
		{\
			time_t tUniqueNameInTdAssert = time(NULL);\
			if (fpDebugFile != NULL)\
			{\
				fprintf(fpDebugFile, "%s%s: %d: %s: Assertion \'%s\' failed.\r\n",\
				ctime(&tUniqueNameInTdAssert), __FILE__, __LINE__, __func__, #exp);\
			}\
			return;\
		}\
	}while(0)
#define td_perror(string)	
#endif

#define set1(byte, bitn) (byte) |= 0x1 << (bitn)		//将byte的第bitn位置1
#define set0(byte, bitn) (byte) &= ~(0x1 << (bitn))		//将byte的第bitn位置0
#define getbit(byte, bitn) (((byte) >> bitn) & 0x1)	//获取byte的第bitn位
#define setbit1(byte, bitn, sta) ((byte) = (((byte) & (~(0x1 << (bitn)))) | ((sta) << (bitn))))	//将byte的第bitn位置为sta

//#define absollute()		 (int)(times(NULL) / 100)
typedef unsigned char		td_u8;
typedef unsigned char       td_uchar;
typedef unsigned short		td_u16;
typedef unsigned int		td_u32;
typedef unsigned long long 	td_u64;
typedef signed char			td_s8;
typedef short				td_s16;
typedef int					td_s32;
typedef long long			td_s64;


typedef char                td_char;
typedef float				td_float;
typedef double				td_double;
typedef void                td_void;
typedef long double			td_ldouble;
#define PACKED				__attribute__((packed))	

/*******************************************From 3510 below**********************************************************/
#define OSD_REGION_HANDLE td_u32
typedef struct							//Sherry modify 20081121
{
	td_u8 		m_u8Brightness;
	td_u8 		m_u8Hue;
	td_u8 		m_u8Contrast;
	td_u8 		m_u8Saturation;
	td_u8		m_u8StartTime[3];		//0:Hour 1:Minute 2:Second
	td_u8		m_u8StopTime[3];		//0:Hour 1:Minute 2:Second
	td_u8		m_u8CtoG;				//Leeon Added 090112, 彩转灰(Color/Gray)使能
}structVideoParam;

typedef struct __RECT__
{
	unsigned short left;
	unsigned short top;
	unsigned short right;
	unsigned short bottom;
}Rect_t;

typedef struct
{
	td_u8		m_u8SensorFlipEnable;
	td_u8		m_u8SensorMirrorEnable;
	td_u8		m_u8SensorScene;
}SENSORPARA;

/*用于叠加通道名称*/
typedef struct osd_text_struct
{
//	OSD_REGION_HANDLE osd_handle;     	/*创建osd 时底层返回*/
	int  	show;      					/*true = show ，是否显示*/
	char	text[CHNNAME_LEN];					/*叠加字符内容*/
	int	osdpos;          				/*叠加位置0~15*/
	int 	osdX;						//叠加位置横坐标
	int 	osdY;						//叠加位置纵坐标
	td_u32	osdColor;      				//叠加字符颜色
}OSD_CHANNAME_T;

/*******************************************From 3510 above**********************************************************/

/*----------------------------------------------*
 * The common constant                          *
 *----------------------------------------------*/
typedef enum {
    td_false    = 0,
    td_true     = 1,
} td_bool;

#ifndef NULL
#define NULL             0L
#endif

#define td_success          0 
#define td_failure          (-1)
//device capability
//陶永亮 100727 blade_all
#define VIDEOENCODE_MAX_CHANNEL_NUM		32//16  //sherry 20100613 modify for 3520-single-chip
#define MAX_VCA_CHN_NUM    32
#define VIDEOINPUT_MAX_CHANNEL_NUM		32
#define AUDIOENCODE_MAX_CHANNEL_NUM	16
#define AUDIOINPUT_MAX_CHANNEL_NUM		16
#define VIDEOOUTPUT_MAX_CHANNEL_NUM		16    //gxl added 20091215
//#define GPIN_MAX_NUM	4
//#define GPOUT_MAX_NUM 4
//Cheng 2010/02/21 add talk channel
#define AUDIO_CHANNEL_TALK_NUM                    1

// for test
#ifdef TD_DEBUG
#define	MAX_CONNECTION		4		//测试时使用
#else
#define	MAX_CONNECTION		8		//每一通道最多可有8个连接
#endif
#define   MAX_ENCODE_ABILITY	480        //最大编码能力480 cif

#define NO_STREAM   		0
#define ONLY_VIDEO  		1
#define ONLY_AUDIO  		2
#define VIDEO_AUDIO 		3

#define NETMODE_TCP     	1
#define NETMODE_UDP     	2
#define NETMODE_MC      	3
#define NVS_ACTIVE      	4

#define BYTES_1K			(0x1 << 10)
#define BYTES_1M			(0x1 << 20)
#define BYTES_1G			((td_u64)0x1 << 30)
#define BYTES_1T			((td_u64)0x1 << 40)

#ifndef MIN
#define 	MIN(x,y) ((x) < (y) ? (x) : (y))
#endif
#ifndef MAX
#define 	MAX(x,y) ((x) > (y) ? (x) : (y))
#endif
#ifndef MIN_IN3
#define MIN_IN3(a,b,c) MIN(MIN(a,b),c)
#endif

#define MAX_FRAME_SIZE   BYTES_1M    // 最大帧1M 

//连接类型
#define CONNECTMODE_CMD		1
#define CONNECTMODE_DATA		2
#define CONNECTMODE_DIDA		0

#define	 TD_AUTO     		1

#define DEVICE_DVRS 0
#define DEVICE_DECS 1

//曹海波添加  查询未加锁录像
#define QUERY_RECFILE_UNLOCKED	(0x1 << 24)

typedef enum
{
	AUDIO_TYPE_G711A = 1,
	AUDIO_TYPE_G711U,
	AUDIO_TYPE_DVI4,
	//ljj add
	AUDIO_TYPE_MEDIA_G726_1_24 = 0x05,
	AUDIO_TYPE_MEDIA_G726_1_32 = 0x06,
	AUDIO_TYPE_MEDIA_G726_1_40 = 0x07,
	AUDIO_TYPE_MEDIA_AAC = 0x16, // huaqiang add for AAC 20130107
	AUDIO_TYPE_ADPCM_IMA = 0x23,
	//ljj add end 
	// zty 20120220
	AUDIO_TYPE_MEDIA_G726_16 = 0x24,
	AUDIO_TYPE_MEDIA_G726_24 = 0x25,
	AUDIO_TYPE_MEDIA_G726_32 = 0x26,
	AUDIO_TYPE_MEDIA_G726_40 = 0x27,
	// zty add end
	
	//ljj add 
	AUDIO_TYPE_PCM	= 0x33,
	AUDIO_BUTT,	

    //qiaohaijun for audio error
	AUDIO_TYPE_ERROR = 0xff
}AUDIO_TYPE_E;

typedef enum 
{
	ANALOG_CHN = 0,  //模拟通道
	DIG_CHN,		 //数字通道
	VOENC_CHN,       //VO复合编码通道
	BUTT,
}CHN_TYPE;

typedef enum
{
	VENC_H264 = 0,
	VENC_MJPEG,
	VENC_BUTT,
}VENC_TYPE_E;

typedef enum
{
	QCIF =0,
	HCIF,
	FCIF,
	HD1,
	FD1,
	MD1,
	QVGA,
	VGA,
	HVGA,
	F720P,
	F960P,
	F1200,
	F1080P,
	QXGA,
	QHD	= 0x0100,
	H960 = 0x0200,
	MA5 = 0x300,
	M5 = 0x400,
	QSXGA = 0x0500,
    //走廊模式分辨率格式:100000 + N(N为以上分辨率代码),以此类推
    F720P_9_16 = 0x100009,    //720x 1280
    F1080P_9_16 = 0x10000C,	//1080x 1920
	VIEDOSIZE_BUTT,
}VIDEO_SIZE_E;

#define F1080I 40

#define CIF		FCIF
#define D1		FD1
#define SXGA		HVGA


//兼容3520 SDI设备所附加两个宏定义，其他设备不要用
#define    HD_SDI720P 		2
#define    HD_SDI1080P 	3
//end

typedef enum
{
	VI_NORM_PAL 		= 0x0000,
	VI_NORM_NTSC,
	VI_NORM_AUTO		= 0x0004,

	VI_NORM_960H_PAL 	= 0x0010,
	VI_NORM_960H_NTSC,
	
	VI_NORM_720P		= 0x040,//0x0100
	VI_NORM_1080P		= 0x050,//0x0110
	VI_NORM_BUTT,
}VI_NORM;

typedef enum //shihc add 20121206
{
	VI_1080P30 = 0,
	VI_1080P25,
	VI_1080I60,
	VI_1080I50,
	VI_720P60,
	VI_720P50,
	VI_720P30,
	VI_720P25,
	VI_1080P60,
	VI_1080P50,
} VI_HD_FROMAT_E;


typedef struct
{
    char    m_cDeviceId[64];
    char    m_cDeviceName[64];
    char    m_cNFSIp[16];
    char  	m_cNFSPath[255+1];
	int		m_iDevNo;								//设备编号，陶永亮，2008-12-03，DVR新增字段
	int 	m_blNfsEnable;							//NFS使能
	int		m_iVspport;
	int		m_iVapport;
	char	m_cAccessnum[64];
}STR_COMMON_INFO;

#define MAX_PATH_LEN         (255+1)
#define USER_NAME_LEN       16
#define PASSWORD_LEN        16

typedef struct
{
	char    m_cManagerServerIp[16];
	long    m_lManagerServerPort;
	char    m_cHeartBeatServerIp[16];
	long    m_lHeartBeatPort;
	char    m_cRegisterServerIP[16];
	long    m_lRegisterPort;
	char     m_cEnableHeartBeat[16];
	int     m_iHeartBeatPeriod;
	int     m_iRegisterTime;
	char    m_cVapPath[MAX_PATH_LEN];
	char    m_authServerIp[16];
	long    m_lauthServerPort;
	char    m_authUserName[USER_NAME_LEN];
	char    m_authUserPassword[PASSWORD_LEN];
	char    m_cputhreshold;
	char	m_memthreshold;
}STR_NET_MANAGE_INFO;


#define VERSION_LEN     64
typedef struct
{
    char    m_csoftWareVersion[VERSION_LEN];
}STR_UPGRADE_INFO;

typedef struct
{
 	int    m_iFormat;
	char m_cSeperatechar[8]; 
}STR_DATE_FORMAT;
/**************************Other Attributes Begin*******************************/
//陶永亮 091222 别名管理
typedef enum
{
	ALIAS_CHANNEL = 0,		//通道
	ALIAS_ALARM_INPUT,		//报警输入
	ALIAS_ALARM_OUTPUT,		//报警输出
}TAliasType;

typedef struct
{
	td_u8	m_cChannel[MAX_CHANNEL_NUM][MAX_ALIAS_LEN + 1];		//通道别名
	td_u8	m_cAlarmInput[MAX_INPORT_NUM][MAX_ALIAS_LEN + 1];	//报警输入通道别名
	td_u8	m_cAlarmOutput[MAX_OUTPORT_NUM][MAX_ALIAS_LEN + 1];	//报警输出通道名
	td_s32	m_iChannelVer;									//通道别名版本
	td_s32	m_iAlarmInputVer;								//报警输入通道别名版本
	td_s32	m_iAlarmOutputVer;								//报警输出通道别名版本
}TAlias;

/**************************Other Attributes Begin*******************************/
/**************************Media Attributes Begin*******************************/
typedef enum hiFRAME_TYPE_E
{
    FRAME_I = 0,   /* I frame */
    FRAME_P,       /* P frame */
    FRAME_BUTT
} FRAME_TYPE_E;

//音视频帧头
typedef struct
{
    unsigned int	u32FrameID ;	//标示ID,32位,固定为: 0x 00 00 00 02
    unsigned int	u32FrameSize;	//帧大小32位,整个帧大小,字节数
    unsigned char	u8FrameType;	//帧类型,8位,FRAME_I=0,  FRAME_P=1, FRAME_B=2 
    unsigned int	u32FrameNO;	//帧序号,32位,帧序号,循环递增
    unsigned int	u32TimeStamp;	//时间戳,32位,暂时不知道有什么用
    unsigned int	u32VStreamLen;	//视频数据长度,32位,视频数据大小
    unsigned short	u16AFrames;	//音频帧数,16位,该视频帧携带音频帧数
    unsigned short	u16AFrameSize;	//音频帧大小,16位,音频帧大小
    unsigned char	u8ACoder;	//音频压缩方式,8位,不压缩:0;G711_A:0x01; G711_U:0x02;ADPCM_A :0x03;G726:0x04
    unsigned short	reserved;		//16位,保留,32位对齐
}S_FrameHeader,*pS_FrameHeader;
//帧头后面先跟整帧视频数据,再跟所有音频数据

#define MAX_COVWORD_LEN 36
//文件头结构
typedef struct
{
    unsigned short  FrameRate;	//帧率
    unsigned short  Width;		//图像宽
    unsigned short  Height;		//图像高
    unsigned short  Mode;		//编码模式：11（MP4)， 21(H264)
    unsigned short  bAudio;		//是否带音频
    unsigned short  Year;		//H264编码不用以下下字段，全部置0xFF,可以补充为录像时间
    unsigned short  Month;
    unsigned short  Day;
    unsigned short  Hour;
    unsigned short  Minute;
    unsigned short  Second;
    unsigned short  CoverMask;
    char cCovWord[36];		//固定存放字符串"S MULTI-MEDIA STREAM (H.264)"加0x00结束符，剩余部分填充0xFF
    unsigned int 	m_uiFrameNoDiff;	// 文件首尾帧号差
    unsigned int 	TriggerHigh;	// 记录报警端口号20120906 杨珏
    unsigned int 	TriggerLow;	// 记录报警端口号20120906 杨珏
    unsigned short	reserved;		//表cCovWord当前的长度，当前值为36
    unsigned char   AChannels;   // 声道1/2，默认为1
	unsigned char   BitsPerSample;// 采样位数8/16/24, 默认16
    unsigned int 	AudioSample;
    unsigned int    TotalSize;	//文件总大小(字节数)，老版本保留
    unsigned int    FrameCount;	//文件总帧数,老版本保留
}S_FileHeader,*pS_FileHeader;
/**************************Media Attributes End*******************************/
/**************************Alarm Attributes Begin*******************************/
//几种报警类型
#if 1 // modify by caizhaoxu 20120321
typedef enum
{
	ALM_VIDEO_LOST,								//视频丢失报警,1
	ALM_PORT,									//端口报警,0
	ALM_MD,										//移动侦测报警,2
	ALM_VIDEO_COVER,							// video cover
	ALM_VCA,									// this value only for ensure ALM_AUDIO_LOST is 5
	//add by gyn 20120903
	ALM_AUDIO_LOST,                             //音频丢失报警
	//add end
	ALM_TEM_HUM,
	/****************************************************************
	* if you want to save your alarm info into config_alm.dat by type,
	* please add you type over this value
	*****************************************************************/
	ALM_SAVE_TO_CFG, 

	ALM_TW,                						/*绊线报警 */
	ALM_PM,										/* 周界报警*/
	ALM_OSCER,									/*物品看护*/
	//ALM_FACE,									/*人脸检测*/
	ALM_DIAGNOSE,								/*视频诊断*/
	ALM_CAP,								    //智能跟踪//shihc add 20130225
	ALM_CAP_td,
	ALM_CPC,									//流量统计
	ALM_CDD,                                    //人群聚集
	ALM_SVD,									//离岗
	ALM_MAX,									//最大值，该值在声明数组时使用，要扩展内容请在该值以上添加
}TAlarmType;

#else
typedef enum
{
	ALM_VIDEO_LOST,								//视频丢失报警
	ALM_PORT,									//端口报警
	ALM_MD,										//移动侦测报警
	ALM_TW,                //zhangweiwei add
	ALM_PM,
	ALM_FACE,
	ALM_DIAGNOSE,
	ALM_MAX,									//最大值，该值在声明数组时使用，要扩展内容请在该值以上添加
}TAlarmType;
#endif
/**************************Alarm Attributes End*******************************/
/**************************Hardware Attributes Begin*******************************/

/**************************Hardware Attributes End*******************************/

/**************************Com Attributes Begin*******************************/

//串口的工作模式
typedef enum
{
	PTZ_PROTOCOL = 1,								//协议控制模式
	PTZ_STREAM = 2,									//透明通道模式
	PTZ_RESERVED = 3,								//预留
	PTZ_7601B = 4,									//7601B串行总线报警器
	key_485 = 5,
	GPS_MOD = 6,									//车载GPS
	ATM_PROTOCOL = 7,
	PTZ_WORKMODE_MAX,								//最大值，添加其他类型请在上面添加
}TComWorkMode;

//记录串口配置的结构体
typedef struct
{
	td_s32		m_iBaudRate;								//设备的波特率
	TComWorkMode	m_eMode;									//串口的工作模式
	td_u8		m_ucDataBit;								//数据位
	td_u8		m_ucStopBit;								//停止位
	td_u8		m_ucVerifyBit;								//校验位
	td_u8		m_uUartId;									// dxl 20110513 加入UART配置，以兼容不同硬件平台
}TCom;
/**************************Com Attributes End**********************************/
/**************************PTZ Attributes Begin**********************************/
//通道相关的PTZ属性
typedef struct
{
	//Leeon Tonie Added below for 3511, new PTZ mode.
	td_u8			m_cProtocol;						//该通道所使用的控制协议编号
	td_u8			m_cProtocolName[32];				//该通道所使用的协议名称
    td_u8			m_cComNo;							//该通道对应的通道号
    td_s16			m_sAddress;							//该通道所连接设备的地址
    td_u8			m_blComAttrEnable;					//是否自定义串口属性
    TCom			m_stComAttr;						//该协议所对应的串口属性，如9600,'n',8,1
}TPTZChannel;
/**************************PTZ Attributes End*******************************/
/**************************User Attributes Begin*******************************/
#define MAX_IPFILTER_NUM			16

//陶永亮 091028 为IP过滤定义独立的数据结构，并移至用户模块
typedef struct
{
	//这两项是通过网络设置的屏蔽方式
    td_u32	    m_u32ExpectIP;					//被屏蔽的IP地址
    td_u32		m_u32ExpectMask;				//被屏蔽的IP段掩码
	
	//Leeon Tonie add for Tiandy-Dvr, more ip filter
	//以下参数是通过本地设置的黑名单/白名单的方式
	td_u8		m_cFilterType;					//类型:黑名单/白名单/不启用
	td_u8		m_cIPNum;						//名单长度
	td_u32		m_uiIPList[MAX_IPFILTER_NUM];	//名单
}TIpFilter;
//zhangshengusr 20131029 为过滤被断开的ip定义的结构体
typedef struct
{
	td_u32  m_uiIP;		//被断开的ip
	td_s32  m_iTime;	//被断开的时间
}TdicUsrMsg;

typedef struct
{
	td_s32  m_iNumNow;  //目前被禁止的ip个数
	TdicUsrMsg  m_IPMember[32];//最大保存32个用户
	pthread_mutex_t g_mutexIPforbidLogon;//用于编辑禁止登陆ip列表的保护
} TIPFilter_ex;

/**************************User Attributes End**********************************/
//设备支持的字符集
typedef enum
{
	GB2312 = 1,
	UTF8,
}TCharsetType;


//add by wanzy  2011/10/19 增加外挂sip协议

//SIP设备参数
typedef struct
{
	char m_SipServerIp[33];	//sip服务器ip
	int  m_SipServerPort;	//sip服务器端口号
	char m_SipServerID[33];	//sip服务器ID
	char m_SipDeviceID[33]; //设备编号
	char m_SipUserName[33]; //用户名
	char m_SipPassword[33];	//密码
	int  m_RegisterValidity;//注册有效期	
	int  m_keepalivetime;	//保活时间
	int  m_HeartBeatinterval;	//心跳间隔时间
	int  m_HeartBeatTimes;	//心跳次数
	int  m_EnableRegister;
}TSIPDeviceInfo;

//SIP视频通道参数
typedef struct
{
	int   	m_iChannelNo;
	char	m_pcChannelId[32];	//通道设备编号
	int   	m_iLevel;		//当前ptz控制级别
	int   	m_iPTZtime;		//上次ptz控制计时
}TSIPChnPara;

//SIP报警通道参数
typedef struct									
{
	int   	m_iChannelNo;
	char	m_pcChannelId[32]; //通道设备编号
	int   	m_iLevel;			//通道报警级别
}TSIPAlarmPara;

//add by wanzy 2011/10/19
typedef struct
{
	int	m_iCmdNo;
	int   	m_iChannelNo;
	char	m_pcChannelId[32];
	int   	m_iLevel;
	int   	m_iPTZtime;
}TCstmChnParaID;

//add by nsg 120905
typedef struct
{
	td_s32	m_iInformWay;			//通信方式0:串口 1:UDP
	char	m_cProtocolType[33];	//协议厂家名称	
	td_u32  m_uiSrcIP;				//ATM  IP地址
	td_s32	m_iSrcPort;				//ATM端口号
	td_u32	m_uiDestIP;				//设备IP地址
	td_s32	m_iDestPort;			//设备端口号
}TAtmPara;			//ATM参数

#define STR_SERVER_NAME_LEN 63
#define IP_STR_LEN 31

typedef struct 
{
	char	m_cServerName[STR_SERVER_NAME_LEN + 1];       	//服务器地址
	char	m_cPath[STR_SERVER_NAME_LEN + 1];				//文件路径
	char 	m_cUserName[IP_STR_LEN + 1];         			//用户名
	char	m_cPassword[IP_STR_LEN + 1];					//密码
	int		m_iPort;										//端口号
	int 	m_iUseage;                   					//用途0 升级 1上传
	int 	m_iUploadMethod;              					//上传方式0:自动1:手动
}TFtpPara;	//	FTP参数

#define MAX_LEN_EMAILPARM 64
typedef struct TSmtpPara
{
	char m_SmtpServerIp[MAX_LEN_EMAILPARM];
	char m_SmtpServerPort[MAX_LEN_EMAILPARM/8];
	char m_SmtpServerAccount[MAX_LEN_EMAILPARM];
	char m_SmtpServerPassword[MAX_LEN_EMAILPARM];
	char m_AuthType[MAX_LEN_EMAILPARM/2];
	char m_TimeOut[MAX_LEN_EMAILPARM/8];
	
	char m_From[MAX_LEN_EMAILPARM];
	char m_To[MAX_LEN_EMAILPARM];
	char m_EmailSubject[MAX_LEN_EMAILPARM*2];
	char m_EmailAddr[4][MAX_LEN_EMAILPARM];
}TSmtpPara;

//end

#define TR_SUBDEVIDREQ 1000
#define TR_SUBDEVIDRSP -1000
#define TR_MAINDEVIDREQ 1001
#define TR_MAINDEVIDRSP -1001

//add by zhuangzhibing 20120216
typedef enum
{
	NETDATA_COM 	= 1,									//网络数据通过透明通道发送
	COMDATA			= 2,									//串口数据
	UIDATA			= 3,									//Ui数据通过主程序转发
	NETDATA_DZ		= 4,									//网络数据通过DZ协议发送
}TDataType;//向外挂发送数据的类型
//add end
//文件类型
typedef enum
{
	FILE_REC = 0,    //录像文件
	FILE_IMG,        //图片文件
	FILE_BACKUP,	 //备份录像
	FILE_AUDIO,      //音频文件
	MAX_FILE_TYPE,	 //文件类型的最大值
}TFileType;

typedef enum
{
	CONVERT_FILETYPE_SDV=1, 	//默认SDV格式,不转换
	CONVERT_FILETYPE_AVI,  	//转换成AVI格式
	CONVERT_FILETYPE_MP4,   	//转换成MP4格式
	CONVERT_FILETYPE_MAX,  //预留
}CONVERT_TYPE_E;

typedef enum
{
	CBL_SINGLE_FILETYPE_DISABLE=0, 	//不使能单一文件刻录
	CBL_SINGLE_FILETYPE_SDV,
	CBL_SINGLE_FILETYPE_AVI,
	CBL_SINGLE_FILETYPE_MP4,
	CBL_SINGLE_FILETYPE_MAX,  //预留
}CBL_SINGLE_TYPE_E;//备份或刻录单一文件录像格式


typedef enum
{
	AUDIO_FILETYPE_NONE =0, 	//默认不备份音频文件
	AUDIO_FILETYPE_AAC,  	//备份AAC音频文件
	AUDIO_FILETYPE_MAX,  //预留
}BACK_AUDIO_TYPE_E;


typedef td_s32 TRecordType;
#define MAX_RESERVED_INFO_LEN	64	//录像文件信息中的预留信息长度

//文件索引结构
typedef struct
{
	td_u64	m_ulFileIndex;					//文件索引号
	td_u8	m_ucChannelNo;					//通道号
	TFileType	m_eFileType;				//文件类型,TFileType
	TRecordType	m_eRecordType;				//录像类型,TRecordType
	td_u64 	m_eDevType;						//视频源设备类型 
	td_s32 	m_iRecAttr;						//录像文件的属性，用不同录像类型权值的乘积来表示一个录像文件所具有的多种属性
	td_u8	m_ucFileName[FILE_NAME_LEN];	//文件名，不含路径
	td_u8	m_ucFileNameSed[FILE_NAME_LEN];//冗余录像文件名
	td_u32	m_uiFileSize;					//文件大小，单位BYTES
	time_t	m_iStartTime;					//录像开始时间
	time_t	m_iStopTime;					//录像结束时间
	td_u8	m_cReserved[MAX_RESERVED_INFO_LEN];	//预留信息，用于填充自定义信息	
	td_u32  m_iFileSizeIndex;
	td_u32  m_iSedFileSizeIndex;
	td_u32  m_iChnPickFlag;
}TFileInfo;
typedef struct TQueryResult_S TQueryResult;
struct TQueryResult_S
{
	TFileInfo		m_stFileInfo;
	int				m_iDisk;
	TQueryResult*	m_pstNext;
};
//该结构体用于查询执行者
typedef struct
{
	td_u32 		m_uiSocket;								//SOCKET，用于唯一标识谁执行了这个查询;0表示UI，其他表示网络客户端
	char**		m_ppcResult;							//查询结果记录
	TQueryResult*	m_stResult;
	td_s32		m_iColumn;								//查询到的列数
	td_s32		m_iNum;									//记录查询到的结果数
	td_u8		m_blNewestData;							//用于标识该节点中存储的是不是最新的查询结果
	td_s32		m_iStartQueryTime;						//记录查询开始时间，用于超时退出.
	//以下记录查询条件
	td_u8		m_ucChannelNo;							//通道号
	td_u8		m_ucFileType;							//文件类型
	td_u8		m_ucRecType;							//录像类型
	td_u8		m_ucDevType;							//视频源设备类型
	time_t		m_iStartTime;							//时间段起始时间
	time_t		m_iStopTime;							//时间段结束时间
	td_u8		m_cReserved[MAX_RESERVED_INFO_LEN];		//预留信息，用于填充自定义信息	
}TQueryNode;

#ifdef TD_DEBUG
#else
#define TODO
#endif
//shihc add 20130320  定义通用的dvr服务的ID值,根据需求进行扩展
typedef enum
{
	COMMON_AUDIOVIDEO	= 0x1000,//音视频模块开始
	
	COMMON_FONTOVerlAY  = 0x2000,//字符叠加模块开始

	COMMON_COMPTZ	    = 0x3000,//串口PTZ模块开始
	
	COMMON_ABNORMAL     = 0x4000,//系统异常模块开始
	
	COMMON_ARLAM_MD	    = 0x5000,//报警模块开始//移动报警使能
	COMMON_ARLAM_OD,
	
	COMMON_STORAGE      = 0x6000,//存储模块开始	
	COMMON_COMMONENABLE_ONEKEYREC, //一键录像 0-停止，1-开启
	COMMON_COMMONENABLE_HASHENABLE, //哈希校验 0-不是能，1-使能
	COMMON_COMMONENABLE_SPLITAVENABLE, //提取纯音频文件0-不使能，1-使能
	COMMON_COMMONENABLE_SPLITAVBURNENABLE, //刻录纯音频文件0-不使能，1-使能
	COMMON_COMMONENABLE_SPLITAVBACKUPENABLE, //备份刻录纯音频文件0-不使能，1-使能
	COMMON_COMMONENABLE_BURNFILEFORMAT = 0x6006, //0-保留，1-sdv,2-avi, 3-mp4
	

	COMMON_NETSERVICE_SNMP = 0x7000,//网络服务模块开始,//SNMP
	COMMON_NETSERVICE_SMTP,//SMTP
	COMMON_NETSERVICE_RTSP_VERIFY,//rtsp校验
	COMMON_NETSERVICE_28181,//28181纯视频 

	
	COMMON_USERS        = 0x8000,//用户模块开始
	
	COMMON_PUSET	    = 0x9000,//PU模块开始

 
	COMMON_DISK_DISCGROUP= 0xA000,//磁盘模块开始,//盘组策略
	COMMON_DISK_QUOTA,    //配额策略
	COMMON_RAID,					//RAID模块开始




	
	COMMON_SYSTEM	    = 0xB000,//系统管理模块开始
	COMMON_TEMPCTRL,//风扇温控阀值控制
	
	COMMON_COMMUNICATION  = 0xC000,//通信模块开始
	
	COMMON_NETCONNECT	  = 0xD000,//网络连接模块开始
	
	COMMON_VCA            = 0xE000,//智能分析模块开始

	COMMON_ATM	          = 0xF000,//ATM模块开始
	
	COMMON_TRAFFIC        = 0x10000,//行业交通模块开始
	
	COMMON_DZ	          = 0x11000,//DZ相关模块开始

	COMMON_COMMONENABLE   = 0x12000,//车载通用使能模块开始
	COMMON_COMMONENABLE_GPSTIMING,//GPS校时
	COMMON_COMMONENABLE_ALARM,//设备报警电压阈值
	COMMON_COMMONENABLE_SHUTDOWN,//设备关机电压阈值

	COMMON_TELNETDEN	  = 0x12014,	//telnet服务使能
	COMMON_SETCLOSEPROPERTY = 0x12015,	//封盘弹盘使能
	COMMON_END            = 0x14000,//结束符
	

}SYSTEM_SERVICE_COMMON_ID;
//shihc add 20130320  定义通用的系统报错ID值,根据需求进行扩展
typedef enum
{
	LASTERROR_AUDIOVIDEO_CHANGECHNTYPE = 0x1000,//音视频模块开始,//切换通道类型失败
	
	LASTERROR_FONTOVerlAY     = 0x2000,//字符叠加模块开始

	LASTERROR_COMPTZ	      = 0x3000,//串口PTZ模块开始
	
	LASTERROR_ABNORMAL        = 0x4000,//系统异常模块开始
	
	LASTERROR_ARLAM	          = 0x5000,//报警模块开始
	   	
	LASTERROR_SETLOCKSTATUS_FAILURE = 0x6000,//存储模块开始,	//设置文件锁状态失败
	LASTERROR_COMMONENABLE_ONEKEYREC,//通用业务存储模式设置失败
	LASTERROR_COMMONENABLE_HASHENABLE,//通用业务哈希使能设置失败
	LASTERROR_COMMONENABLE_SPLITAVENABLE, //通用业务生成纯音频文件设置失败
	
	LASTERROR_COMMONENABLE_SPLITAVBURNENABLE, //刻录纯音频文件0-不使能，1-使能
	LASTERROR_COMMONENABLE_SPLITAVBACKUPENABLE, //备份刻录纯音频文件0-不使能，1-使能

	LASTERROR_COMMONENABLE_BURNFILEFORMAT = 0x6006, //通用业务设置实时刻录录像文件格式失败
	
	LASTERROR_NETSERVICE	  = 0x7000,//网络服务模块开始
	LASTERROR_SMTP,//smtp设置失败
	LASTERROR_RTSP_VERIFY,//rtsp检验设置失败

	LASTERROR_USERS           = 0x8000,//用户模块开始
	
	LASTERROR_PUSET	          = 0x9000,//PU模块开始
	
	LASTERROR_DISK            = 0xA000,//磁盘模块开始
	LASTERROE_RAID,						//通用业务RAID模式设置失败

	LASTERROR_SYSTEM	      = 0xB000,//系统管理模块开始
	
	LASTERROR_COMMUNICATION   = 0xC000,//通信模块开始
	
	LASTERROR_NETCONNECT	  = 0xD000,//网络连接模块开始
	
	LASTERROR_VCA             = 0xE000,//智能分析模块开始

	LASTERROR_ATM	          = 0xF000,//ATM模块开始
	
	LASTERROR_TRAFFIC         = 0x10000,//行业交通模块开始
	
	LASTERROR_DZ	          = 0x11000,//DZ相关模块开始

	LASTERROR_COMMONENABLE_SNMP = 0x12000,//通用业务使能模块开始	,//SNMP使能失败
	LASTERROR_COMMONENABLE_STORAGEMODE,//通用业务存储模式设置失败
	LASTERROR_COMMONENABLE_GPSTIMING,//通用业务GPS校时使能设置失败
	LASTERROR_COMMON_COMMONENABLE_ALARMPOWER,//报警关机电压阈值设置失败
	LASTERROR_COMMON_SETCLOSEPROPERTY = 0x12015, //封盘、弹盘设置失败

	LASTERROR_END             = 0x14000,//结束符
	

}LASTERROR_ID;


//int td_printf(unsigned int handle, char* pszfmt, ...);
typedef enum
{
	PTZPRI_ALARM  = 0,      //报警联动
	PTZPRI_VCACAP  ,       //智能跟踪
	PTZPRI_REMOTE,         //远程优先级
	PTZPRI_LOCAL,	        //本地优先级
	PTZPRI_MAX,	        // 最大
}TPTZ_PRIORITY;

//zy 20130926
typedef struct 
{
    td_u32 u32Width;
    td_u32 u32Height;
}TSize;

typedef enum
{
	REC_TAG_ADD  = 0,      //添加标签
	REC_TAG_DEL  ,       //删除标签
	REC_TAG_UPDATE,         //编辑标签
	REC_TAG_QUERY,         //编辑标签
}TREC_TAG_OPERATION;

typedef struct
{
   time_t	m_iStartTime;					//时间段起始时间
   time_t	m_iStopTime;					//时间段结束时间
}vca_TimeSegment;

#define MAX_RTMP_LIST_INFO		16					//RTMP列表信息最大数
#define MAX_RTSP_LIST_INFO		64					//RTSP列表信息最大数

#define JMB39X ON

#define PM_TC_2800AN_SD		0xC0120	//3520mc
#define PM_TC_2800AN_SX		0xC0140	//3520sc
#define PM_TC_2816AN_SF_H_T	0xC0171	//3531&3532  16_960H(16) || 2U审讯960H
#define PM_TC_2804AN_SAW	0xC0172	//3531&3532  sdi(4/8) || 2U庭审||2U审讯SDI
#define PM_TC_2816AN_SF_T	0xC0174	//3531&3532  16_D1(16)
#define PM_TC_H804BE_P		0xC0175	//3531单片sdi设备便携式审讯
#define PM_TC_H804I_HD_BP	0xC0179	//3531&3532  sdi(4)	3U审讯SDI
#define PM_TC_H804N_HD_P	0xC0180	//3531  4_960H(4)	3U审讯960H
#define PM_TC_H908NC_HD		0xC017B	//3531&3532  SDI	3U庭审
#define PM_TC_H904B_HD		0xC017A	//3531&3532  SDI	2U简约庭审主机V6.2版
#define PM_TC_H904BIX_HD_I  0xC0184	//3531 4路混合便携式庭审主机

#define JumpIf(c, lable)			if (c) goto lable
#define BreakIf(c)				if (c) break
#define ContinueIf(c)				if (c) continue
#define RetIf(c)					if (c) return
#define RetValueIf(c, value)		if (c) return (value)
#define DoIf(c, a)			if (c) {a;}

#define MAX_OSD_TYPE 5
typedef struct
{
	unsigned int m_uiFontSize[MAX_OSD_TYPE];			//增加字号
}TOSDParamEx;

#endif
