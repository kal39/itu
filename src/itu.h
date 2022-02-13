#ifndef ITU_H
#define ITU_H

char *convert_image(unsigned char *data, int in_width, int in_height, int out_width, int out_height);

#ifdef ITU_IMPLEMENTATION

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
} Character;

typedef struct ImageInfo {
	unsigned char *data;
	int width;
	int height;
	float scale_x;
	float scale_y;
} ImageInfo;

typedef struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Color;

Character ALLOWED_CHARACTERS[] = {
	(Character){"▁",
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
				}},
	(Character){"▂",
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
				}},

	(Character){"▃",
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
				}},

	(Character){"▄",
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
				}},

	(Character){"▅",
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
				}},

	(Character){"▆",
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
				}},

	(Character){"▇",
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
				}},

	(Character){"▏",
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
				}},

	(Character){"▎",
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
				}},

	(Character){"▍",
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
				}},

	(Character){"▌",
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
				}},

	(Character){"▋",
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
				}},

	(Character){"▊",
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
				}},

	(Character){"▉",
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
				}},

	(Character){"▝",
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
				}},

	(Character){"▘",
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
				}},

	(Character){"▗",
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
				}},

	(Character){"▖",
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
				}},

	(Character){"▚",
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
				}},
};

long calculate_color(Character character, ImageInfo image, int x, int y, Color *fgColor, Color *bgColor) {
	int fgColorArr[] = {0, 0, 0};
	int bgColorArr[] = {0, 0, 0};
	int fgColorCount = 0;
	int bgColorCount = 0;
	int error = 0;

	for (int i = 0; i < CHARACTER_HEIGHT; i++) {
		for (int j = 0; j < CHARACTER_WIDTH; j++) {
			int pos_x = (int)((float)(j + x * CHARACTER_WIDTH) / image.scale_x);
			int pos_y = (int)((float)(i + y * CHARACTER_HEIGHT) / image.scale_y);
			int idx = (pos_y * image.width + pos_x) * 3;

			if (character.pixels[i * CHARACTER_WIDTH + j]) {
				fgColorArr[0] += image.data[idx + 0];
				fgColorArr[1] += image.data[idx + 1];
				fgColorArr[2] += image.data[idx + 2];
				fgColorCount++;

				error += abs(fgColorArr[0] / fgColorCount - image.data[idx + 0]);
				error += abs(fgColorArr[1] / fgColorCount - image.data[idx + 1]);
				error += abs(fgColorArr[2] / fgColorCount - image.data[idx + 2]);
			} else {
				bgColorArr[0] += image.data[idx + 0];
				bgColorArr[1] += image.data[idx + 1];
				bgColorArr[2] += image.data[idx + 2];
				bgColorCount++;

				error += abs(bgColorArr[0] / bgColorCount - image.data[idx + 0]);
				error += abs(bgColorArr[1] / bgColorCount - image.data[idx + 1]);
				error += abs(bgColorArr[2] / bgColorCount - image.data[idx + 2]);
			}
		}
	}

	fgColorArr[0] /= fgColorCount;
	fgColorArr[1] /= fgColorCount;
	fgColorArr[2] /= fgColorCount;

	bgColorArr[0] /= bgColorCount;
	bgColorArr[1] /= bgColorCount;
	bgColorArr[2] /= bgColorCount;

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

char *convert_image_area(ImageInfo image, int x, int y) {
	long min = LONG_MAX;
	Character minChar;
	Color minFgColor;
	Color minBgColor;

	for (int i = 0; i < ALLOWED_CHARACTER_COUNT; i++) {
		Color fgColor, bgColor;
		int error = calculate_color(ALLOWED_CHARACTERS[i], image, x, y, &fgColor, &bgColor);

		if (error < min) {
			min = error;
			minChar = ALLOWED_CHARACTERS[i];
			minFgColor = fgColor;
			minBgColor = bgColor;
		}
	}

	return to_string(minChar, minFgColor, minBgColor);
}

char *convert_image(unsigned char *data, int in_width, int in_height, int out_width, int out_height) {
	if (in_width < 0 || in_height < 0) return NULL;

	float scale_x = (float)out_width * (float)CHARACTER_WIDTH / (float)in_width;
	float scale_y = (float)out_height * (float)CHARACTER_HEIGHT / (float)in_height;

	ImageInfo image = (ImageInfo){data, in_width, in_height, scale_x, scale_y};

	// allocate space for charaters, newlines, color reset, and \0
	int strLen = CHARACTER_STRLEN * out_width * out_height + (out_height - 1) + 4 + 1;
	char *str = malloc(strLen);
	long offset = 0;

	for (int i = 0; i < out_height; i++) {
		for (int j = 0; j < out_width; j++) {
			char *tmp = convert_image_area(image, j, i);
			memcpy(str + offset, tmp, CHARACTER_STRLEN);
			offset += CHARACTER_STRLEN;
			free(tmp);
		}

		if (i != out_height - 1) {
			str[offset] = '\n';
			offset += 1;
		}
	}

	char end[] = "\e[0m";
	memcpy(str + offset, end, 5);
	str[strLen - 1] = '\0';

	return str;
}

#endif
#endif