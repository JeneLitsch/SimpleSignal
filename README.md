# SimpleSignal
A simple signal system I made for my current game project.

## Types...
Types... are the parameter of the signal.

## Slot<Types...>
- non copyable
#### Slot(const std::function & fx)
  Creates a new slot with fx as callback function.<br/>
  "fx" is called if a connected signal is emitted.<br/>
#### void changeFunction(const std::function & fx)
  Changes function <br/> 
  NOTE: Invalidates all connections to this slot.<br/>
#### Connections createConnection()
  Creates a new Connection to the Slot.<br/>
  Is used by signal in connect(Slot).<br/>
 
  
## Connections<Types...> 
#### Connections(std::shared_ptr<std::function<void(Types...)>> fx_)
  Creates a Connection with a weak-ptr to fx_<br/>
#### operator(Types...)
  Calls function.<br/>
  WARNING: It's unchecked please use valid() before.<br/>
#### bool valid() and operator bool()
  "valid()" returns true if connected slot is still connected and if fx can safely be called.<br/>
  In case of an issues false is returned.<br/>
  
## Signal<Types...>
#### void emit(...)
  Calls all valid connections and cleans up invalid ones<br/>
#### void connect(const Slot &)
  Connects signal to a slot.<br/>
  Don't allow duplicate connections.<br/>
  If a slot is already connected this function returns without adding a second connection.<br/>
  NOTE: Slot::createConnections is called nonetheless but returned Connection is discarded.<br/>
