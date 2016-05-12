int hammingWeight(uint32_t n) {
    uint32_t v=n;
    v = v - ((v>>1) & 0x55555555);
    v = (v & 0x33333333) + ((v>>2) & 0x33333333);
    return (((v + (v>>4) & 0xF0F0F0F) * 0x1010101) >> 24);
}
