#include <stdio.h>
#include <stdlib.h>
#include "tga.h"

/* Attempts to create a TGAImage. Returns null if file opening or allocations fail. */
TGAImage *createImage(const char *name, unsigned short width, unsigned short height) {
	
	/* Make sure file can be opened. */
	FILE *file = fopen(name, "wb");
	if(file == NULL) {
		return NULL;
	}	
	
	/* Try to allocate image data and space for actually struct itself. */
	unsigned char *imageData = malloc(width * height * 3);
	if(imageData == NULL) {
		return NULL;
	}
	
	TGAImage *image = malloc(sizeof(TGAImage));
	if(image == NULL) {
		return NULL;
	}
	
	/* Set up image fields. */
	image->file = file;
	image->width = width;
	image->height = height;
	image->imageData = imageData;
	
	/* Return image. */
	return image;
	
}

/* Write image data to disk. */
void writeImage(TGAImage *image) {
	
	FILE *file = image->file;

	/* ID length (zero for none) */
	fputc(0, file);
	
	/* Colormap type (zero for none) */
	fputc(0, file);
	
	/* Image type (2 for uncompressed truecolor) */
	fputc(2, file);
	
	/* Colormap fields (zero for none) */
	/* Also X and Y origin (zero, bottom) */
	for(unsigned int i = 0; i < 9; i++) fputc(0, file);
	
	/* Image width */
	fputc(image->width & 0xFF, file);
	fputc((image->width & 0xFF00) >> 8, file);
	
	/* Image height */
	fputc(image->height & 0xFF, file);
	fputc((image->height & 0xFF00) >> 8, file);
	
	/* Pixel depth (24 bit) */
	fputc(24, file);
	
	/* Image descriptor (0, mostly discarded data) */
	fputc(0, file);

	for(unsigned int i = 0; i < image->width * image->height * 3; i += 3) {
		
		/* Reverse color component order to RGB (more intuitive) */
		fputc(image->imageData[i + 2], file);
		fputc(image->imageData[i + 1], file);
		fputc(image->imageData[i], file);
		
	}
	
}

void closeImage(TGAImage *image) {

	/* Close image handle. */
	fclose(image->file);
	
	/* Free allocated memory. */
	free(image->imageData);
	free(image);
	
}
