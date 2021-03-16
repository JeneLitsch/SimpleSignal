#pragma once
#include <functional>
#include <memory>

template<class ... Types>
class Connection {
public:
	Connection(std::shared_ptr<std::function<void(Types...)>> fx_){
		this->fx = fx_;
	}

	//is called by the signal
	void operator()(Types ... args) const {
		return (*std::shared_ptr(fx))(args...);
	}

	//is used to check the connection is valid
	//the same as valid() 
	operator bool() const {
		return this->valid();
	}

	//is used to check the connection is valid
	bool valid() const {
		return !this->fx.expired();
	}

private:
	std::weak_ptr<std::function<void(Types...)>> fx;
};