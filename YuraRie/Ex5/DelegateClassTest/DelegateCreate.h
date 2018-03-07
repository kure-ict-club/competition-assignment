#pragma once

#include <memory>
#include "DelegateAction.h"
template<typename T, typename ... Args>
class DelegateCreate : public DelegateAction<Args...>
{
protected:
	typedef void (T::*EventFunc)(Args...);
	T * m_obj;
	EventFunc m_func;
	void set(T* obj, const EventFunc func) noexcept{
		m_obj = obj;
		m_func = func;
	}

public:
	virtual void operator()(Args... value)const noexcept {
		(m_obj->*m_func)(value ...);
	}

	static std::unique_ptr<DelegateAction<Args...>> create(T* obj, void (T::*func)(Args...))noexcept {
		std::unique_ptr<DelegateCreate> ptr = std::make_unique<DelegateCreate>();
		ptr->set(obj, func);
		return std::move(ptr);
	}
};

//