// Qubic Programming Interface 0.0.3

#define NUMBER_OF_COMPUTORS 676
#define ADMIN_INDEX NUMBER_OF_COMPUTORS

#define NULL_ID nullptr

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

bool get1(long long map, long long domain, long long key) {

	return 0;
}

bool get1(long long map, long long domain, void* key) {

	return 0;
}

bool get1(long long map, long long key) {

	return get1(map, 0, key);
}

bool get1(long long map, void* key) {

	return get1(map, 0, key);
}

bool get1(long long map) {

	return get1(map, (long long)0);
}

char get8(long long map, long long domain, long long key) {

	return 0;
}

char get8(long long map, long long domain, void* key) {

	return 0;
}

char get8(long long map, long long key) {

	return get8(map, 0, key);
}

char get8(long long map, void* key) {

	return get8(map, 0, key);
}

char get8(long long map) {

	return get8(map, (long long)0);
}

short get16(long long map, long long domain, long long key) {

	return 0;
}

short get16(long long map, long long domain, void* key) {

	return 0;
}

short get16(long long map, long long key) {

	return get16(map, 0, key);
}

short get16(long long map, void* key) {

	return get16(map, 0, key);
}

short get16(long long map) {

	return get16(map, (long long)0);
}

int get32(long long map, long long domain, long long key) {

	return 0;
}

int get32(long long map, long long domain, void* key) {

	return 0;
}

int get32(long long map, long long key) {

	return get32(map, 0, key);
}

int get32(long long map, void* key) {

	return get32(map, 0, key);
}

int get32(long long map) {

	return get32(map, (long long)0);
}

long long get64(long long map, long long domain, long long key) {

	return 0;
}

long long get64(long long map, long long domain, void* key) {

	return 0;
}

long long get64(long long map, long long key) {

	return get64(map, 0, key);
}

long long get64(long long map, void* key) {

	return get64(map, 0, key);
}

long long get64(long long map) {

	return get64(map, (long long)0);
}

void* get256(long long map, long long domain, long long key) {

	return NULL_ID;
}

void* get256(long long map, long long domain, void* key) {

	return NULL_ID;
}

void* get256(long long map, long long key) {

	return get256(map, 0, key);
}

void* get256(long long map, void* key) {

	return get256(map, 0, key);
}

void* get256(long long map) {

	return get256(map, (long long)0);
}

void set1(long long map, long long domain, long long key, bool value) {
}

void set1(long long map, long long domain, void* key, bool value) {
}

void set1(long long map, long long key, bool value) {

	set1(map, 0, key, value);
}

void set1(long long map, void* key, bool value) {

	set1(map, 0, key, value);
}

void set1(long long map, bool value) {

	set1(map, (long long)0, value);
}

void set8(long long map, long long domain, long long key, char value) {
}

void set8(long long map, long long domain, void* key, char value) {
}

void set8(long long map, long long key, char value) {

	set8(map, 0, key, value);
}

void set8(long long map, void* key, char value) {

	set8(map, 0, key, value);
}

void set8(long long map, char value) {

	set8(map, (long long)0, value);
}

void set16(long long map, long long domain, long long key, short value) {
}

void set16(long long map, long long domain, void* key, short value) {
}

void set16(long long map, long long key, short value) {

	set16(map, 0, key, value);
}

void set16(long long map, void* key, short value) {

	set16(map, 0, key, value);
}

void set16(long long map, short value) {

	set16(map, (long long)0, value);
}

void set32(long long map, long long domain, long long key, int value) {
}

void set32(long long map, long long domain, void* key, int value) {
}

void set32(long long map, long long key, int value) {

	set32(map, 0, key, value);
}

void set32(long long map, void* key, int value) {

	set32(map, 0, key, value);
}

void set32(long long map, int value) {

	set32(map, (long long)0, value);
}

void set64(long long map, long long domain, long long key, long long value) {
}

void set64(long long map, long long domain, void* key, long long value) {
}

void set64(long long map, long long key, long long value) {

	set64(map, 0, key, value);
}

void set64(long long map, void* key, long long value) {

	set64(map, 0, key, value);
}

void set64(long long map, long long value) {

	set64(map, (long long)0, value);
}

void set256(long long map, long long domain, long long key, void* value) {
}

void set256(long long map, long long domain, void* key, void* value) {
}

void set256(long long map, long long key, void* value) {

	set256(map, 0, key, value);
}

void set256(long long map, void* key, void* value) {

	set256(map, 0, key, value);
}

void set256(long long map, void* value) {

	set256(map, (long long)0, value);
}

long long add(long long a, long long b) {

	return a + b;
}

long long sub(long long a, long long b) {

	return a - b;
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

unsigned long long random(
) { // Returns a deterministic pseudo-random number in [0..18446744073709551615] range

	return 0;
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

	void*				self;			// Non-zero value
} system;

void* environment(
) {

	return NULL_ID;
}

void* entity(
) {

	return NULL_ID;
}

void* effect(
) {

	return NULL_ID;
}

void* id(
	char* id
) {

	return NULL_ID;
}

void* computorId(
	unsigned short computorIndex, // Returns NULL_ID for "676", use "adminId()" to get the identity of the admin
	unsigned short epoch // Must be "system.epoch" now
) { // Returns the identity of the computor or NULL_ID

	return NULL_ID;
}

void* adminId(
) { // Returns the identity of the admin

	return NULL_ID;
}

long long energy(
	void* id
) {

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
