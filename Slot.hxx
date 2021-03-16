#pragma once
#include <memory>
#include <functional>
#include "Connection.txx"
template<class ... Types>
class Slot {
public:
	
	//fx is a callback function which is called when a connected signal is emited
	//to be safe it has to a method of the object which owns the slot or a free function 
	Slot(const std::function<void(Types...)> & fx){
		this->fx = std::make_shared<std::function<void(Types...)>>(fx);
	}

private:
	//creates a connection is used by the signal in connect()
	Connection<Types...> createConnection() const{
		return Connection<Types...>(fx);
	}

	std::shared_ptr<std::function<void(Types...)>> fx;
};