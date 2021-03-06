/*
 * nRF24AP1.h
 * 
 * Copyright 2013 Charles Wolf <Cwolf@localhost.localdomain>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#ifndef _nRF24AP1_H_
#define _nRF24AP1_H_

#ifndef UCHAR
	#define UCHAR unsigned char
#endif

#ifndef TRUE
	#define TRUE	1
#endif

#ifndef FALSE
	#define FALSE 	0
#endif
 

//Define the pins used for the nRF24AP1
#define nRF24AP1_DIRECTION		DDRD
#define nRF24AP1_PORT			PORTD
#define	nRF24AP1_RESET_PIN 		PD2			//Active Low
#define	nRF24AP1_RTS_PIN		PD5
#define	nRF24AP1_SUSPEND_PIN	PD3			//Active Low
#define	nRF24AP1_SLEEP_PIN		PD4
#define	nRF24AP1_TX_PIN			PD6
#define	nRF24AP1_RX_PIN			PD7

// Protocol Definitions
#define MESG_TX_SYNC			((UCHAR)0xA4)
#define MESG_RX_SYNC			((UCHAR)0xA5)
#define MESG_SIZE_OFFSET		((UCHAR)1)   
#define MESG_ID_OFFSET			((UCHAR)2)     
#define MESG_SYNC_SIZE			((UCHAR)1)
#define MESG_SIZE_SIZE			((UCHAR)1)
#define MESG_ID_SIZE			((UCHAR)1)
#define MESG_CHECKSUM_SIZE		((UCHAR)1)
#define MESG_MAX_DATA_SIZE		((UCHAR)17)
#define MESG_HEADER_SIZE		(MESG_SYNC_SIZE + MESG_SIZE_SIZE + MESG_ID_SIZE)
#define MESG_DATA_OFFSET		MESG_HEADER_SIZE 
#define MESG_FRAME_SIZE			(MESG_HEADER_SIZE + MESG_CHECKSUM_SIZE)
#define MESG_MAX_SIZE			(MESG_MAX_DATA_SIZE + MESG_FRAME_SIZE)

// ANT Messages
#define MESG_INVALID_ID                   ((UCHAR)0x00)
#define MESG_EVENT_ID                     ((UCHAR)0x01)
#define MESG_VERSION_ID                   ((UCHAR)0x3E)  // protocol library version
#define MESG_RESPONSE_EVENT_ID            ((UCHAR)0x40)
#define MESG_UNASSIGN_CHANNEL_ID          ((UCHAR)0x41)
#define MESG_ASSIGN_CHANNEL_ID            ((UCHAR)0x42)
#define MESG_CHANNEL_MESG_PERIOD_ID       ((UCHAR)0x43)
#define MESG_CHANNEL_SEARCH_TIMEOUT_ID    ((UCHAR)0x44)
#define MESG_CHANNEL_RADIO_FREQ_ID        ((UCHAR)0x45)
#define MESG_NETWORK_KEY_ID               ((UCHAR)0x46)
#define MESG_RADIO_TX_POWER_ID            ((UCHAR)0x47)
#define MESG_RADIO_CW_MODE_ID             ((UCHAR)0x48)
#define MESG_SEARCH_WAVEFORM_ID           ((UCHAR)0x49)
#define MESG_SYSTEM_RESET_ID              ((UCHAR)0x4A)
#define MESG_OPEN_CHANNEL_ID              ((UCHAR)0x4B)
#define MESG_CLOSE_CHANNEL_ID             ((UCHAR)0x4C)
#define MESG_REQUEST_ID                   ((UCHAR)0x4D)
#define MESG_BROADCAST_DATA_ID            ((UCHAR)0x4E)
#define MESG_ACKNOWLEDGED_DATA_ID         ((UCHAR)0x4F)
#define MESG_BURST_DATA_ID                ((UCHAR)0x50)
#define MESG_CHANNEL_ID_ID                ((UCHAR)0x51)
#define MESG_CHANNEL_STATUS_ID            ((UCHAR)0x52)
#define MESG_RADIO_CW_INIT_ID             ((UCHAR)0x53)
#define MESG_CAPABILITIES_ID              ((UCHAR)0x54)
#define MESG_NVM_DATA_ID                  ((UCHAR)0x56)
#define MESG_NVM_CMD_ID                   ((UCHAR)0x57)
#define MESG_NVM_STRING_ID                ((UCHAR)0x58)
#define MESG_ID_LIST_ADD_ID               ((UCHAR)0x59)
#define MESG_ID_LIST_CONFIG_ID            ((UCHAR)0x5A)
#define MESG_OPEN_RX_SCAN_ID              ((UCHAR)0x5B)
#define MESG_EXT_CHANNEL_RADIO_FREQ_ID    ((UCHAR)0x5C)
#define MESG_EXT_BROADCAST_DATA_ID        ((UCHAR)0x5D)
#define MESG_EXT_ACKNOWLEDGED_DATA_ID     ((UCHAR)0x5E)
#define MESG_EXT_BURST_DATA_ID            ((UCHAR)0x5F)
#define MESG_CHANNEL_RADIO_TX_POWER_ID    ((UCHAR)0x60)
#define MESG_GET_SERIAL_NUM_ID            ((UCHAR)0x61)
#define MESG_GET_TEMP_CAL_ID              ((UCHAR)0x62)
#define MESG_SET_LP_SEARCH_TIMEOUT_ID     ((UCHAR)0x63)
#define MESG_SET_TX_SEARCH_ON_NEXT_ID     ((UCHAR)0x64)
#define MESG_SERIAL_NUM_SET_CHANNEL_ID_ID ((UCHAR)0x65)
#define MESG_RX_EXT_MESGS_ENABLE_ID       ((UCHAR)0x66)
#define MESG_RADIO_CONFIG_ALWAYS_ID       ((UCHAR)0x67)
#define MESG_ENABLE_LED_FLASH_ID          ((UCHAR)0x68)
#define MESG_AGC_CONFIG_ID                ((UCHAR)0x6A)
#define MESG_READ_SEGA_ID                 ((UCHAR)0xA0)
#define MESG_SEGA_CMD_ID                  ((UCHAR)0xA1)
#define MESG_SEGA_DATA_ID                 ((UCHAR)0xA2)
#define MESG_SEGA_ERASE_ID                ((UCHAR)0XA3)   
#define MESG_SEGA_WRITE_ID                ((UCHAR)0XA4)
// Unused                                 ((UCHAR)0xA5) 
#define MESG_SEGA_LOCK_ID                 ((UCHAR)0xA6)
#define MESG_FUSECHECK_ID                 ((UCHAR)0xA7)
#define MESG_UARTREG_ID                   ((UCHAR)0XA8)
#define MESG_MAN_TEMP_ID                  ((UCHAR)0xA9)
#define MESG_BIST_ID                      ((UCHAR)0XAA)
#define MESG_SELFERASE_ID                 ((UCHAR)0XAB)
#define MESG_SET_MFG_BITS_ID              ((UCHAR)0xAC)
#define MESG_UNLOCK_INTERFACE_ID          ((UCHAR)0xAD)
#define MESG_IO_STATE_ID                  ((UCHAR)0xB0)
#define MESG_CFG_STATE_ID                 ((UCHAR)0xB1)
#define MESG_RSSI_ID                      ((UCHAR)0xC0)
#define MESG_RSSI_BROADCAST_DATA_ID       ((UCHAR)0xC1)
#define MESG_RSSI_ACKNOWLEDGED_DATA_ID    ((UCHAR)0xC2)
#define MESG_RSSI_BURST_DATA_ID           ((UCHAR)0xC3)
#define MESG_RSSI_SEARCH_THRESHOLD_ID     ((UCHAR)0xC4)
#define MESG_BTH_BROADCAST_DATA_ID        ((UCHAR)0xD0)
#define MESG_BTH_ACKNOWLEDGED_DATA_ID     ((UCHAR)0xD1)
#define MESG_BTH_BURST_DATA_ID            ((UCHAR)0xD2)
#define MESG_BTH_EXT_BROADCAST_DATA_ID    ((UCHAR)0xD3)
#define MESG_BTH_EXT_ACKNOWLEDGED_DATA_ID ((UCHAR)0xD4)
#define MESG_BTH_EXT_BURST_DATA_ID        ((UCHAR)0xD5)

//ANT Message Lengths
#define MESG_INVALID_SIZE                 ((UCHAR)0)
#define MESG_RESPONSE_EVENT_SIZE          ((UCHAR)3)
#define MESG_CHANNEL_STATUS_SIZE          ((UCHAR)2)
#define MESG_VERSION_SIZE                 ((UCHAR)9)
#define MESG_UNASSIGN_CHANNEL_SIZE        ((UCHAR)1)
#define MESG_ASSIGN_CHANNEL_SIZE          ((UCHAR)3)
#define MESG_CHANNEL_ID_SIZE              ((UCHAR)5)
#define MESG_CHANNEL_MESG_PERIOD_SIZE     ((UCHAR)3)
#define MESG_CHANNEL_SEARCH_TIMEOUT_SIZE  ((UCHAR)2)
#define MESG_CHANNEL_RADIO_FREQ_SIZE      ((UCHAR)2)
#define MESG_NETWORK_KEY_SIZE             ((UCHAR)9)
#define MESG_RADIO_TX_POWER_SIZE          ((UCHAR)2)
#define MESG_RADIO_CW_MODE_SIZE           ((UCHAR)3)
#define MESG_RADIO_CW_INIT_SIZE           ((UCHAR)1)
#define MESG_SEARCH_WAVEFORM_SIZE         ((UCHAR)3)
#define MESG_SYSTEM_RESET_SIZE            ((UCHAR)1)
#define MESG_OPEN_CHANNEL_SIZE            ((UCHAR)1)
#define MESG_CLOSE_CHANNEL_SIZE           ((UCHAR)1)
#define MESG_REQUEST_SIZE                 ((UCHAR)2)
#define MESG_CAPABILITIES_SIZE            ((UCHAR)6)
#define MESG_DATA_SIZE                    ((UCHAR)9)
#define MESG_NVM_DATA_SIZE                ((UCHAR)10)
#define MESG_NVM_CMD_SIZE                 ((UCHAR)3)
#define MESG_NVM_STRING_SIZE              ((UCHAR)9)
#define MESG_ID_LIST_ADD_SIZE             ((UCHAR)6)
#define MESG_ID_LIST_CONFIG_SIZE          ((UCHAR)3)
#define MESG_OPEN_RX_SCAN_SIZE            ((UCHAR)1)
#define MESG_EXT_CHANNEL_RADIO_FREQ_SIZE  ((UCHAR)3)
#define MESG_EXT_DATA_SIZE                ((UCHAR)13)
#define MESG_RADIO_CONFIG_ALWAYS_SIZE     ((UCHAR)2)
#define MESG_RX_EXT_MESGS_ENABLE_SIZE     ((UCHAR)2)
#define MESG_SET_TX_SEARCH_ON_NEXT_SIZE   ((UCHAR)2)
#define MESG_SET_LP_SEARCH_TIMEOUT_SIZE   ((UCHAR)2)
#define MESG_SERIAL_NUM_SET_CHANNEL_ID_SIZE ((UCHAR)3)
#define MESG_ENABLE_LED_FLASH_SIZE        ((UCHAR)2)
#define MESG_GET_SERIAL_NUM_SIZE          ((UCHAR)4)
#define MESG_GET_TEMP_CAL_SIZE            ((UCHAR)4)
#define MESG_AGC_CONFIG_SIZE              ((UCHAR)2)
#define MESG_READ_SEGA_SIZE               ((UCHAR)2)
#define MESG_SEGA_CMD_SIZE                ((UCHAR)3)
#define MESG_SEGA_DATA_SIZE               ((UCHAR)10)
#define MESG_SEGA_ERASE_SIZE              ((UCHAR)0)
#define MESG_SEGA_WRITE_SIZE              ((UCHAR)3)
#define MESG_SEGA_LOCKED_SIZE             ((UCHAR)1)
#define MESG_SEGA_LOCK_SIZE               ((UCHAR)0)
#define MESG_FUSECHECK_SIZE               ((UCHAR)1)
#define MESG_UARTREG_SIZE                 ((UCHAR)2)
#define MESG_MAN_TEMP_SIZE                ((UCHAR)2)
#define MESG_BIST_SIZE                    ((UCHAR)6)
#define MESG_SELFERASE_SIZE               ((UCHAR)2)
#define MESG_SET_MFG_BITS_SIZE            ((UCHAR)2)
#define MESG_UNLOCK_INTERFACE_SIZE        ((UCHAR)1)
#define MESG_IO_STATE_SIZE                ((UCHAR)2)
#define MESG_CFG_STATE_SIZE               ((UCHAR)2)
#define MESG_RSSI_SIZE                    ((UCHAR)3)
#define MESG_RSSI_DATA_SIZE               ((UCHAR)17)
#define MESG_RSSI_SEARCH_THRESHOLD_SIZE   ((UCHAR)2)


#define CHAN0      0
#define CHAN1      1
#define NET0      0
#define NET1      1
#define TIMEOUT   12

//Garmin specific configurations
#define FREQ 			0x39 //  garmin radio frequency
#define PERIOD      	8070 // Garmin search period
#define NETWORK_KEY		"KEY GOES HERE" // Garmin HRM
#define DEVICETYPE		120



void nRF24AP1_init(void);
UCHAR checkSum(UCHAR *data, int length);
void reset_msg(void);
void assignch(void);
void assignch1(void);
void assignch2(void);
void assignch3(void);
void assignch4(void);
void timeout(void);
void frequency(void);
void channel_period(void);
void open_channel(void);
void send_ant_packet( UCHAR msgID, UCHAR argCnt, ...);
void ant_hr_config(void);
int get_ant_msg(int max_wait, UCHAR *MSG);

#endif
