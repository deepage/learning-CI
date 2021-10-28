#include "Hello.h"

// template<typename T>
// int func_add(T* a, T* b, size_t llength, size_t rlength, T* out) {
//     if (llength != rlength && rlength != 1) {
//         printf("size should equ or rlength must be 1!!!\n");
//         return -1;
//     }

//     if (llength == 0 || rlength == 0) {
//         printf("size should not be zero!!\n");
//         return -2;
//     }

//     if (rlength == 1) {
//         out = (T*)malloc(llength * sizeof(T));
//         for (size_t i = 0; i < llength; i++) {
//             out[i] = a[i] + b[0];
//         }
//     } else {
//         out = (T*)malloc(llength * sizeof(T));
//         for (size_t i = 0; i < llength; i++) {
//             out[i] = a[i] + b[i];
//         }
//     }
//     return 0;
// }

template <>
int func_add(int *a, int *b, size_t llength, size_t rlength, int *out) {
    if (llength != rlength && rlength != 1) {
        printf("size should equ or rlength must be 1!!!\n");
        return -1;
    }

    if (llength == 0 || rlength == 0) {
        printf("size should not be zero!!\n");
        return -2;
    }

    if (rlength == 1) {
        out = (int *)malloc(llength * sizeof(int));
        for (size_t i = 0; i < llength; i++) {
            out[i] = a[i] + b[0];
        }
    } else {
        out = (int *)malloc(llength * sizeof(int));
        for (size_t i = 0; i < llength; i++) {
            out[i] = a[i] + b[i];
        }
    }
    return 0;
}

template <>
int func_add(float *a, float *b, size_t llength, size_t rlength, float *out) {
    if (llength != rlength && rlength != 1) {
        printf("size should equ or rlength must be 1!!!\n");
        return -1;
    }

    if (llength == 0 || rlength == 0) {
        printf("size should not be zero!!\n");
        return -2;
    }

    if (rlength == 1) {
        out = (float *)malloc(llength * sizeof(float));
        for (size_t i = 0; i < llength; i++) {
            out[i] = a[i] + b[0];
        }
    } else {
        out = (float *)malloc(llength * sizeof(float));
        for (size_t i = 0; i < llength; i++) {
            out[i] = a[i] + b[i];
        }
    }
    return 0;
}