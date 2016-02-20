//
//  observer.hpp
//  test
//
//  Created by nrdwnd on 2/20/16.
//  Copyright © 2016 bootstat. All rights reserved.
//

#ifndef observer_h
#define observer_h

#include "StandardCplusplus.h"
#include "Arduino.h"
#include <vector>

using std::vector;

class IOListener
{
public:
  virtual void notify(const long long) { }
  virtual void notify(const double) { }
  virtual void notify(const float) { }
  virtual void notify(const int) { }
  virtual void notify(const bool) { }
  virtual void notify(const String) { }
};

class Broadcaster
{
protected:
    vector<IOListener*> observers;
public:
  virtual void broadcast() = 0;
  void subscribe(IOListener* _) {
    observers.push_back(_);
  }
};

#endif /* observer_h */
