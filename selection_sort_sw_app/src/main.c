#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

void sort(unsigned int *array, unsigned int length);
void print_array(unsigned int *array, unsigned int length);

const unsigned int DATA_LEN = 9;
unsigned int data[] = {14, 3, 8, 12, 5, 4, 5, 1, 77};

int main()
{
	init_platform();

	print("\n\rbefore: ");
	print_array(data, DATA_LEN);

	sort(data, DATA_LEN);

	print("\n\rafter : ");
	print_array(data, DATA_LEN);

	cleanup_platform();
	return 0;
}

void sort(unsigned int *array, unsigned int length) {

	for (int index_counter = 0; index_counter < length; ++index_counter) {
		// Set index_counter element as smallest found element
		unsigned int smallest_index = index_counter;
		unsigned int smallest_value = array[index_counter];
		
		// Compare smallest element with rest of array and keep the smallest element
		// found (including index)
		for (int comparing_index_counter = index_counter + 1; comparing_index_counter < length; ++comparing_index_counter) {
			if (array[comparing_index_counter] < smallest_value) {
				smallest_value = array[comparing_index_counter];
				smallest_index = comparing_index_counter;
			}
		}

		// Swap first and smallest elements
		unsigned int temp = array[index_counter];
		array[index_counter] = smallest_value;
		array[smallest_index] = temp;
	}
}

void print_array(unsigned int *array, unsigned int length) {
	for (int i = 0; i < length; ++i) {
		char buf[10];
		sprintf(buf, "%2d%s", array[i], i + 1 == length ? "" : ", ");
		print(buf);
	}
}
