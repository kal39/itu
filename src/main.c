#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ITU_IMPLEMENTATION
#include "itu.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void benchmark(char *fileName, int times) {
	int width, height;
	unsigned char *data = stbi_load("train.png", &width, &height, NULL, 3);

	int outWidth = 800 / 8 * 1.5;
	int outHeight = 640 / 16 * 1.5;

	printf("==== BENCHMARK RESULTS (%d samples) ====\n", times);

	for (int i = 0; i < 7; i++) {

		struct timeval start;
		gettimeofday(&start, NULL);

		for (int j = 0; j < times; j++) free(itu_convert_image(data, width, height, outWidth, outHeight, i));

		struct timeval end;
		gettimeofday(&end, NULL);

		double startTime = (double)start.tv_sec + (double)start.tv_usec / 1000000.0;
		double endTime = (double)end.tv_sec + (double)end.tv_usec / 1000000.0;

		double totalTime = endTime - startTime;
		double timePerFrame = totalTime / (double)times;
		printf("<<detail: %d>> total time: %f[s], time per frame: %f[s], fps: %f\n",
			   i,
			   totalTime,
			   timePerFrame,
			   1.0 / timePerFrame);
	}

	free(data);
}

void display(char *fileName) {
	int width, height;
	unsigned char *data = stbi_load(fileName, &width, &height, NULL, 3);

	int outWidth = 800 / 8 * 1.5;
	int outHeight = 640 / 16 * 1.5;

	char *out = itu_convert_image(data, width, height, outWidth, outHeight, 6);

	printf("%s\n", out);
	free(data);
	free(out);
}

int main(void) {
	display("train.png");
	// benchmark("train.png", 10);
}