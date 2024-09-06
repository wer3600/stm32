#include <stdint.h>
#include <stdio.h>

// Delay function
void delay(void) {
    for(uint32_t i = 0; i < 300000; i++);
}

int main(void) {
    // Peripheral register addresses
    uint32_t volatile *const pGPIOCModeReg  = (uint32_t*)(0x40020800);
    uint32_t volatile *const pInputDataReg  = (uint32_t*)(0x40020810);
    uint32_t volatile *const pOutputDataReg = (uint32_t*)(0x40020814);
    uint32_t volatile *const pClockCtrlReg  = (uint32_t*)(0x40023830);
    uint32_t volatile *const pPullupDownReg = (uint32_t*)(0x4002080C);

    // 1. Enable the peripheral clock of GPIOC peripheral
    *pClockCtrlReg |= (1 << 2);

    // 2. Configure PC0~PC3 as output (rows)
    *pGPIOCModeReg &= ~(0xFF); // Clear mode bits for PC0~PC3
    *pGPIOCModeReg |= 0x55;   // Set PC0~PC3 as output (0101 in binary)

    // 3. Configure PC8~PC11 as input (columns)
    *pGPIOCModeReg &= ~(0xF << 16); // Clear mode bits for PC8~PC11

    // 4. Enable internal pull-up resistors for PC8~PC11
    *pPullupDownReg &= ~(0xFF << 16);
    *pPullupDownReg |= (0x55 << 16); // 0101 in binary

    while(1) {
        // Make all rows HIGH
        *pOutputDataReg |= 0xF; // Set PC0~PC3 HIGH

        // Make R1 LOW (PC0)
        *pOutputDataReg &= ~(1 << 0);

        // Scan the columns
        // Check C1 (PC8) low or high
        if (!(*pInputDataReg & (1 << 8))) {
            // Key is pressed
            delay();
            printf("1\n");
        }

        // Check C2 (PC9) low or high
        if (!(*pInputDataReg & (1 << 9))) {
            // Key is pressed
            delay();
            printf("2\n");
        }

        // Check C3 (PC10) low or high
        if (!(*pInputDataReg & (1 << 10))) {
            // Key is pressed
            delay();
            printf("3\n");
        }

        // Check C4 (PC11) low or high
        if (!(*pInputDataReg & (1 << 11))) {
            // Key is pressed
            delay();
            printf("A\n");
        }

        // Make all rows HIGH
        *pOutputDataReg |= 0xF; // Set PC0~PC3 HIGH
        // Make R2 LOW (PC1)
        *pOutputDataReg &= ~(1 << 1);

        // Scan the columns
        // Check C1 (PC8) low or high
        if (!(*pInputDataReg & (1 << 8))) {
            // Key is pressed
            delay();
            printf("4\n");
        }

        // Check C2 (PC9) low or high
        if (!(*pInputDataReg & (1 << 9))) {
            // Key is pressed
            delay();
            printf("5\n");
        }

        // Check C3 (PC10) low or high
        if (!(*pInputDataReg & (1 << 10))) {
            // Key is pressed
            delay();
            printf("6\n");
        }

        // Check C4 (PC11) low or high
        if (!(*pInputDataReg & (1 << 11))) {
            // Key is pressed
            delay();
            printf("B\n");
        }

        // Make all rows HIGH
        *pOutputDataReg |= 0xF; // Set PC0~PC3 HIGH
        // Make R3 LOW (PC2)
        *pOutputDataReg &= ~(1 << 2);

        // Scan the columns
        // Check C1 (PC8) low or high
        if (!(*pInputDataReg & (1 << 8))) {
            // Key is pressed
            delay();
            printf("7\n");
        }

        // Check C2 (PC9) low or high
        if (!(*pInputDataReg & (1 << 9))) {
            // Key is pressed
            delay();
            printf("8\n");
        }

        // Check C3 (PC10) low or high
        if (!(*pInputDataReg & (1 << 10))) {
            // Key is pressed
            delay();
            printf("9\n");
        }

        // Check C4 (PC11) low or high
        if (!(*pInputDataReg & (1 << 11))) {
            // Key is pressed
            delay();
            printf("C\n");
        }

        // Make all rows HIGH
        *pOutputDataReg |= 0xF; // Set PC0~PC3 HIGH
        // Make R4 LOW (PC3)
        *pOutputDataReg &= ~(1 << 3);

        // Scan the columns
        // Check C1 (PC8) low or high
        if (!(*pInputDataReg & (1 << 8))) {
            // Key is pressed
            delay();
            printf("*\n");
        }

        // Check C2 (PC9) low or high
        if (!(*pInputDataReg & (1 << 9))) {
            // Key is pressed
            delay();
            printf("0\n");
        }

        // Check C3 (PC10) low or high
        if (!(*pInputDataReg & (1 << 10))) {
            // Key is pressed
            delay();
            printf("#\n");
        }

        // Check C4 (PC11) low or high
        if (!(*pInputDataReg & (1 << 11))) {
            // Key is pressed
            delay();
            printf("D\n");
        }
    } // while end
}
