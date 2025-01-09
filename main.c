#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *streamIn = fopen("images/cameraman.bmp", "rb");
    FILE *streamOut = fopen("images/cameraman_copy.bmp", "wb");
    
    if(streamIn == NULL) {
        printf("Error opening file!\n");
    }

    unsigned char header[54];
    unsigned char colorTable[1024];
    
    for (int i = 0; i < 54; i++) {
        header[i] = getc(streamIn);
    }
    
    int width = *(int *) &header[18];
    int width2 = (int) header[18];

    printf("int: %d\n", width);
    printf("int: %d\n", width2);

    return 0;

}