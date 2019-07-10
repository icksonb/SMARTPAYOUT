
#ifndef _ITLSSPCOMMH
#define _ITLSSPCOMMH
#define CCONV _stdcall
#define NOMANGLE


#include "itl_types.h"
#include "ssp_defines.h"
#include <sys/time.h>
#include <time.h>

#ifdef __cplusplus
 extern "C" {
#endif


#define MAX_SSP_PORT 200

#define NO_ENCRYPTION 0
#define ENCRYPTION_SET 1

typedef struct{
	unsigned long long FixedKey;
	unsigned long long EncryptKey;
}SSP_FULL_KEY;


typedef struct{
	unsigned short packetTime;
	unsigned char PacketLength;
	unsigned char PacketData[255];
}SSP_PACKET;






typedef struct{
	SSP_FULL_KEY Key;
	unsigned long BaudRate;
	unsigned long Timeout;
	unsigned char PortNumber;
	unsigned char SSPAddress;
	unsigned char RetryLevel;
	unsigned char EncryptionStatus;
	unsigned char CommandDataLength;
	unsigned char CommandData[255];
	unsigned char ResponseStatus;
	unsigned char ResponseDataLength;
	unsigned char ResponseData[255];
	unsigned char IgnoreError;
}SSP_COMMAND;


typedef struct{
	unsigned char txData[255];
	unsigned char txPtr;
	unsigned char rxData[255];
	unsigned char rxPtr;
	unsigned char txBufferLength;
	unsigned char rxBufferLength;
	unsigned char SSPAddress;
	unsigned char NewResponse;
	unsigned char CheckStuff;
}SSP_TX_RX_PACKET;



typedef struct{
    long long Generator;
    long long Modulus;
    long long HostInter;
    long long HostRandom;
    long long SlaveInterKey;
    long long SlaveRandom;
    long long KeyHost;
    long long KeySlave;
}SSP_KEYS;






/* command status enumeration */
typedef enum{
	PORT_CLOSED,
	PORT_OPEN,
	PORT_ERROR,
	SSP_REPLY_OK,
	SSP_PACKET_ERROR,
	SSP_CMD_TIMEOUT,
}PORT_STATUS;

typedef struct {
	SSP_FULL_KEY Key;
	unsigned long Timeout;
	unsigned char SSPAddress;
	unsigned char RetryLevel;
	unsigned char EncryptionStatus;
	SSP_PORT port;
}SSP_COMMAND_SETUP;

typedef struct 
{
    unsigned char event;
    unsigned long data1;
    unsigned long data2;
    unsigned char ResponseSize;
    char cc[4];
    unsigned char Response[255];
} SSP_POLL_EVENT;

typedef struct {
    SSP_POLL_EVENT events[20];
    unsigned char event_count;
} SSP_POLL_DATA;

typedef struct{
    unsigned char UnitType;
    char FirmwareVersion[5];
    char CountryCode[4];
    unsigned long ValueMultiplier;
    unsigned char ProtocolVersion;
}SSP_UNIT_DATA;

typedef struct{
    unsigned char NumberOfChannels;
    unsigned char ChannelData[16];
}SSP_CHANNEL_DATA;

typedef struct {
    unsigned char UnitType;
    char FirmwareVersion[5];
    char CountryCode[4];
    unsigned long ValueMultiplier;
    SSP_CHANNEL_DATA ChannelValues;
    SSP_CHANNEL_DATA ChannelSecurity;
    unsigned long RealValueMultiplier;
    unsigned char ProtocolVersion;
}SSP_SETUP_REQUEST_DATA;



int  SSPEnviaComando(const SSP_PORT,SSP_COMMAND* cmd);

SSP_PORT OpenSSPPort(const char * port);



void CloseSSPPort(const SSP_PORT port);

clock_t GetClockMs(void);


#ifdef __cplusplus
}
#endif

#endif
