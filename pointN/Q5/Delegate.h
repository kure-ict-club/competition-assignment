#pragma once

#include "DelegateBase.h"

template <class T>
class Delegate : public DelegateBase {
public:
	Delegate() {};
	virtual ~Delegate() {};
	virtual void operator()(int value) {
		(m_obj->*m_func)(value);
	}
	typedef void (T::*EventFunc)(int);
	void set(T* obj, EventFunc func) {
		m_obj = obj;
		m_func = func;
	}
	static DelegateBase* createDelegator(T* obj, void (T::*func)(int)) {
		Delegate* dg = new Delegate;
		dg->set(obj, func);
		return dg;
	}
protected:
	T* m_obj;
	EventFunc m_func;
};
