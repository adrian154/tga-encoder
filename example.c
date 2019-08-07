#include <stdio.h>
#include "tga.h"

int main(int argc, char *argv[]) {
	
	TGAImage *image = createImage("example.tga", 256, 256);
	
	for(int r = 0; r < 256; r++) {
		for(int g = 0; g < 256; g++) {
			image->imageData[g * 256 * 3 + r * 3 + 2] = r;
			image->imageData[g * 256 * 3 + r * 3 + 1] = g;
			image->imageData[g * 256 * 3 + r * 3] = 0;
		}
	}
	
	writeImage(image);
	closeImage(image);
	
	return 0;
	
}

