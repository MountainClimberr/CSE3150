#ifndef _TIMESHAREDPTR_H 
#define _TIMESHAREDPTR_H


#include <iostream>
#include <cstddef>
#include <chrono>
#include <utility>
#include <thread>

using namespace std;

using Clock = chrono::high_resolution_clock;
typedef chrono::time_point<chrono::high_resolution_clock> clockTime;
typedef chrono::milliseconds milliSeconds;

struct ControlTimedSharedPtr {
  void *          ptr;
  long            myUseCount;
  clockTime       TimedSharedPtrStartTime;
  milliSeconds    deletePtrInMs;

  ControlTimedSharedPtr(void * p, long deleteMeInMilliseconds) : 
    ptr(p), 
    myUseCount(1),
    TimedSharedPtrStartTime(Clock::now()),
    deletePtrInMs{chrono::milliseconds(deleteMeInMilliseconds)} { 
      cout << "ControlTimedSharedPtr " << static_cast<void *>(ptr)
           << " start: " << chrono::duration_cast<chrono::milliseconds>(chrono::milliseconds(0)).count() 
           << " ms " << endl;
  }

  ~ControlTimedSharedPtr() {
    cout << "ControlTimedSharedPtr " << static_cast<void *>(ptr)
         << " end: " 
         << chrono::duration_cast<chrono::milliseconds>(
            Clock::now().time_since_epoch() - TimedSharedPtrStartTime.time_since_epoch()).count() 
         << " ms " << endl;
  }
};



template<typename T>
class TimedSharedPtr {

  private:
      ControlTimedSharedPtr* _ptrToControl;

  public:

  TimedSharedPtr() : _ptrToControl(nullptr) {}

  TimedSharedPtr(T* raw, long deleteMeInMilliseconds ) 
    : _ptrToControl( new ControlTimedSharedPtr(raw, deleteMeInMilliseconds) )
  {}

  TimedSharedPtr( T * raw ) : _ptrToControl( new ControlTimedSharedPtr(raw, 1000) ) // DEFAULT to 1000 milliseconds if No second parameter given
  {}

  //copy constructor increments myUseCount 
  TimedSharedPtr(const TimedSharedPtr& other) : _ptrToControl(other._ptrToControl){
    if (_ptrToControl) {
      ++_ptrToControl->myUseCount;
    }
  }

  //copy assignment
  TimedSharedPtr& operator=(const TimedSharedPtr& other){
    if(this != &other){
      //if the current obj is managing something and is the last user;
      if (_ptrToControl && --_ptrToControl->myUseCount == 0) {
        //delete the raw pointer and control to release ownership
        delete static_cast<T*>(_ptrToControl->ptr);
        delete _ptrToControl;
      }
      //point both objects to the same resource and increment use count
      _ptrToControl = other._ptrToControl;
      if(_ptrToControl){
        ++_ptrToControl->myUseCount;
      }
    }
    return *this;
  }


  long use_count() const noexcept {
      return _ptrToControl ? _ptrToControl->myUseCount : 0;
  }

  T* get() const {
      auto milliseondsSinceStart = Clock::now().time_since_epoch() - _ptrToControl->TimedSharedPtrStartTime.time_since_epoch();
      if (milliseondsSinceStart > _ptrToControl->deletePtrInMs ) {
          cout << "Yeo! Expired " ;
          return nullptr;
      } else {
          return _ptrToControl ? static_cast<T*>(_ptrToControl->ptr) : nullptr;
      }
  }

  ~TimedSharedPtr() {   
    //delete _ptrToControl; // Must account for multiple owners!  Check myUseCount in Control...
    //if the pointer is the last user, delete the raw and control
    if (_ptrToControl && --_ptrToControl->myUseCount == 0) {
      delete static_cast<T*>(_ptrToControl->ptr);
      delete _ptrToControl;
      
    }
  }
};


struct Node {
  Node(int v) : val{v} {};
  int val;
  TimedSharedPtr<Node> next;
};

#endif // !DEBUG
