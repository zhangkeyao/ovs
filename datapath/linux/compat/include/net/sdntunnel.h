#ifndef __NET_SDNTUNNEL_WRAPPER_H
#define __NET_SDNTUNNEL_WRAPPER_H 1
#include <asm/byteorder.h>
/*
 * SDN Tunnel Header:
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |Version|  Type |     Length    |             ID1               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |              ID2              |             ID3               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * Version = 0x1
 *
 * Type = 0x1
 *
 * Length = 0x03
 *
 * ID1-ID3 = Tunnel ID
 *
 */

struct sdthdr {
#if defined(__LITTLE_ENDIAN_BITFIELD)
	__u8    type:4,
	        version:4;
#elif defined (__BIG_ENDIAN_BITFIELD)
	__u8    version:4,
	        type:4;
#else
#error	"Please fix <asm/byteorder.h>"
#endif
	__u8    len;
	__be16  sdt_id1;
	__be16  sdt_id2;
	__be16  sdt_id3;
};


#define SDT_HDR_VERSION     0x01
#define SDT_HDR_TYPE        0x01
#define SDT_HDR_TYPE_EXP    0x0F

#endif

