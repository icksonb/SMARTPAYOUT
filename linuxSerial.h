
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


int openport(char* PORTA);
void closeport(int port);
int readport(int port);
int EscreveSerial(unsigned char *dados, int len, int porta);
int NumBytesBuffer(void);
unsigned char ByteBuffer(void);