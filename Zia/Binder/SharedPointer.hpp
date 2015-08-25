#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP


#include "BasicRefCount.h"
#include "SharedPointerData.hpp"

namespace ptr
{
	template<class T, class RefCounter = ptr::BasicRefCount> 
	class SharedPointer 
	{
		typedef SharedPointerData<T, RefCounter> Data;
		Data*	_data;

		void release()
		{
			if (this->_data) 
			{
				this->_data->decr();
				if (!this->_data->shared())
				{
					delete this->_data;
				}
				this->_data = 0;
			}
		}

	public:

		SharedPointer()
			:_data(0)
		{}

		SharedPointer(const SharedPointer<T, RefCounter>& p)
		{
			if ((this->_data = p._data)) 
				this->_data->incr();
		}

		SharedPointer(T* t)
		{
			this->_data = new Data(t);
			this->_data->incr();
		}

		~SharedPointer()
		{
			this->release();
		}

		SharedPointer<T, RefCounter> &operator=(const SharedPointer<T, RefCounter>&p)
		{
			if (this->_data == p._data) 
				return *this;
			this->release();
			if ((this->_data = p._data)) 
				this->_data->incr();
			return *this;
		}

		SharedPointer<T, RefCounter> &operator=(T* p)
		{
			if (this->_data && this->_data->get() == p)
				return *this;
			this->release();
			this->_data = new Data(p);
			this->_data->incr();
			return *this;
		}

		operator T*()const       
		{
			return this->_data->get();
		}

		T& operator*()           
		{
			return *this->_data->get();
		}

		const T& operator*() const 
		{
			return *this->_data->get();
		}

		T* operator->() 
		{  
			return this->_data->get();
		}

		const T*operator->() const
		{
			return this->_data->get();
		}

		operator bool() const 
		{ 
			return (this->_data != 0 && this->_data->get() != 0);
		}

		operator bool() 
		{ 
			return (this->_data != 0 && this->_data->get() != 0);
		}

		bool operator!() const 
		{ 
			return (this->_data == 0 || this->_data->get() == 0); 
		}

		bool operator!() 
		{ 
			return (this->_data == 0 || this->_data->get() == 0); 
		}
		long	count()
		{
			return this->_data->nbShared();
		}
	};
};

#endif