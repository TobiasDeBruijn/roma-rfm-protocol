#include "include/settings.h"
#include "include/packet.h"

int serialize_settings(uint8_t* out, SettingsPacket* packet) {
  out[0] = SettingsPacketIdentifier;
  encode_uint32(packet->serialNumber, out + 1);
  encode_uint16(packet->ackId, out + 5);
  out[7] = packet->flags;

  switch(packet->settingsType) {
    case SettingsTypeOnOff: {
      out[8] = SettingsPacket_TypeOnOff;
      out[9] = packet->onOff.relay1DefaultOn;
      out[10] = packet->onOff.relay2DefaultOn;

      return SettingsPacketHeaderLength + 3;
    }
  }
}

int deserialize_settings(SettingsPacket* packet, uint8_t* in) {
  packet->serialNumber = decode_uint32(in + 1);
  packet->ackId = decode_uint16(in + 5);
  packet->flags = in[7];

  switch(in[8]) {
    case SettingsPacket_TypeOnOff: {
      packet->settingsType = SettingsTypeOnOff;
      struct SettingsOnOff onOff = {
              .relay1DefaultOn = in[9],
              .relay2DefaultOn = in[10],
      };

      packet->onOff = onOff;
      break;
    }
    default:
      return 1;
  }

  return 0;
}