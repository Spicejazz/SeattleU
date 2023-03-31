#include "fileUtils.h"

int readByte(std::ifstream &input) {
    char byte;
    input.read(&byte, 1);
    return byte;
}

int readInt(std::ifstream &input) {
    char buffer[4];
    input.read(buffer, 4);
    return *((int *)buffer);
}