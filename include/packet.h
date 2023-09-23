#ifndef ROMA_RFM_PROTOCOL_PACKET_H
#define ROMA_RFM_PROTOCOL_PACKET_H

#include <stdint.h>

int encode_uint32(uint32_t input, uint8_t *out);
int encode_uint16(uint16_t input, uint8_t *out);

uint32_t decode_uint32(const uint8_t *input);
uint16_t decode_uint16(const uint8_t *input);

#endif //ROMA_RFM_PROTOCOL_PACKET_H
