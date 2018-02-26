#pragma once
#include <list>
#include "DelegateAction.h"
template<typename ... Args>
class DelegateEvent
{
private:
	std::list<std::unique_ptr<DelegateAction<Args...>>> action_list;
public:

	//add event
	void setEvent(std::unique_ptr<DelegateAction<Args...>>&& action)noexcept {
		this->action_list.push_back(std::move(action));
	}
	void operator<<(std::unique_ptr<DelegateAction<Args...>>&& action) noexcept {
		this->action_list.push_back(std::move(action));
	}
	void operator+=(std::unique_ptr<DelegateAction<Args...>>&& action) noexcept {
		this->action_list.push_back(std::move(action));
	}

	//event clear
	void clear() noexcept {
		std::list<std::unique_ptr<DelegateAction<Args...>>>().swap(action_list);
	}

	//OnEventList
	void operator()(Args... value)const noexcept {
		for (auto& action : action_list)
			(*action)(value...);
	}

};

