/* CRCTABLE 1.0  Public Domain by Celso Minnitti, Jr  Feb-06-94 	*/
/* This program will generate the crc16_table and CRC32_table		*/
/* that are used by CMCRC.ASM										*/

#include <stdio.h>
#define CRC32_POLYNOMIAL 0xEDB88320
#define CRC16_POLYNOMIAL 0xA001

void main()
{
	unsigned long crc32Table[256];
	unsigned int crc16Table[256];
	unsigned int crc;
	unsigned long crc32;
	int i, j;

	printf("CRCTABLE 1.0  Public Domain by Celso Minnitti, Jr  Feb-06-94\n\n");

	for (i = 0; i < 256; i++) {
		crc = i;
		for (j = 8; j > 0; j--) {
			if (crc & 1)
				crc = (crc >> 1) ^ CRC16_POLYNOMIAL;
			else
				crc >>= 1;
		}
		crc16Table[i] = crc;
	}

	printf("\ncrc16_table\tlabel\tword");
	for (i = 0; i < 256; i++) {
		if (!(i%32) && i) printf("\n; %Xh", i);
		if (!(i%8)) printf("\n\tdw ");
		if (i%8 != 7) printf("0%04Xh, ", crc16Table[i]);
		else
			printf("0%04Xh", crc16Table[i]);
	}
	printf("\n");

	for (i = 0; i < 256; i++) {
		crc32 = i;
		for (j = 8; j > 0; j--) {
			if (crc32 & 1)
				crc32 = (crc32 >> 1) ^ CRC32_POLYNOMIAL;
			else
				crc32 >>= 1;
		}
		crc32Table[i] = crc32;
	}

	printf("\ncrc32_table\tlabel\tdword");
	for (i = 0; i < 256; i++) {
		if (!(i%16) && i) printf("\n; %Xh", i);
		if (!(i%4)) printf("\n\tdd ");
		if (i%4 != 3) printf("0%08lXh, ", crc32Table[i]);
		else
			printf("0%08lXh", crc32Table[i]);
	}
}
