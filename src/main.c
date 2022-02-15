#include <stdio.h>
#include <stdlib.h>

#define ITU_IMPLEMENTATION
#include "itu.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(void) {
	int width, height;
	unsigned char *data = stbi_load("train.png", &width, &height, NULL, 3);
	char *str = convert_image(data, width, height, 800 / 8 * 1.5, 640 / 16 * 1.5, 6);
	printf("%s\n", str);

	// for (int i = 0; i < 7; i++) print_allowed_characters(i);
}