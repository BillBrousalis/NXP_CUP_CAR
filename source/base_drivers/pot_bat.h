#ifndef POT_BAT_H_
#define POT_BAT_H_
//----------------------------------
#define POT_MAX	4095.0f
#define POT_MID (float)(POT_MAX / 2.0f)
//----------------------------------
void adc1_vals_store(uint8_t chnl, uint32_t val);

#endif
