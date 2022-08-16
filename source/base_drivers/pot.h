#pragma once
//----------------------------------
#define POT_MAX	4095.0f
#define POT_MID (float)(POT_MAX / 2.0f)
//----------------------------------

void pot_update(int chnl, int32_t val);
