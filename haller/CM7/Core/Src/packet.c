#include "packet.h"
#include <string.h>
#include <stdint.h>

void PacketFromString(char* dataBuffer, Packet* packetPtr){
    packetPtr->commandID = *(uint8_t*)dataBuffer;
    dataBuffer += sizeof(packetPtr->commandID);

    packetPtr->dataLength = *(uint8_t*)dataBuffer;
    dataBuffer += sizeof(packetPtr->dataLength);

    for (uint8_t i = 0; i < packetPtr->dataLength; i++){
        packetPtr->data[i] = *(uint8_t*)dataBuffer;
        dataBuffer += sizeof(packetPtr->data[i]);
    }
}

void StringFromPacket(Packet* packetPtr, char* destBuffer){
    char id = (char)packetPtr->commandID;
    char size = (char)packetPtr->dataLength;

    *destBuffer = id;
    destBuffer += sizeof(id);
    *destBuffer = size;
    destBuffer += sizeof(size);

    strcpy(destBuffer, &packetPtr->data);
}
