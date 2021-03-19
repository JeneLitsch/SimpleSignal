# SimpleSignal
A simple signal system I made for my current game project.

=== Slot<Types...> ====================================================================
- non copyable

Slot(const std::function & fx)
  creates a new slot with fx as callback function
  fx is called if an connected signal is emitted

void changeFunction(const std::function & fx)
  changes function 
  note: invalidates all connections to this slot

Connections createConnection()
  creates a Connection to Slot
  used by signal in connect(Slot)
 
  
=== Connections<Types...> ============================================================
 
Connections(std::shared_ptr<std::function<void(Types...)>> fx_)
  creates a Connection with a weak-ptr to fx_

operator(...)
  Calls function
  warning: it's unchecked please use valid() before
  
bool valid() and operator bool()
  return true if connected slot is still connected and if fx can safely be called
  In case of an issues false is returned
  
=== Signal<Types...> =================================================================

void emit(...)
  calls all valid connections and clean up invalid ones additonally

void connect(const Slot &)
  connects signal to a slot
  don't allow duplicate connections
  if a slot is already connected this function returns without adding a second connection
  note: Slot::createConnections is nonetheless but returned Connection is discarded
