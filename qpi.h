// Qubic Programming Interface 1.0.0

#define NUMBER_OF_COMPUTORS 676

#define NULL_ID _mm256_setzero_si256()

#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

#define WEDNESDAY 0
#define THURSDAY 1
#define FRIDAY 2
#define SATURDAY 3
#define SUNDAY 4
#define MONDAY 5
#define TUESDAY 6

typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed int sint32;
typedef unsigned int uint32;
typedef signed long long sint64;
typedef unsigned long long uint64;
typedef __m256i id;

struct bool_2
{
	uint64 values;

	inline bool get(uint32 index)
	{
		return values & (1ULL << (index & 1));
	}

	inline void set(uint32 index, bool value)
	{
		values = (values & (~(1ULL << (index & 1)))) | (((uint64)value) << (index & 1));
	}
};

struct bool_4
{
	uint64 values;

	inline bool get(uint32 index)
	{
		return values & (1ULL << (index & 3));
	}

	inline void set(uint32 index, bool value)
	{
		values = (values & (~(1ULL << (index & 3)))) | (((uint64)value) << (index & 3));
	}
};

struct bool_8
{
	uint64 values;

	inline bool get(uint32 index)
	{
		return values & (1ULL << (index & 7));
	}

	inline void set(uint32 index, bool value)
	{
		values = (values & (~(1ULL << (index & 7)))) | (((uint64)value) << (index & 7));
	}
};

struct bool_16
{
	uint64 values;

	inline bool get(uint32 index)
	{
		return values & (1ULL << (index & 15));
	}

	inline void set(uint32 index, bool value)
	{
		values = (values & (~(1ULL << (index & 15)))) | (((uint64)value) << (index & 15));
	}
};

struct bool_32
{
	uint64 values;

	inline bool get(uint32 index)
	{
		return values & (1ULL << (index & 31));
	}

	inline void set(uint32 index, bool value)
	{
		values = (values & (~(1ULL << (index & 31)))) | (((uint64)value) << (index & 31));
	}
};

struct bool_64
{
	uint64 values;

	inline bool get(uint32 index)
	{
		return values & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values = (values & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_128
{
	uint64 values[2];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_256
{
	uint64 values[4];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_512
{
	uint64 values[8];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_1024
{
	uint64 values[16];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_2048
{
	uint64 values[32];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_4096
{
	uint64 values[64];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_8192
{
	uint64 values[128];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_16384
{
	uint64 values[256];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_32768
{
	uint64 values[512];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_65536
{
	uint64 values[1024];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_131072
{
	uint64 values[2048];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_262144
{
	uint64 values[4096];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_524288
{
	uint64 values[8192];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct bool_1048576
{
	uint64 values[16384];

	inline bool get(uint32 index)
	{
		return values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (1ULL << (index & 63));
	}

	inline void set(uint32 index, bool value)
	{
		values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] = (values[(index >> 6) & (sizeof(values) / sizeof(values[0]) - 1)] & (~(1ULL << (index & 63)))) | (((uint64)value) << (index & 63));
	}
};

struct sint8_2
{
	sint8 values[2];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_4
{
	sint8 values[4];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_8
{
	sint8 values[8];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_16
{
	sint8 values[16];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_32
{
	sint8 values[32];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_64
{
	sint8 values[64];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_128
{
	sint8 values[128];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_256
{
	sint8 values[256];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_512
{
	sint8 values[512];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_1024
{
	sint8 values[1024];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_2048
{
	sint8 values[2048];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_4096
{
	sint8 values[4096];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_8192
{
	sint8 values[8192];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_16384
{
	sint8 values[16384];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_32768
{
	sint8 values[32768];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_65536
{
	sint8 values[65536];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_131072
{
	sint8 values[131072];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_262144
{
	sint8 values[262144];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_524288
{
	sint8 values[524288];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint8_1048576
{
	sint8 values[1048576];

	inline sint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_2
{
	uint8 values[2];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_4
{
	uint8 values[4];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_8
{
	uint8 values[8];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_16
{
	uint8 values[16];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_32
{
	uint8 values[32];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_64
{
	uint8 values[64];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_128
{
	uint8 values[128];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_256
{
	uint8 values[256];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_512
{
	uint8 values[512];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_1024
{
	uint8 values[1024];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_2048
{
	uint8 values[2048];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_4096
{
	uint8 values[4096];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_8192
{
	uint8 values[8192];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_16384
{
	uint8 values[16384];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_32768
{
	uint8 values[32768];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_65536
{
	uint8 values[65536];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_131072
{
	uint8 values[131072];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_262144
{
	uint8 values[262144];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_524288
{
	uint8 values[524288];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint8_1048576
{
	uint8 values[1048576];

	inline uint8 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint8 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_2
{
	sint16 values[2];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_4
{
	sint16 values[4];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_8
{
	sint16 values[8];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_16
{
	sint16 values[16];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_32
{
	sint16 values[32];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_64
{
	sint16 values[64];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_128
{
	sint16 values[128];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_256
{
	sint16 values[256];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_512
{
	sint16 values[512];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_1024
{
	sint16 values[1024];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_2048
{
	sint16 values[2048];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_4096
{
	sint16 values[4096];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_8192
{
	sint16 values[8192];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_16384
{
	sint16 values[16384];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_32768
{
	sint16 values[32768];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_65536
{
	sint16 values[65536];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_131072
{
	sint16 values[131072];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_262144
{
	sint16 values[262144];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_524288
{
	sint16 values[524288];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint16_1048576
{
	sint16 values[1048576];

	inline sint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_2
{
	uint16 values[2];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_4
{
	uint16 values[4];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_8
{
	uint16 values[8];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_16
{
	uint16 values[16];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_32
{
	uint16 values[32];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_64
{
	uint16 values[64];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_128
{
	uint16 values[128];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_256
{
	uint16 values[256];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_512
{
	uint16 values[512];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_1024
{
	uint16 values[1024];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_2048
{
	uint16 values[2048];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_4096
{
	uint16 values[4096];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_8192
{
	uint16 values[8192];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_16384
{
	uint16 values[16384];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_32768
{
	uint16 values[32768];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_65536
{
	uint16 values[65536];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_131072
{
	uint16 values[131072];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_262144
{
	uint16 values[262144];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_524288
{
	uint16 values[524288];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint16_1048576
{
	uint16 values[1048576];

	inline uint16 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint16 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_2
{
	sint32 values[2];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_4
{
	sint32 values[4];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_8
{
	sint32 values[8];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_16
{
	sint32 values[16];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_32
{
	sint32 values[32];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_64
{
	sint32 values[64];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_128
{
	sint32 values[128];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_256
{
	sint32 values[256];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_512
{
	sint32 values[512];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_1024
{
	sint32 values[1024];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_2048
{
	sint32 values[2048];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_4096
{
	sint32 values[4096];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_8192
{
	sint32 values[8192];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_16384
{
	sint32 values[16384];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_32768
{
	sint32 values[32768];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_65536
{
	sint32 values[65536];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_131072
{
	sint32 values[131072];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_262144
{
	sint32 values[262144];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_524288
{
	sint32 values[524288];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint32_1048576
{
	sint32 values[1048576];

	inline sint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_2
{
	uint32 values[2];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_4
{
	uint32 values[4];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_8
{
	uint32 values[8];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_16
{
	uint32 values[16];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_32
{
	uint32 values[32];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_64
{
	uint32 values[64];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_128
{
	uint32 values[128];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_256
{
	uint32 values[256];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_512
{
	uint32 values[512];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_1024
{
	uint32 values[1024];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_2048
{
	uint32 values[2048];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_4096
{
	uint32 values[4096];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_8192
{
	uint32 values[8192];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_16384
{
	uint32 values[16384];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_32768
{
	uint32 values[32768];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_65536
{
	uint32 values[65536];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_131072
{
	uint32 values[131072];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_262144
{
	uint32 values[262144];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_524288
{
	uint32 values[524288];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint32_1048576
{
	uint32 values[1048576];

	inline uint32 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint32 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_2
{
	sint64 values[2];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_4
{
	sint64 values[4];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_8
{
	sint64 values[8];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_16
{
	sint64 values[16];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_32
{
	sint64 values[32];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_64
{
	sint64 values[64];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_128
{
	sint64 values[128];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_256
{
	sint64 values[256];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_512
{
	sint64 values[512];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_1024
{
	sint64 values[1024];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_2048
{
	sint64 values[2048];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_4096
{
	sint64 values[4096];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_8192
{
	sint64 values[8192];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_16384
{
	sint64 values[16384];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_32768
{
	sint64 values[32768];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_65536
{
	sint64 values[65536];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_131072
{
	sint64 values[131072];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_262144
{
	sint64 values[262144];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_524288
{
	sint64 values[524288];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct sint64_1048576
{
	sint64 values[1048576];

	inline sint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, sint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_2
{
	uint64 values[2];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_4
{
	uint64 values[4];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_8
{
	uint64 values[8];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_16
{
	uint64 values[16];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_32
{
	uint64 values[32];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_64
{
	uint64 values[64];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_128
{
	uint64 values[128];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_256
{
	uint64 values[256];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_512
{
	uint64 values[512];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_1024
{
	uint64 values[1024];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_2048
{
	uint64 values[2048];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_4096
{
	uint64 values[4096];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_8192
{
	uint64 values[8192];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_16384
{
	uint64 values[16384];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_32768
{
	uint64 values[32768];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_65536
{
	uint64 values[65536];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_131072
{
	uint64 values[131072];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_262144
{
	uint64 values[262144];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_524288
{
	uint64 values[524288];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct uint64_1048576
{
	uint64 values[1048576];

	inline uint64 get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, uint64 value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_2
{
	id values[2];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_4
{
	id values[4];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_8
{
	id values[8];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_16
{
	id values[16];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_32
{
	id values[32];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_64
{
	id values[64];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_128
{
	id values[128];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_256
{
	id values[256];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_512
{
	id values[512];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_1024
{
	id values[1024];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_2048
{
	id values[2048];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_4096
{
	id values[4096];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_8192
{
	id values[8192];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_16384
{
	id values[16384];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_32768
{
	id values[32768];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_65536
{
	id values[65536];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_131072
{
	id values[131072];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_262144
{
	id values[262144];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_524288
{
	id values[524288];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

struct id_1048576
{
	id values[1048576];

	inline id get(uint32 index)
	{
		return values[index & (sizeof(values) / sizeof(values[0]) - 1)];
	}

	inline void set(uint32 index, id value)
	{
		values[index & (sizeof(values) / sizeof(values[0]) - 1)] = value;
	}
};

//////////

template <typename T>
inline T div(T a, T b)
{
	return b ? (a / b) : 0;
}

template <typename T>
inline T mod(T a, T b)
{
	return b ? (a % b) : 0;
}

//////////

id admin(
) { // Returns the identity of the admin

	return NULL_ID;
}

id computor(
	uint16 computorIndex // [0..675]
) { // Returns the identity of the computor or NULL_ID

	return NULL_ID;
}

uint8 day(
) { // [1..31]

	return 0;
}

uint8 dayOfWeek(
) { // [0..6]

	return 0;
}

uint16 epoch(
) { // [0..9'999]

	return 0;
}

uint8 hour(
) { // [0..23]

	return 0;
}

id identity(
	char* id
) {

	return NULL_ID;
}

sint64 incomingAmount(
	id id
) {

	return 0;
}

id invocation(
) {

	return NULL_ID;
}

id invocator(
) {

	return NULL_ID;
}

template <typename T, typename U>
void invoke(T input, U output) {

}

uint16 millisecond(
) { // [0..999]

	return 0;
}

uint8 minute(
) { // [0..59]

	return 0;
}

uint8 month(
) { // [1..12]

	return 0;
}

sint64 outgoingAmount(
	id id
) {

	return 0;
}

uint64 random(
) { // Returns a deterministic pseudo-random number in [0..18'446'744'073'709'551'615] range

	return 0;
}

uint8 second(
) { // [0..59]

	return 0;
}

id self(
) {

	return NULL_ID;
}

id stateDigest(
	id id
) {

	return NULL_ID;
}

uint32 tick(
) { // [0..999'999'999]

	return 0;
}

sint64 transfer( // Attempts to transfer energy from this qubic
	id destination, // The destination to transfer to, use NULL_ID to destroy the transferred energy
	sint64 amount // The amount of energy to transfer, must be in [0..1'000'000'000'000'000] range
) { // Returns the remaining amount of energy; if the value is less than 0 then the attempt has failed, in this case the absolute value equals to the insufficient amount

	return 0;
}

uint8 year(
) { // [0..99] (0 = 2000, 1 = 2001, ..., 99 = 2099)

	return 0;
}
