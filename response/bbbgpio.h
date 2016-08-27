/*
 * BeagleBone Black
 * 
 * bbbgpio.h
 *
 *      Author: carvalho
 */

#ifndef BBBGPIO_H_
#define BBBGPIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UP 1
#define DOWN 0

#define INPUT 1
#define OUTPUT 0

#define GPIO_2 2
#define GPIO_3 3
#define GPIO_4 4
#define GPIO_5 5
#define GPIO_7 7

#define GPIO_14 14
#define GPIO_15 15

#define GPIO_22 22
#define GPIO_23 23
#define GPIO_26 26
#define GPIO_27 27

#define GPIO_30 30

#define GPIO_44 44
#define GPIO_45 45
#define GPIO_46 46
#define GPIO_47 47
#define GPIO_48 48
#define GPIO_49 49

#define GPIO_50 50
#define GPIO_51 51

#define GPIO_60 60
#define GPIO_61 61
#define GPIO_65 65
#define GPIO_66 66
#define GPIO_67 67
#define GPIO_68 68
#define GPIO_69 69

#define GPIO_112 112
#define GPIO_114 114
#define GPIO_115 115
#define GPIO_116 116

FILE* _GPIO_file(unsigned int _pin , const char *_file) {
	char file[40];

	snprintf(file, sizeof(file), "/sys/class/gpio/gpio%d/", _pin);

	strcat(file,_file);

	FILE *pFile = fopen(file, "r+");

	return pFile;
}

/*
 * @brief Set status of digital pin (UP[1] or DOWN[0])
 *
 * @paran _pin
 * @param _status If is UP or DOWN
 *
 * @return Return success (1) or error (-1)
 */
int GPIO_setStatus(unsigned int _pin, unsigned int _status) {
	char status;

	if(_status == UP) {
		status = '1';
	} else {
		status = '0';
	}

	FILE *pFile = _GPIO_file(_pin, "value");

	if(pFile != NULL) {
		fwrite(&status, sizeof(char), 1, pFile);
		fclose(pFile);

		return 1;
	}

	perror("Error Status file");
	return -1;
}

int GPIO_setMode(unsigned int _pin, unsigned int _mode) {

	char mode[4];

	if(_mode == INPUT) {
		strcpy(mode,"in");
	} else if(_mode == OUTPUT) {
		strcpy(mode,"out");
	} else {
		printf("Mode invalid, GPIO_%d", _pin);
		return -1;
	}

	FILE *pFile = _GPIO_file(_pin, "direction");

	if(pFile != NULL) {
		fwrite(mode, sizeof(char), strlen(mode), pFile);
		fclose(pFile);

		return 1;
	}

	perror("Error Mode file");
	return -1;
}

int GPIO_status(unsigned int _pin) {
	FILE *pFile = _GPIO_file(_pin, "value");
	char buffer;

	if(pFile != NULL) {
		fread(&	buffer, sizeof(char), 1, pFile);
		fclose(pFile);

		if(buffer == '1') return UP;
		else return DOWN;
	}

	perror("Error Read status file");
	return -1;
}

#endif /* BBBGPIO_H_ */
