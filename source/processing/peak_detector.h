#ifndef PEAK_DETECTOR_H_
#define PEAK_DETECTOR_H_
//--------------------------
int detect_peak(
	const float* data,
    int data_count,
    int* emi_peaks,
    int* num_emi_peaks,
    int max_emi_peaks,
    int* absop_peaks,
    int* num_absop_peaks,
    int max_absop_peaks,
    float delta,
    int emi_first
);

#endif
