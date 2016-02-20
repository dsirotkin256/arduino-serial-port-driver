//
//  command.hpp
//  test
//
//  Created by nrdwnd on 2/20/16.
//  Copyright © 2016 bootstat. All rights reserved.
//

#ifndef command_h
#define command_h

#include "StandardCplusplus.h"
#include <vector>
#include "Arduino.h"

namespace commands {
  const String 
  turnOnBlueLight  = "blue_led::on",
  turnOffBlueLight = "blue_led::off",
  pushButton       = "button::push",
  releaseButton    = "button::release";
}

using std::vector;

class CommandInterface
{
protected:
  String _name;
public:
  CommandInterface(const String name) : _name(name) { }
  virtual void execute() = 0;
  String name() const {
    return _name;
  }
};

template <class T>
class Command: public CommandInterface
{
private:
  T* object;
  void(T::*callback)();
public:
  Command(const String name, T* t, void(T::*cb)())     
   : CommandInterface(name), object(t), callback(cb) { }
  void execute() {
    (object->*callback)();
  }
};

/*
 * Container: vector
 * Stores: Initialized commands
 */

vector<CommandInterface*> cmds;


/*
 * Name: executeCommand
 * Signature: String
 * Return type: void
 * Aim: Execute client request on particular object method
 * Objective: Check requested command exists
 * in the list of registered commands and.
 */

void executeCommand(const String command) {
  for (auto cmd : cmds) {
    if (cmd->name() == command) {
      cmd->execute();
      break;
    }
  }
}


#endif /* command_h */
