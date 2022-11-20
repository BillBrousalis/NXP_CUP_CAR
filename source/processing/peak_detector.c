#include "includes.h"
#include "globals.h"

int detect_peak(
	const float* data, 		/* the data */
    int data_count, 		/* row count of data */
    int* emi_peaks, 		/* emission peaks will be put here */
    int* num_emi_peaks, 	/* number of emission peaks found */
    int max_emi_peaks, 		/* maximum number of emission peaks */
    int* absop_peaks, 		/* absorption peaks will be put here */
    int* num_absop_peaks, 	/* number of absorption peaks found */
    int max_absop_peaks, 	/* maximum number of absorption peaks */
    float delta, 			/* delta used for distinguishing peaks */
    int emi_first 			/* should we search emission peak first of absorption peak first? */
    			) {
    int i;
    float mx;
    float mn;
    int mx_pos = 0;
    int mn_pos = 0;
    int is_detecting_emi = emi_first;

    mx = data[0];
    mn = data[0];

    *num_emi_peaks = 0;
    *num_absop_peaks = 0;

    for(i = 1; i < data_count; ++i) {
        if(data[i] > mx) {
            mx_pos = i;
            mx = data[i];
        }
        if(data[i] < mn) {
            mn_pos = i;
            mn = data[i];
        }

        if(is_detecting_emi && data[i] < mx - delta) {
            if(*num_emi_peaks >= max_emi_peaks) return 1;

            emi_peaks[*num_emi_peaks] = mx_pos;
            ++ (*num_emi_peaks);

            is_detecting_emi = 0;

            i = mx_pos - 1;

            mn = data[mx_pos];
            mn_pos = mx_pos;
        }
        else if((!is_detecting_emi) && data[i] > mn + delta) {
            if(*num_absop_peaks >= max_absop_peaks) return 2;

            absop_peaks[*num_absop_peaks] = mn_pos;
            ++ (*num_absop_peaks);

            is_detecting_emi = 1;

            i = mn_pos - 1;

            mx = data[mn_pos];
            mx_pos = mn_pos;
        }
    }
    return 0;
}
