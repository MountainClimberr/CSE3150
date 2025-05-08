#ifndef TIMED_SHARED_PTR_H
#define TIMED_SHARED_PTR_H

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

using Clock = chrono::high_resolution_clock;
typedef chrono::time_point<chrono::high_resolution_clock> clockTime;
typedef chrono::milliseconds milliSeconds;

struct Node{
  int val;
  Node(int v) : val{v} {}
};

struct ControlTimedSharedPtr{
  void*         ptr;
  long          myUseCount;
  clockTime     TimedSharedPtrStartTime;
  milliSeconds  deletePtrInMs;

  // constructor
  ControlTimedSharedPtr(void* p, long deleteMeInMilliseconds) 
    : ptr(p), 
      myUseCount(1),
      TimedSharedPtrStartTime(Clock::now()),
      deletePtrInMs{chrono::milliseconds(deleteMeInMilliseconds)} 
  { 
    cout << "ControlTimedSharedPtr " << static_cast<void*>(ptr)
        << " start: " 
        << chrono::duration_cast<chrono::milliseconds>(chrono::milliseconds(0)).count() 
        << " ms " << endl;
  }

  // destructor
  ~ControlTimedSharedPtr(){
    cout << "ControlTimedSharedPtr " << static_cast<void*>(ptr)
        << " end: " 
        << chrono::duration_cast<chrono::milliseconds>(
          Clock::now().time_since_epoch() - TimedSharedPtrStartTime.time_since_epoch()
        ).count() 
        << " ms " << endl;
  }
};

template<typename T>
class TimedSharedPtr{
  private:
    ControlTimedSharedPtr* _ptrToControl;

  public:

  TimedSharedPtr() : _ptrToControl(nullptr){}

  TimedSharedPtr(T* raw, long deleteMeInMilliseconds) 
    : _ptrToControl(new ControlTimedSharedPtr(raw, deleteMeInMilliseconds)){}

  TimedSharedPtr(T* raw) 
    : _ptrToControl(new ControlTimedSharedPtr(raw, 1000)){} // DEFAULT to 1000 milliseconds

  TimedSharedPtr(const TimedSharedPtr& other) 
    : _ptrToControl(other._ptrToControl){
    if (_ptrToControl){
      _ptrToControl->myUseCount++;
    }
  }

  // copy assignment operator
  TimedSharedPtr& operator=(const TimedSharedPtr& other){
    // we check for self-assignment
    if (this != &other){
      // we decrement the use count of the current object
      if (_ptrToControl){
        _ptrToControl->myUseCount--;
        if (_ptrToControl->myUseCount == 0){
          delete _ptrToControl;
        }
      }
      
      // we copy the data from the other object
      _ptrToControl = other._ptrToControl;
      
      // and we increment the use count
      if (_ptrToControl){
        _ptrToControl->myUseCount++;
      }
    }
    return *this;
  }

  long use_count() const noexcept{
    return _ptrToControl ? _ptrToControl->myUseCount : 0;
  }

  T* get() const{
    if (!_ptrToControl){
      return nullptr;
    }
    auto milliseondsSinceStart = Clock::now().time_since_epoch() - _ptrToControl->TimedSharedPtrStartTime.time_since_epoch();
    if (milliseondsSinceStart > _ptrToControl->deletePtrInMs ){
      cout << "Yeo! Expired " ;
      return nullptr;
    } else{
      return static_cast<T*>(_ptrToControl->ptr);
    }
  }

  // delete _ptrToControl
  ~TimedSharedPtr(){   
    if (_ptrToControl && --_ptrToControl->myUseCount == 0){
      delete _ptrToControl;
    }
  }
};

#endif