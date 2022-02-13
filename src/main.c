#include <stdio.h>
#include <stdlib.h>

#include "itu.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(void) {
	int width, height;
	unsigned char *data = stbi_load("train.png", &width, &height, NULL, 3);
	char *str = convert_image(data, width, height, 200, 60);
	printf("%s\n", str);
}