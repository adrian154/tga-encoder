struct TGAImage {
	unsigned short width;
	unsigned short height;
	unsigned char *imageData;
	FILE *file;
};

typedef struct TGAImage TGAImage;

extern TGAImage *createImage(const char *name, unsigned short width, unsigned short height);
extern void writeImage(TGAImage *image);
extern void closeImage(TGAImage *image);
