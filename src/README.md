**Usage:**

```
/*
 * Creates a string with the correct size to be used with itu_convert_image().
 *
 * Parameters:
 *   out_width:  width of the output image in characters
 *   out_height: height of the output image in characters
 *
 * Returns:
 *   NULL:   string creation unsuccessful
 *   (else): string that can be passed to itu_convert_image() <<<FREE AFTER USE!!>>>
 */

char *itu_allocate_string(int out_width, int out_height);

/*
 * Writes string representation of an image using unicode block elements and 24-bit truecolor to the out parameter.
 * NOTE: for characters, width:height = 1:2
 *
 * Parameters:
 *   out:        string to write to (allocate using itu_allocate_string())
 *   data:       pixel data of the input image in 3 channels (rgb); same format as stb_image
 *   in_width:   width of input image in px
 *   in_height:  height of the input image in px
 *   out_width:  width of the output image in characters
 *   out_height: height of the output image in characters
 *   detail:     between 0 (inclusive) and 6 (inclusive), 0 lowest detail, 6 highest detail
 *
 * Returns:
 *   0:  conversion successful
 *   -1: in/out dimensions unsupported
 *   -2: malloc() failed
 */

int itu_convert_image(char *out, unsigned char *data, int in_width, int in_height, int out_width, int out_height,
					  int detail);
```