#pragma once
#include <memory>
#include <functional>
#include "Connection.hxx"
#include <iostream>
template<class ... Types>
class Slot {
public:
	//no function specified;
	Slot() {
		this->fx = std::shared_ptr<std::function<void(Types...)>>();
	}

 	Slot( const Slot& ) = delete; // non copyable
    Slot& operator=( const Slot& ) = delete; // non copyable

	//fx is a callback function which is called when a connected signal is emited
	//to be safe it has to a method of the object which owns the slot or a free function 
	Slot(const std::function<void(Types...)> & fx){
		changeFunction(fx);
	}

	//changes function and invalidates all connection
	void changeFunction(const std::function<void(Types...)> & fx){
		this->fx = std::make_shared<std::function<void(Types...)>>(fx);
	}

	//creates a connection is used by the signal in connect()
	Connection<Types...> createConnection() const{
		return Connection<Types...>(fx);
	}
private:

	std::shared_ptr<std::function<void(Types...)>> fx;
};