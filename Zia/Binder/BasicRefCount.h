 #ifndef REF_COUNT_H
 #define REF_COUNT_H
 
#include "IRefCounter.h"
#include <iostream>
 namespace ptr
 {
   class BasicRefCount 
	   : public ptr::IRefCounter
   {
     
     protected:
       long _refCount;
       
     public:
       
       BasicRefCount() 
       : _refCount(0)
       {
	 
       }
       
       virtual ~BasicRefCount() 
       {
	 
       }
       
       void incr() 
       {
		 ++this->_refCount;
		 std::cout << this->_refCount << std::endl;
       }
       
       bool decr()
       {
		 --this->_refCount;
		 std::cout << this->_refCount << std::endl;
		return shared();
       }
       
       bool shared() 
       { 
		return (this->_refCount > 0);
       }
       
       long	nbShared() const
       {
		return this->_refCount;
       }
   };
 };
 #endif