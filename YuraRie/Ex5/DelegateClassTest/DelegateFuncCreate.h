#pragma once

#include <memory>
#include "DelegateAction.h"
template<typename ... Args>
class DelegateFuncCreate : public DelegateAction<Args...>
{
protected:
	void(*m_func)(Args...);
	void set(void(*func)(Args...)) noexcept {
		m_func = func;
	}

public:

	virtual void operator()(Args... value)const noexcept {
		(m_func)(value ...);
	}

	static std::unique_ptr<DelegateAction<Args...>> create(void (*func)(Args...))noexcept {
		std::unique_ptr<DelegateFuncCreate> ptr = std::make_unique<DelegateFuncCreate>();
		ptr->set(func);
		return std::move(ptr);
	}
};