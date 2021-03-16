#pragma once
#include <functional>
#include <memory>
#include "Connection.hxx"
#include "Slot.hxx"
template<class ... Types>
class Signal {
public:

	//emits a signal and calls all connection
	//if a connection is invalid it will be removed
	void emit(Types... param){
		long last = this->connections.size() -1;
		for(long i = last; i >= 0; i--) {
			//get connection
			Connection<Types...> & connection = this->connections[i];

			//if connection i valid -> call the connection
			if(connection){
				connection(param...);
			}

			//remove invalid connection
			else{
				std::remove(
					this->connections.begin(),
					this->connections.end(),
					connection
				);
			}
		}
	}

	//add a new connection to a given slot to the signal
	void connect(const Slot<Types...> & slot){
		this->connections.push_back(slot.createConnection());
	}

private:
	std::vector<Connection<Types...>> connections;
};