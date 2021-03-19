# SimpleSignal
A simple signal system I made for my current game project.

## Slot<Types...>
- non copyable

#### Slot(const std::function & fx)
  Creates a new slot with fx as callback function.<br/>
  "fx" is called if an connected signal is emitted.<br/>

#### void changeFunction(const std::function & fx)
  Changes function <br/> 
  note: Invalidates all connections to this slot.<br/>

#### Connections createConnection()
  Creates a Connection to Slot.<br/>
  Is used by signal in connect(Slot).<br/>
 
  
## Connections<Types...> 
 
#### Connections(std::shared_ptr<std::function<void(Types...)>> fx_)
  Creates a Connection with a weak-ptr to fx_<br/>

#### operator(...)
  Calls function.<br/>
  warning: It's unchecked please use valid() before.<br/>
  
#### bool valid() and operator bool()
  "valid()" return true if connected slot is still connected and if fx can safely be called.<br/>
  In case of an issues false is returned.<br/>
  
## Signal<Types...>

#### void emit(...)
  Calls all valid connections and clean up invalid ones additonally<br/>

#### void connect(const Slot &)
  Connects signal to a slot.<br/>
  Don't allow duplicate connections.<br/>
  If a slot is already connected this function returns without adding a second connection.<br/>
  note: Slot::createConnections is nonetheless but returned Connection is discarded.<br/>
