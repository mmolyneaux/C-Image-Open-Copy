#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *streamIn = fopen("images/cameraman.bmp", "rb");
    FILE *streamOut = fopen("images/cameraman_copy.bmp", "wb");

    if (streamIn == NULL) {
        printf("Error opening file!\n");
    }

    unsigned char header[54];
    unsigned char colorTable[1024];

    for (int i = 0; i < 54; i++) {
        header[i] = getc(streamIn);
    }

    // width starts at address of byte(char) 18, which is then cast to an int*,
    // so it can be dereferenced into an int, so it is cast to a 4 byte int
    // instead stead of a single byte from the char header array. Then the
    // height can be retreived from the next 4 byts and so on.
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int bitDepth = *(int *)&header[28];

    printf("width: %d\n", width);
    printf("height: %d\n", height);
    printf("bitDepth: %d\n", bitDepth);

    return 0;
}