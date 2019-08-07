# tga-encoder

tga-encoder is a small C library that encodes TGA images.

## What is TGA?

TGA is a very lightweight image format. It was created by Truevision in the 1980s but is still supported by a lot of image sotware such as Photoshop today. They are very easy to manipulate due to their simple structure.

## How it works

There are only three functions declared in "tga.h": `createImage()`, `writeImage()`, and `closeImage()`.

`createImage()` takes three parameters:

```
TGAImage createImage(
	const char *name,			/* File name. */
	unsigned short width,			/* Image width. */
	unsigned short height			/* Image height. */
);
```

The image's contents are manipulated through the `imageData` field in the TGAImage object. Pixels are stored horizontally starting from the bottom left.

`writeImage()` only takes on parameter, a pointer to a TGAImage object. It writes the image data to the file.

`closeImage()` also only takes a pointer to a TGAImage object. It cleans up memory allocated in `createImage()`.

## Important notes
- `closeImage()` does not write the image to the file. You must call `writeImage()` for any data to actually be written to the file.
- Image size is constrained by the format's limitations to 65536 x 65536.
- Image data is stored in blue-green-red order. If your image's colors come out weirdly, you are probably storing pixels in the wrong order.

## Example
When run, the example program should output this:

[image]: exampleOutput.png