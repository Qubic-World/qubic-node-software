using namespace QPI;

struct Qx
{
public:
	struct transfer_input
	{
	};
	struct transfer_output
	{
	};

/*private*/public:
	uint64 _earnedAmount;
	uint64 _distributedAmount;
	uint64 _burnedAmount;

	uint32 _assetIssuanceFee; // Amount of qus
	uint32 _transferFee; // Amount of qus
	uint32 _tradeFee; // Number of billionths

	PUBLIC(transfer)
	_

	REGISTER_FUNCTIONS_FOR_USERS
	_

	INITIALIZE

		// No need to initialize _earnedAmount and other variables with 0, whole contract state is zeroed before initialization is invoked

		s->_assetIssuanceFee = 1000000000;
		s->_transferFee = 1000000;
		s->_tradeFee = 5000000; // 0.5%
	_

	BEGIN_EPOCH
	_

	END_EPOCH
	_

	BEGIN_TICK
		s->_assetIssuanceFee = s->_transferFee * s->_tradeFee;
	_

	END_TICK
		s->_transferFee = s->_tradeFee + s->_assetIssuanceFee + 13;
	_
};