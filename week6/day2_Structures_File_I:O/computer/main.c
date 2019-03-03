#include "computer.h"

int main()
{

    struct computer lenovo_thinkpad;
    lenovo_thinkpad.cpu_speed_GHz = 3.40;
    lenovo_thinkpad.ram_size_GB = 8;
    lenovo_thinkpad.bits = 64;

    notebook_t macbook_air;
    macbook_air.cpu_speed_GHz = 1.8;
    macbook_air.ram_size_GB = 8;
    macbook_air.bits = 64;

    printf("The Lenovo Thinkpad: CPU speed: %.2f RAM size: %d Bits: %d",
           lenovo_thinkpad.cpu_speed_GHz,
           lenovo_thinkpad.ram_size_GB,
           lenovo_thinkpad.bits);
    printf("\n");
    printf("The Macbook Air: CPU speed: %.2f RAM size: %d Bits: %d",
           macbook_air.cpu_speed_GHz,
           macbook_air.ram_size_GB,
           macbook_air.bits);
    return 0;
}

