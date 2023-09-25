#ifndef ROMA_RFM_PROTOCOL_COMMAND_H
#define ROMA_RFM_PROTOCOL_COMMAND_H

#include <stdint.h>
#include <stdbool.h>

#define CommandPacketIdentifier 0x01
#define CommandPacketHeaderLength 10

#define CommandPacket_TypeOnOff 0x01

#define CommandPacket_Flag_isAck 0x80

typedef enum CommandType {
  TypeOnOff,
} CommandType;

typedef struct CommandPacket {
    uint32_t serialNumber;
    uint16_t ackId;
    uint8_t flags;
    CommandType commandType;
    union {
        struct CommandOnOff {
            bool on;
            uint8_t relayIndex;
        } onOff;
    };
} CommandPacket;

/**
 * Serialize a command packet
 * @param out The buffer to serialize into. It is up to the caller to make sure that the buffer is large enough to fit the packet as per the specification.
 * @param packet The packet to serialize
 * @return The amount of bytes serialized
 */
int serialize_command(uint8_t* out, CommandPacket* packet);

/**
 * Deserialize a command packet
 * @param packet The packet to deserialize into.
 * @param in The buffer to deserialize. It is up to the caller to make sure that the buffer is large enough to match the specification for this packet.
 * @return 0 if success.
 */
int deserialize_command(CommandPacket* packet, const uint8_t* in);

#endif //ROMA_RFM_PROTOCOL_COMMAND_H
