#pragma once

class DelegateBase {
public:
	DelegateBase() {};
	virtual ~DelegateBase() {};
	virtual void operator()(int value) = 0;
};
