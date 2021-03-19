# SimpleSignal
A simple signal system I made for my current game project.

## Slot<Types...>
- non copyable

#### Slot(const std::function & fx)
  creates a new slot with fx as callback function
  fx is called if an connected signal is emitted

#### void changeFunction(const std::function & fx)
  changes function 
  note: invalidates all connections to this slot

#### Connections createConnection()
  creates a Connection to Slot
  used by signal in connect(Slot)
 
  
## Connections<Types...> 
 
#### Connections(std::shared_ptr<std::function<void(Types...)>> fx_)<br/>
  creates a Connection with a weak-ptr to fx_<br/>

#### operator(...)
  Calls function<br/>
  warning: it's unchecked please use valid() before<br/>
  
#### bool valid() and operator bool()
  return true if connected slot is still connected and if fx can safely be called<br/>
  In case of an issues false is returned<br/>
  
## Signal<Types...>

void emit(...)
  calls all valid connections and clean up invalid ones additonally<br/>

#### void connect(const Slot &)
  connects signal to a slot<br/>
  don't allow duplicate connections<br/>
  if a slot is already connected this function returns without adding a second connection<br/>
  note: Slot::createConnections is nonetheless but returned Connection is discarded<br/>
