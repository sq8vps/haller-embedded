#ifndef INC_PACKET_H_
#define INC_PACKET_H_

#include <stdint.h>

#define MAX_DATA_LENGTH 252

typedef struct {
    uint8_t commandID;
    uint8_t dataLength;
    uint8_t data[MAX_DATA_LENGTH];
} Packet;

void PacketFromString(char* dataBuffer, Packet* packetPtr);

void StringFromPacket(Packet* packetPtr, char* destBuffer);


#endif /* INC_PACKET_H_ */
