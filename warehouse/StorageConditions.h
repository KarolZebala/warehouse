#pragma once
class StorageConditions
{
public:
	int getMinValue() {
		return this->MinValue;
	}
	int getMaxValue() {
		return this->MaxValue;
	}
protected: 
	int MinValue;
	int MaxValue;

};

