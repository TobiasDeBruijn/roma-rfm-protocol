#ifndef ROMA_RFM_PROTOCOL_SETTINGS_H
#define ROMA_RFM_PROTOCOL_SETTINGS_H

#include <stdint.h>
#include <stdbool.h>

#define SettingsPacketIdentifier 0x02
#define SettingsPacketHeaderLength 9

#define SettingsPacket_TypeOnOff 0x01

typedef enum SettingsType {
    SettingsTypeOnOff,
} SettingsType;

typedef struct SettingsPacket {
    uint32_t serialNumber;
    uint16_t ackId;
    uint8_t flags;
    SettingsType settingsType;
    union {
        struct OnOff {
            bool relay1DefaultOn;
            bool relay2DefaultOn;
        } onOff;
    };
} SettingsPacket;

int serialize_settings(uint8_t* out, SettingsPacket* packet);
int deserialize_settings(SettingsPacket* packet, uint8_t* in);

#endif //ROMA_RFM_PROTOCOL_SETTINGS_H
