#pragma once
template<typename ... Args>
class DelegateAction
{
public: virtual void operator()(Args... value)const noexcept = 0;
};

