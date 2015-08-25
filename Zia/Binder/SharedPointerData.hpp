#ifndef SHARED_POINTER_DATA
#define SHARED_POINTER_DATA

#include <iostream>
namespace ptr
{
  template<typename T, typename RefCounter> 
  class SharedPointerData : public RefCounter
  {
    T*	data;
    
    public:
      
      SharedPointerData(T* dt)
      : RefCounter()
      {
			data = dt;
      }
      
      ~SharedPointerData() 
      {
		std::cout << "DELETE" << std::endl;
		delete this->data;
      }
      
      T* get()
      {
		return this->data;
      }
  };
};

#endif