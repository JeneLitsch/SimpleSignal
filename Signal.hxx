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
		long last = static_cast<long>(this->connections.size() -1);
		for(long i = last; i >= 0; i--) {

			//get connection
			std::size_t idx = static_cast<std::size_t>(i);
			Connection<Types...> & connection = this->connections[idx];

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
		Connection<Types...> newConnection = slot.createConnection();

		// prevent duplicate connections
		for(const Connection<Types...> & existingConnection : this->connections){
			if(existingConnection == newConnection){
				return;
			}
		}

		this->connections.push_back(newConnection);
	}

private:
	std::vector<Connection<Types...>> connections;
};