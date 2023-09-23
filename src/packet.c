#include "include/packet.h"

int encode_uint32(uint32_t input, uint8_t *out) {
  out[0] = (input >> 24) & 0xFF;
  out[1] = (input >> 16) & 0xFF;
  out[2] = (input >> 8) & 0xFF;
  out[3] = input & 0xFF;

  return 4;
}

int encode_uint16(uint16_t input, uint8_t *out) {
  out[0] = (input >> 8) & 0xFF;
  out[1] = input & 0xFF;

  return 2;
}

uint32_t decode_uint32(const uint8_t *input) {
  return (uint32_t) input[3]
         | (uint32_t) input[2] << 8
         | (uint32_t) input[1] << 16
         | (uint32_t) input[0] << 24;
}

uint16_t decode_uint16(const uint8_t *input) {
  return ((uint16_t) input[1]) | (((uint16_t) input[0]) << 8);
}