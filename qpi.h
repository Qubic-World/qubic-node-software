// Qubic Programming Interface 0.0.0

#define NUMBER_OF_COMPUTORS 676
#define ADMIN_INDEX NUMBER_OF_COMPUTORS

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

#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

#define MAX_TIMESTAMP_VALUE 9223372036854775807

#define MIN_ENERGY_AMOUNT 1000000
#define MAX_ENERGY_AMOUNT 9223372036854775807

long long add(long long a, long long b) {

	return a + b;
}

long long sub(long long a, long long b) {

	return a + b;
}

long long mul(long long a, long long b) {

	return a * b;
}

long long div(long long a, long long b) {

	return b == 0 ? 0 : a / b;
}

long long mod(long long a, long long b) {

	return b == 0 ? 0 : a % b;
}

struct System {

	unsigned long long	timestamp;		// [0..9223372036854775807]

	unsigned short		computorIndex;	// [0..676] (Always 676 for smart contracts)
	unsigned short		epoch;			// [0..32767]
	unsigned int		tick;			// [0..2147483647]
	unsigned int		iteration;		// [0..2147483647]

	unsigned short		year;			// [2001..2100]
	unsigned char		month;			// [1..12]
	unsigned char		day;			// [1..31]
	unsigned char		dayOfWeek;		// [0..6]
	unsigned char		hour;			// [0..23]
	unsigned char		minute;			// [0..59]
	unsigned char		second;			// [0..60] ("60" is not a typo, see https://en.wikipedia.org/wiki/Leap_second)
	unsigned int		nanosecond;		// [0..999999999]

	char*				self;			// Non-zero value
} system;

char* computorId(
	unsigned short computorIndex, // Returns NULL_ID for "676", use "adminId()" to get the identity of the admin
	unsigned short epoch // Must be "system.epoch" now
) { // Returns the identity of the computor or NULL_ID

	return nullptr;
}

char* adminId(
) { // Returns the identity of the admin

	return nullptr;
}

unsigned long long random(
) { // Returns a deterministic pseudo-random number in [0..18446744073709551615] range

	return 0;
}

long long send( // Attempts to send a message
	void* destination, // The destination to send to, use NULL_ID to broadcast
	unsigned long long timestamp, // In the most cases "system.timestamp" suits well enough
	unsigned long long messageSize, // Message size in bytes
	void* message // Message "struct"
) {

	return 0;
}

long long transfer( // Attempts to transfer energy from this qubic
	void* destination, // The destination to transfer to, use NULL_ID to destroy the transferred energy
	unsigned long long timestamp, // In the most cases "system.timestamp" suits well enough
	long long amount // The amount of energy to transfer, must be in [MIN_ENERGY_AMOUNT..MAX_ENERGY_AMOUNT] range despite of being a signed type
) { // Returns the remaining amount of energy; if the value is less than 0 then the transfer has failed, in this case the absolute value equals to the insufficient amount

	return 0;
}

long long affect( // Attempts to affect all entities in an environment
	void* destination, // The destination environment to affect, NULL_ID is reserved
	unsigned long long timestamp, // In the most cases "system.timestamp" suits well enough
	unsigned long long effectSize, // Effect size in bytes
	void* effect // Effect "struct"
) {

	return 0;
}

struct Void {
};
