#include "include/command.h"
#include "include/packet.h"

int serialize_command(uint8_t *out, CommandPacket *packet) {
  out[0] = CommandPacketIdentifier;
  encode_uint32(packet->serialNumber, out + 1);
  encode_uint16(packet->ackId, out + 5);

  switch (packet->commandType) {
    case TypeOnOff: {
      encode_uint16(CommandPacket_TypeOnOff, out);
      out[9] = packet->onOff.on;
      out[10] = packet->onOff.relayIndex;

      return CommandPacketHeaderLength + 4;
    }
  }
}

int deserialize_command(CommandPacket *packet, const uint8_t *in) {
  packet->serialNumber = decode_uint32(in + 1);
  packet->ackId = decode_uint16(in + 5);

  switch (in[0]) {
    case CommandPacket_TypeOnOff: {
      packet->commandType = TypeOnOff;
      struct OnOff onOff = {
              .on = in[9],
              .relayIndex = in[10],
      };

      packet->onOff = onOff;
    }
  }

  return 0;
}