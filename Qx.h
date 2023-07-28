using namespace QPI;

struct Qx
{
private:
	uint64 _earnedAmount;
	uint64 _distributedAmount;
	uint64 _burnedAmount;

	uint32 _assetIssuanceFee; // Amount of qus
	uint32 _transferFee; // Amount of qus
	uint32 _tradeFee; // Number of billionths

	INITIALIZE

		// No need to initialize _earnedAmount and other variables with 0, whole contract state is zeroed before initialization is invoked

		_assetIssuanceFee = 1000000000;
		_transferFee = 1000000;
		_tradeFee = 5000000; // 0.5%
	__

	BEGIN_EPOCH
	__

	BEGIN_TICK
	__

	END_TICK
	__

	END_EPOCH
	__
};