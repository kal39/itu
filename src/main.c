#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITU_IMPLEMENTATION
#include "itu.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void benchmark(char *fileName, int times) {
	int width, height;
	unsigned char *data = stbi_load("train.png", &width, &height, NULL, 3);

	int outWidth = 800 / 8 * 1.5;
	int outHeight = 640 / 16 * 1.5;

	char *out = itu_allocate_string(outWidth, outHeight);

	printf("==== BENCHMARK RESULTS (%d samples) ====\n", times);

	for (int i = 0; i < 7; i++) {

		clock_t start = clock();
		for (int j = 0; j < times; j++) itu_convert_image(out, data, width, height, outWidth, outHeight, i);
		clock_t end = clock();

		double totalTime = (double)(end - start) / CLOCKS_PER_SEC;
		double timePerFrame = totalTime / (double)times;
		printf("<<detail: %d>> total time: %f[s], time per frame: %f[s], fps: %f\n",
			   i,
			   totalTime,
			   timePerFrame,
			   1.0 / timePerFrame);
	}

	free(data);
	free(out);
}

void display(char *fileName) {
	int width, height;
	unsigned char *data = stbi_load("train.png", &width, &height, NULL, 3);

	int outWidth = 800 / 8 * 1.5;
	int outHeight = 640 / 16 * 1.5;

	char *out = itu_allocate_string(outWidth, outHeight);
	itu_convert_image(out, data, width, height, outWidth, outHeight, 6);

	printf("%s\n", out);
	free(data);
	free(out);
}

int main(void) {
	display("train.png");
	benchmark("train.png", 10);
}