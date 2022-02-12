#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARACTER_WIDTH 8
#define CHARACTER_HEIGHT 16
#define ALLOWED_CHARACTER_COUNT 19
#define CHARACTER_STRLEN 41

typedef struct Character {
	char *character;
	int *pixels;
	int fgPixelCount;
	int bgPixelCount;
} Character;

typedef struct Image {
	unsigned char *data;
	int width;
	int height;
} Image;

typedef struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Color;

Character create_character(char *character, int *pixels) {
	int fgPixelCount = 0;
	int bgPixelCount = 0;

	for (int i = 0; i < CHARACTER_HEIGHT; i++) {
		for (int j = 0; j < CHARACTER_WIDTH; j++) {
			if (pixels[i * CHARACTER_WIDTH + j]) fgPixelCount++;
			else bgPixelCount++;
		}
	}

	return (Character){character, pixels, fgPixelCount, bgPixelCount};
}

Character *load_allowed_characters() {
	return (Character[]){
		create_character("▁",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
						 }),
		create_character("▂",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
						 }),

		create_character("▃",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
						 }),

		create_character("▄",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
						 }),

		create_character("▅",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
						 }),

		create_character("▆",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
						 }),

		create_character("▇",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
							 1, 1, 1, 1, 1, 1, 1, 1, //
						 }),

		create_character("▏",
						 (int[]){
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
							 1, 0, 0, 0, 0, 0, 0, 0, //
						 }),

		create_character("▎",
						 (int[]){
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
							 1, 1, 0, 0, 0, 0, 0, 0, //
						 }),

		create_character("▍",
						 (int[]){
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
							 1, 1, 1, 0, 0, 0, 0, 0, //
						 }),

		create_character("▌",
						 (int[]){
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
						 }),

		create_character("▋",
						 (int[]){
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
							 1, 1, 1, 1, 1, 0, 0, 0, //
						 }),

		create_character("▊",
						 (int[]){
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
							 1, 1, 1, 1, 1, 1, 0, 0, //
						 }),

		create_character("▉",
						 (int[]){
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
							 1, 1, 1, 1, 1, 1, 1, 0, //
						 }),

		create_character("▝",
						 (int[]){
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
						 }),

		create_character("▘",
						 (int[]){
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
						 }),

		create_character("▗",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
						 }),

		create_character("▖",
						 (int[]){
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 0, 0, 0, 0, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
						 }),

		create_character("▚",
						 (int[]){
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 1, 1, 1, 1, 0, 0, 0, 0, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
							 0, 0, 0, 0, 1, 1, 1, 1, //
						 }),
	};
}

long calculate_color(Character character, Image image, int x, int y, Color *fgColor, Color *bgColor) {
	// calculate average fg and bg color
	long fgColorArr[] = {0, 0, 0};
	long bgColorArr[] = {0, 0, 0};

	for (int i = 0; i < CHARACTER_HEIGHT; i++) {
		for (int j = 0; j < CHARACTER_WIDTH; j++) {
			int idx = ((i + y) * image.width + (j + x)) * 3;

			if (character.pixels[i * CHARACTER_WIDTH + j]) {
				fgColorArr[0] += image.data[idx + 0];
				fgColorArr[1] += image.data[idx + 1];
				fgColorArr[2] += image.data[idx + 2];
			} else {
				bgColorArr[0] += image.data[idx + 0];
				bgColorArr[1] += image.data[idx + 1];
				bgColorArr[2] += image.data[idx + 2];
			}
		}
	}

	fgColorArr[0] /= character.fgPixelCount;
	fgColorArr[1] /= character.fgPixelCount;
	fgColorArr[2] /= character.fgPixelCount;

	bgColorArr[0] /= character.bgPixelCount;
	bgColorArr[1] /= character.bgPixelCount;
	bgColorArr[2] /= character.bgPixelCount;

	// calculate overall error
	long error = 0;

	for (int i = 0; i < CHARACTER_HEIGHT; i++) {
		for (int j = 0; j < CHARACTER_WIDTH; j++) {
			int idx = ((i + y) * image.width + (j + x)) * 3;

			if (character.pixels[i * CHARACTER_WIDTH + j]) {
				error += abs(fgColorArr[0] - image.data[idx + 0]);
				error += abs(fgColorArr[1] - image.data[idx + 1]);
				error += abs(fgColorArr[2] - image.data[idx + 2]);
			} else {
				error += abs(bgColorArr[0] - image.data[idx + 0]);
				error += abs(bgColorArr[1] - image.data[idx + 1]);
				error += abs(bgColorArr[2] - image.data[idx + 2]);
			}
		}
	}

	*fgColor = (Color){fgColorArr[0], fgColorArr[1], fgColorArr[2]};
	*bgColor = (Color){bgColorArr[0], bgColorArr[1], bgColorArr[2]};
	return error;
}

char *to_string(Character character, Color fgColor, Color bgColor) {
	char *str = malloc(CHARACTER_STRLEN + 1);

	sprintf(str,
			"\x1b[38;2;%03d;%03d;%03dm\x1b[48;2;%03d;%03d;%03dm%s",
			fgColor.r,
			fgColor.g,
			fgColor.b,
			bgColor.r,
			bgColor.g,
			bgColor.b,
			character.character);
	return str;
}

char *convert_image_area(Image image, int x, int y) {
	long min = LONG_MAX;
	Character minChar;
	Color minFgColor;
	Color minBgColor;

	Character *allowed_characters = load_allowed_characters();

	for (int i = 0; i < ALLOWED_CHARACTER_COUNT; i++) {
		Color fgColor, bgColor;
		int error = calculate_color(allowed_characters[i], image, x, y, &fgColor, &bgColor);

		if (error < min) {
			min = error;
			minChar = allowed_characters[i];
			minFgColor = fgColor;
			minBgColor = bgColor;
		}
	}

	return to_string(minChar, minFgColor, minBgColor);
}

char *convert_image(unsigned char *data, int width, int height) {
	if (width % CHARACTER_WIDTH != 0 || height % CHARACTER_HEIGHT != 0) return NULL;

	Image image = (Image){data, width, height};

	char *str = malloc(CHARACTER_STRLEN * ((width / CHARACTER_WIDTH) * (height / CHARACTER_HEIGHT)) + height + 1);
	long offset = 0;

	for (int i = 0; i < height / CHARACTER_HEIGHT; i++) {
		for (int j = 0; j < width / CHARACTER_WIDTH; j++) {
			char *tmp = convert_image_area(image, j * CHARACTER_WIDTH, i * CHARACTER_HEIGHT);
			memcpy(str + offset, tmp, CHARACTER_STRLEN);
			offset += CHARACTER_STRLEN;
			free(tmp);
		}

		str[offset] = '\n';
		offset += 1;
	}

	str[offset] = '\0';

	return str;
}