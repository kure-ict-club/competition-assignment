#pragma once
#include <list>


class DoorBell {
public:
	void setOnOpenDoorHandler(DelegateBase* db) {
		m_eventlist.push_back(db);
	}
	void onOpenDoor() {
		std::list<DelegateBase*>::iterator it = m_eventlist.begin();
		std::list<DelegateBase*>::iterator end = m_eventlist.end();
		for (; it != end; it++) {
			DelegateBase* ptr = (*it);
			(*ptr)(0);
		}
	}
private:
	std::list<DelegateBase*> m_eventlist;
};
