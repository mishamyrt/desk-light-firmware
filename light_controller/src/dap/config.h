#pragma once

#define INPUT_DATA_SIZE 128

/// 4 bytes for technical values. 2 for constants, 1 for length and one for checksum.
#define INPUT_BUFFER_SIZE INPUT_DATA_SIZE + 4
#define BOUD_RATE 2000000
#define INPUT_TIMEOUT 50
