/**
  * @file   main.c
  * @author won.seok.django@gmail.com
  * @brief  skeleton code for measuring rpi3 bare metal execution time.
  */
typedef char s08t;
typedef unsigned char u08t;

typedef int s32t;
typedef unsigned int u32t;

/* belows are BSP constants */
#define GPIOSEL_BASE 0x3f200000
#define GPIOSET_BASE 0x3f20001c
#define GPIOCLR_BASE 0x3f200028

const u32t SEGMENT_PIN[8] = { 21, 20, 16, 26, 19, 13, 6, 5 };
const u32t SEGMENT_MAP[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f };
/* aboves are BSP constants */

/* belows are BSP functions */
void naiveDelay(u32t _dly);

void initGPIO(u32t _pin);
void writeGPIO(u32t _pin, u32t _val);

void initSegment(void);
void writeSegment(u32t _val);
/* aboves are BSP functions */

s32t main(void)
{
    u32t num;

    initSegment();
    for (num = 0; num < 10; ++num)
    {
        writeSegment(num);
        naiveDelay(10000);
    }

    while (1)
    {

    }

    return 0;
}

void naiveDelay(u32t _dly)
{
    u32t it;

    for (it = 0; it < _dly; ++it);
}

void initGPIO(u32t _pin)
{
    u32t* base = (u32t*)GPIOSEL_BASE;

    base[_pin / 10] &= ~(7 << (_pin % 10) * 3);
    base[_pin / 10] |=  (1 << (_pin % 10) * 3);
}

void writeGPIO(u32t _pin, u32t _val)
{
    u32t* base = (_val != 0) ? (u32t*)GPIOSET_BASE : (u32t*)GPIOCLR_BASE;

    base[_pin / 32] |= (1 << (_pin % 32)); 
}

void initSegment(void)
{
    u32t seg;

    for (seg = 0; seg < 8; ++seg)
    {
        initGPIO(SEGMENT_PIN[seg]);
        writeGPIO(SEGMENT_PIN[seg], 0);
    }

}

void writeSegment(u32t _val)
{
    u32t seg;

    for (seg = 0; seg < 8; ++seg)
    {
        writeGPIO(SEGMENT_PIN[seg], SEGMENT_MAP[_val] & (1 << seg));
    }
}
