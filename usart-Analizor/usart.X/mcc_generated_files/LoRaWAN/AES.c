/*********************************************************************
 *
 *              Module for encrypting/decrypting data using 
 *              the AES (Rijndael) algorithm.
 *
 *********************************************************************
 * FileName:        AES.c
 * Dependencies:    none
 * Processor:       18FXXX/18CXXX
 * Assembler:       MPASMWIN 02.70.02 or higher
 * Linker:          MPLINK 2.33.00 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the "Company") for its PICmicro(r) Microcontroller is intended and
 * supplied to you, the Company's customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * Microchip Technology Inc. ("Microchip") licenses this software to 
 * you solely for use with Microchip products.  The software is owned 
 * by Microchip and is protected under applicable copyright laws.  
 * All rights reserved.
 *
 * You may not export or re-export Software, technical data, direct 
 * products thereof or any other items which would violate any applicable
 * export control laws and regulations including, but not limited to, 
 * those of the United States or United Kingdom.  You agree that it is
 * your responsibility to obtain copies of and to familiarize yourself
 * fully with these laws and regulations to avoid violation.
 *
 * SOFTWARE IS PROVIDED "AS IS."  MICROCHIP EXPRESSLY DISCLAIM ANY 
 * WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP
 * BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES,
 * LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF PROCUREMENT
 * OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS BY THIRD PARTIES
 * (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), ANY CLAIMS FOR 
 * INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS. 
 *
 *
 *
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * David Flowers        05/28/04    Initial Revision
 ********************************************************************/

/****************************** Headers *****************************/
#include <p18CXXX.h>
#include "AESdef.h"
#include "AES.h"

/****************************** Constants ***************************/
const unsigned char STable[] =
{
	0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76,
	0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0,
	0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15,
	0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75,
	0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84,
	0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF,
	0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8,
	0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2,
	0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73,
	0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB,
	0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79,
	0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08,
	0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A,
	0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E,
	0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF,
	0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16
};
#ifdef DECODE
const unsigned char SiTable[] =
{
	0x52,0x09,0x6A,0xD5,0x30,0x36,0xA5,0x38,0xBF,0x40,0xA3,0x9E,0x81,0xF3,0xD7,0xFB,
	0x7C,0xE3,0x39,0x82,0x9B,0x2F,0xFF,0x87,0x34,0x8E,0x43,0x44,0xC4,0xDE,0xE9,0xCB,
	0x54,0x7B,0x94,0x32,0xA6,0xC2,0x23,0x3D,0xEE,0x4C,0x95,0x0B,0x42,0xFA,0xC3,0x4E,
	0x08,0x2E,0xA1,0x66,0x28,0xD9,0x24,0xB2,0x76,0x5B,0xA2,0x49,0x6D,0x8B,0xD1,0x25,
	0x72,0xF8,0xF6,0x64,0x86,0x68,0x98,0x16,0xD4,0xA4,0x5C,0xCC,0x5D,0x65,0xB6,0x92,
	0x6C,0x70,0x48,0x50,0xFD,0xED,0xB9,0xDA,0x5E,0x15,0x46,0x57,0xA7,0x8D,0x9D,0x84,
	0x90,0xD8,0xAB,0x00,0x8C,0xBC,0xD3,0x0A,0xF7,0xE4,0x58,0x05,0xB8,0xB3,0x45,0x06,
	0xD0,0x2C,0x1E,0x8F,0xCA,0x3F,0x0F,0x02,0xC1,0xAF,0xBD,0x03,0x01,0x13,0x8A,0x6B,
	0x3A,0x91,0x11,0x41,0x4F,0x67,0xDC,0xEA,0x97,0xF2,0xCF,0xCE,0xF0,0xB4,0xE6,0x73,
	0x96,0xAC,0x74,0x22,0xE7,0xAD,0x35,0x85,0xE2,0xF9,0x37,0xE8,0x1C,0x75,0xDF,0x6E,
	0x47,0xF1,0x1A,0x71,0x1D,0x29,0xC5,0x89,0x6F,0xB7,0x62,0x0E,0xAA,0x18,0xBE,0x1B,
	0xFC,0x56,0x3E,0x4B,0xC6,0xD2,0x79,0x20,0x9A,0xDB,0xC0,0xFE,0x78,0xCD,0x5A,0xF4,
	0x1F,0xDD,0xA8,0x33,0x88,0x07,0xC7,0x31,0xB1,0x12,0x10,0x59,0x27,0x80,0xEC,0x5F,
	0x60,0x51,0x7F,0xA9,0x19,0xB5,0x4A,0x0D,0x2D,0xE5,0x7A,0x9F,0x93,0xC9,0x9C,0xEF,
	0xA0,0xE0,0x3B,0x4D,0xAE,0x2A,0xF5,0xB0,0xC8,0xEB,0xBB,0x3C,0x83,0x53,0x99,0x61,
	0x17,0x2B,0x04,0x7E,0xBA,0x77,0xD6,0x26,0xE1,0x69,0x14,0x63,0x55,0x21,0x0C,0x7D
};

const unsigned char x1[] =
{
	0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,
	0x10,0x12,0x14,0x16,0x18,0x1A,0x1C,0x1E,
	0x20,0x22,0x24,0x26,0x28,0x2A,0x2C,0x2E,
	0x30,0x32,0x34,0x36,0x38,0x3A,0x3C,0x3E,
	0x40,0x42,0x44,0x46,0x48,0x4A,0x4C,0x4E,
	0x50,0x52,0x54,0x56,0x58,0x5A,0x5C,0x5E,
	0x60,0x62,0x64,0x66,0x68,0x6A,0x6C,0x6E,
	0x70,0x72,0x74,0x76,0x78,0x7A,0x7C,0x7E,
	0x80,0x82,0x84,0x86,0x88,0x8A,0x8C,0x8E,
	0x90,0x92,0x94,0x96,0x98,0x9A,0x9C,0x9E,
	0xA0,0xA2,0xA4,0xA6,0xA8,0xAA,0xAC,0xAE,
	0xB0,0xB2,0xB4,0xB6,0xB8,0xBA,0xBC,0xBE,
	0xC0,0xC2,0xC4,0xC6,0xC8,0xCA,0xCC,0xCE,
	0xD0,0xD2,0xD4,0xD6,0xD8,0xDA,0xDC,0xDE,
	0xE0,0xE2,0xE4,0xE6,0xE8,0xEA,0xEC,0xEE,
	0xF0,0xF2,0xF4,0xF6,0xF8,0xFA,0xFC,0xFE,
	0x1B,0x19,0x1F,0x1D,0x13,0x11,0x17,0x15,
	0x0B,0x09,0x0F,0x0D,0x03,0x01,0x07,0x05,
	0x3B,0x39,0x3F,0x3D,0x33,0x31,0x37,0x35,
	0x2B,0x29,0x2F,0x2D,0x23,0x21,0x27,0x25,
	0x5B,0x59,0x5F,0x5D,0x53,0x51,0x57,0x55,
	0x4B,0x49,0x4F,0x4D,0x43,0x41,0x47,0x45,
	0x7B,0x79,0x7F,0x7D,0x73,0x71,0x77,0x75,
	0x6B,0x69,0x6F,0x6D,0x63,0x61,0x67,0x65,
	0x9B,0x99,0x9F,0x9D,0x93,0x91,0x97,0x95,
	0x8B,0x89,0x8F,0x8D,0x83,0x81,0x87,0x85,
	0xBB,0xB9,0xBF,0xBD,0xB3,0xB1,0xB7,0xB5,
	0xAB,0xA9,0xAF,0xAD,0xA3,0xA1,0xA7,0xA5,
	0xDB,0xD9,0xDF,0xDD,0xD3,0xD1,0xD7,0xD5,
	0xCB,0xC9,0xCF,0xCD,0xC3,0xC1,0xC7,0xC5,
	0xFB,0xF9,0xFF,0xFD,0xF3,0xF1,0xF7,0xF5,
	0xEB,0xE9,0xEF,0xED,0xE3,0xE1,0xE7,0xE5
};
const unsigned char x2[] =
{
	0x00,0x04,0x08,0x0C,0x10,0x14,0x18,0x1C,
	0x20,0x24,0x28,0x2C,0x30,0x34,0x38,0x3C,
	0x40,0x44,0x48,0x4C,0x50,0x54,0x58,0x5C,
	0x60,0x64,0x68,0x6C,0x70,0x74,0x78,0x7C,
	0x80,0x84,0x88,0x8C,0x90,0x94,0x98,0x9C,
	0xA0,0xA4,0xA8,0xAC,0xB0,0xB4,0xB8,0xBC,
	0xC0,0xC4,0xC8,0xCC,0xD0,0xD4,0xD8,0xDC,
	0xE0,0xE4,0xE8,0xEC,0xF0,0xF4,0xF8,0xFC,
	0x1B,0x1F,0x13,0x17,0x0B,0x0F,0x03,0x07,
	0x3B,0x3F,0x33,0x37,0x2B,0x2F,0x23,0x27,
	0x5B,0x5F,0x53,0x57,0x4B,0x4F,0x43,0x47,
	0x7B,0x7F,0x73,0x77,0x6B,0x6F,0x63,0x67,
	0x9B,0x9F,0x93,0x97,0x8B,0x8F,0x83,0x87,
	0xBB,0xBF,0xB3,0xB7,0xAB,0xAF,0xA3,0xA7,
	0xDB,0xDF,0xD3,0xD7,0xCB,0xCF,0xC3,0xC7,
	0xFB,0xFF,0xF3,0xF7,0xEB,0xEF,0xE3,0xE7,
	0x36,0x32,0x3E,0x3A,0x26,0x22,0x2E,0x2A,
	0x16,0x12,0x1E,0x1A,0x06,0x02,0x0E,0x0A,
	0x76,0x72,0x7E,0x7A,0x66,0x62,0x6E,0x6A,
	0x56,0x52,0x5E,0x5A,0x46,0x42,0x4E,0x4A,
	0xB6,0xB2,0xBE,0xBA,0xA6,0xA2,0xAE,0xAA,
	0x96,0x92,0x9E,0x9A,0x86,0x82,0x8E,0x8A,
	0xF6,0xF2,0xFE,0xFA,0xE6,0xE2,0xEE,0xEA,
	0xD6,0xD2,0xDE,0xDA,0xC6,0xC2,0xCE,0xCA,
	0x2D,0x29,0x25,0x21,0x3D,0x39,0x35,0x31,
	0x0D,0x09,0x05,0x01,0x1D,0x19,0x15,0x11,
	0x6D,0x69,0x65,0x61,0x7D,0x79,0x75,0x71,
	0x4D,0x49,0x45,0x41,0x5D,0x59,0x55,0x51,
	0xAD,0xA9,0xA5,0xA1,0xBD,0xB9,0xB5,0xB1,
	0x8D,0x89,0x85,0x81,0x9D,0x99,0x95,0x91,
	0xED,0xE9,0xE5,0xE1,0xFD,0xF9,0xF5,0xF1,
	0xCD,0xC9,0xC5,0xC1,0xDD,0xD9,0xD5,0xD1
};
const unsigned char x3[] =
{
	0x00,0x08,0x10,0x18,0x20,0x28,0x30,0x38,
	0x40,0x48,0x50,0x58,0x60,0x68,0x70,0x78,
	0x80,0x88,0x90,0x98,0xA0,0xA8,0xB0,0xB8,
	0xC0,0xC8,0xD0,0xD8,0xE0,0xE8,0xF0,0xF8,
	0x1B,0x13,0x0B,0x03,0x3B,0x33,0x2B,0x23,
	0x5B,0x53,0x4B,0x43,0x7B,0x73,0x6B,0x63,
	0x9B,0x93,0x8B,0x83,0xBB,0xB3,0xAB,0xA3,
	0xDB,0xD3,0xCB,0xC3,0xFB,0xF3,0xEB,0xE3,
	0x36,0x3E,0x26,0x2E,0x16,0x1E,0x06,0x0E,
	0x76,0x7E,0x66,0x6E,0x56,0x5E,0x46,0x4E,
	0xB6,0xBE,0xA6,0xAE,0x96,0x9E,0x86,0x8E,
	0xF6,0xFE,0xE6,0xEE,0xD6,0xDE,0xC6,0xCE,
	0x2D,0x25,0x3D,0x35,0x0D,0x05,0x1D,0x15,
	0x6D,0x65,0x7D,0x75,0x4D,0x45,0x5D,0x55,
	0xAD,0xA5,0xBD,0xB5,0x8D,0x85,0x9D,0x95,
	0xED,0xE5,0xFD,0xF5,0xCD,0xC5,0xDD,0xD5,
	0x6C,0x64,0x7C,0x74,0x4C,0x44,0x5C,0x54,
	0x2C,0x24,0x3C,0x34,0x0C,0x04,0x1C,0x14,
	0xEC,0xE4,0xFC,0xF4,0xCC,0xC4,0xDC,0xD4,
	0xAC,0xA4,0xBC,0xB4,0x8C,0x84,0x9C,0x94,
	0x77,0x7F,0x67,0x6F,0x57,0x5F,0x47,0x4F,
	0x37,0x3F,0x27,0x2F,0x17,0x1F,0x07,0x0F,
	0xF7,0xFF,0xE7,0xEF,0xD7,0xDF,0xC7,0xCF,
	0xB7,0xBF,0xA7,0xAF,0x97,0x9F,0x87,0x8F,
	0x5A,0x52,0x4A,0x42,0x7A,0x72,0x6A,0x62,
	0x1A,0x12,0x0A,0x02,0x3A,0x32,0x2A,0x22,
	0xDA,0xD2,0xCA,0xC2,0xFA,0xF2,0xEA,0xE2,
	0x9A,0x92,0x8A,0x82,0xBA,0xB2,0xAA,0xA2,
	0x41,0x49,0x51,0x59,0x61,0x69,0x71,0x79,
	0x01,0x09,0x11,0x19,0x21,0x29,0x31,0x39,
	0xC1,0xC9,0xD1,0xD9,0xE1,0xE9,0xF1,0xF9,
	0x81,0x89,0x91,0x99,0xA1,0xA9,0xB1,0xB9
};
#endif

#define BLOCKSIZE 16

/****************************** Variables ***************************/
static unsigned char _roundCounter;
static unsigned char _rcon;

/****************************** Macros ******************************/
#define xtime(a) (((a)<0x80)?(a)<<1:(((a)<<1)^0x1b) )
/* if(a<0x80){a<<=1;}else{a=(a<<1)^0x1b;}

/****************************** Function Prototypes *****************/
void EncodeShiftRow(unsigned char* block);
void DecodeShiftRow(unsigned char* stateTable);
void EncKeySchedule(unsigned char* key);
void DecKeySchedule(unsigned char* key);

/****************************** Functions ***************************/

/*********************************************************************
 * Function:        void AESEncode(unsigned char* block, unsigned char* key)
 *
 * PreCondition:    None
 *
 * Input:           block - 16 byte block of data to be encrypted 
 *						    (padded if needed)
 *
 * Output:          None
 *
 * Side Effects:    block values changed
 *
 * Stack Requirements: None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/

#ifdef ENCODE
void AESEncode(unsigned char* block, unsigned char* key)
{
	unsigned char i;
	unsigned char temp;

	/* initiate round counter = 10 */
	_roundCounter = 10;

	_rcon = 0x01;

	/* key addition */
	for(i=0;i<BLOCKSIZE;i++)
	{
		block[i] ^= key[i];	
	}

	do
	{

		/* s table substitution */
		for(i=0;i<BLOCKSIZE;i++)
		{
			block[i]=STable[block[i]];
		}

		/*   encode shift row */
		EncodeShiftRow(block);

		/*   if round counter != 1 */
		if(_roundCounter != 1)
		{
			unsigned char aux,aux1,aux2,aux3;
			/*     mix column */
			for(i=0;i<16;i+=4)
			{
				aux1= block[i+0] ^ block[i+1];
				aux3= block[i+2]^block[i+3];
				aux = aux1 ^ aux3;
				aux2= block[i+2]^block[i+1];

				aux1 = xtime(aux1);
				aux2 = xtime(aux2);
				aux3 = xtime(aux3);

				block[i+0]= aux^aux1^block[i+0];
				block[i+1]= aux^aux2^block[i+1];
				block[i+2]= aux^aux3^block[i+2];
				block[i+3]= block[i+0]^block[i+1]^block[i+2]^aux;
			}
		}
		/*   encode key schedule */ 
		EncKeySchedule(key);

		/*   key addition */
		for(i=0;i<BLOCKSIZE;i++)
		{
			block[i] ^= key[i];
		}
		
		_roundCounter--;
	}
	while(_roundCounter !=0);
}
#endif

/*********************************************************************
* Function: void EncKeySchedule(unsigned char* key)
*
* PreCondition:
*
* Input: key - array of the key data
*
* Output: 
*
* Side Effects: values of the key changed
*
* Overview: None
*
* Note: None
********************************************************************/
#ifdef ENCODE
#define ENC_KEY_NEEDED
#endif
#ifdef DECODE
#ifdef calcKey
#define ENC_KEY_NEEDED
#endif
#endif
#ifdef ENC_KEY_NEEDED
void EncKeySchedule(unsigned char* key)
{
	/* column 1 */
	key[0]^=STable[key[13]];
	key[1]^=STable[key[14]];
	key[2]^=STable[key[15]];
	key[3]^=STable[key[12]];

	key[0]^=_rcon;
	_rcon = xtime(_rcon);

	/* column 2 */
	key[4]^=key[0];
	key[5]^=key[1];
	key[6]^=key[2];
	key[7]^=key[3];

	/* column 3 */
	key[8]^=key[4];
	key[9]^=key[5];
	key[10]^=key[6];
	key[11]^=key[7];

	/* column 4 */
	key[12]^=key[8];
	key[13]^=key[9];
	key[14]^=key[10];
	key[15]^=key[11];
}
#endif


/*********************************************************************
* Function: void EncodeShiftRow(unsigned char* stateTable)
*
* PreCondition:
*
* Input: stateTable - the data needing to be shifted
*
* Output: 
*
* Side Effects: values of the inputed data changed
*
* Overview: None
*
* Note: None
********************************************************************/
#ifdef ENCODE
void EncodeShiftRow(unsigned char* stateTable)
{
	unsigned char temp;

	/* first row (row 0) unchanged */

	/* second row (row 1) shifted left by one */
	temp=stateTable[1];
	stateTable[1]=stateTable[5];
	stateTable[5]=stateTable[9];
	stateTable[9]=stateTable[13];
	stateTable[13]=temp;
	
	/* third row (row 2) shifted left by two */
	temp=stateTable[2];
	stateTable[2]=stateTable[10];
	stateTable[10]=temp;
	temp=stateTable[14];
	stateTable[14]=stateTable[6];
	stateTable[6]=temp;

	/* fourth row (row 3) shifted left by three (or right by one) */
	temp=stateTable[3];
	stateTable[3]=stateTable[15];
	stateTable[15]=stateTable[11];
	stateTable[11]=stateTable[7];
	stateTable[7]=temp;
}
#endif

/*********************************************************************
 * Function:        void AESCalcDecodeKey(unsigned char* key)
 *
 * PreCondition:    None
 *
 * Input:           key - array of the values of the 128 bit key
 *
 * Output:          None
 *
 * Side Effects:    key goes from encoding key to decoding key
 *
 * Stack Requirements: None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
#ifdef calcKey
void AESCalcDecodeKey(unsigned char* key)
{
	_roundCounter = 10;
	
	_rcon=0x01;
	do
	{	
		EncKeySchedule(key);
		_roundCounter--;
	}
	while(_roundCounter>0);
}
#endif

/*********************************************************************
 * Function:        void AESDecode(unsigned char* block, unsigned char* key)
 *
 * PreCondition:    None
 *
 * Input:           block - 16 byte block of data to be deciphered 
 *
 * Output:          None
 *
 * Side Effects:    block values changed
 *
 * Stack Requirements: None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
#ifdef DECODE
void AESDecode(unsigned char* block, unsigned char* key)
{
	unsigned char i;
	unsigned char b[BLOCKSIZE];

	/* reconstruct key */
	i=1;

	_rcon = 0x36;

	/* initiate round counter = 10 */
	_roundCounter = 10;

	/* key addition */
	for(i=0;i<BLOCKSIZE;i++)
	{
		block[i] ^= key[i];
	}
	Nop();

	do
	{

		if( _roundCounter != 10)
		{
			/* inverse mix column */
			/*     mix column */

			{
				unsigned char temp0,temp1,temp2,temp3;
				for(i=0;i<16;i+=4)
				{
					temp3=x3[block[i+0x00]]^x3[block[i+0x01]]^x3[block[i+0x02]]^x3[block[i+0x03]]^block[i+0x00]^block[i+0x01]^block[i+0x02]^block[i+0x03];
					temp0=x2[block[i+0x00]]^x1[block[i+0x00]]
							  ^x1[block[i+0x01]]
							  ^x2[block[i+0x02]]
							  ^temp3^block[i+0x00];
					temp1=x2[block[i+0x01]]^x1[block[i+0x01]]
							  ^x1[block[i+0x02]]
							  ^x2[block[i+0x03]]
							  ^temp3^block[i+0x01];
					temp2=x2[block[i+0x02]]^x1[block[i+0x02]]
							  ^x1[block[i+0x03]]
							  ^x2[block[i+0x00]]
							  ^temp3^block[i+0x02];
					temp3^=x2[block[i+0x03]]^x1[block[i+0x03]]
							  ^x1[block[i+0x00]]
							  ^x2[block[i+0x01]]
							  ^block[i+0x03];
					block[i+0]=temp0;
					block[i+1]=temp1;
					block[i+2]=temp2;
					block[i+3]=temp3;
				}
			}
			
		}

		/* s table substitution */
		for(i=0;i<BLOCKSIZE;i++)
		{
			block[i]=SiTable[block[i]];
		}

		/* decode shift row */
		DecodeShiftRow(block);

		/* decode key schedule */ 
		DecKeySchedule(key);

		for(i=0;i<BLOCKSIZE;i++)
		{
			block[i] ^= key[i];
		}

		_roundCounter--;
	}
	while( _roundCounter !=0);
}

/*********************************************************************
* Function: void DecodeShiftRow(unsigned char* stateTable)
*
* PreCondition:
*
* Input: stateTable - array of data to be shifted
*
* Output: 
*
* Side Effects: values of the inputed data changed
*
* Overview: None
*
* Note: None
********************************************************************/
void DecodeShiftRow(unsigned char* stateTable)
{
	unsigned char temp;

	/* first row (row 0) unchanged */

	/* second row (row 1) shifted left by three (or right by one) */
	temp=stateTable[1];
	stateTable[1]=stateTable[13];
	stateTable[13]=stateTable[9];
	stateTable[9]=stateTable[5];
	stateTable[5]=temp;
	
	/* third row (row 2) shifted left by two */
	temp=stateTable[2];
	stateTable[2]=stateTable[10];
	stateTable[10]=temp;
	temp=stateTable[14];
	stateTable[14]=stateTable[6];
	stateTable[6]=temp;

	/* fourth row (row 3) shifted left by one */
	temp=stateTable[7];
	stateTable[7]=stateTable[11];
	stateTable[11]=stateTable[15];
	stateTable[15]=stateTable[3];
	stateTable[3]=temp;
}

/*********************************************************************
* Function: void DecKeySchedule(unsigned char* key)
*
* PreCondition:
*
* Input: key - array of the key data
*
* Output: 
*
* Side Effects: values of the key changed to next key in decrypt
*
* Overview: None
*
* Note: None
********************************************************************/
void DecKeySchedule(unsigned char* key)
{
	/* column 4 */
	key[12]^=key[8];
	key[13]^=key[9];
	key[14]^=key[10];
	key[15]^=key[11];
	
	/* column 3 */
	key[8]^=key[4];
	key[9]^=key[5];
	key[10]^=key[6];
	key[11]^=key[7];

	/* column 2 */
	key[4]^=key[0];
	key[5]^=key[1];
	key[6]^=key[2];
	key[7]^=key[3];

	/* column 1 */
	key[0]^=STable[key[13]];
	key[1]^=STable[key[14]];
	key[2]^=STable[key[15]];
	key[3]^=STable[key[12]];

	key[0]^=_rcon;
	if(_rcon &0x01)
	{
		_rcon = 0x80;
	}
	else
	{
		_rcon >>= 1;
	}

}
#endif
