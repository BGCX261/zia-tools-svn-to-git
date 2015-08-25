#ifndef FUNCTION_INTERNAL_HPP
#define FUNCTION_INTERNAL_HPP

#include "TraitsCall.hpp"
#include <iostream>

namespace binder
{
	template <typename Tret>
	struct FunctionBase
	{
		virtual Tret call(void) = 0;
		virtual FunctionBase* clone() const = 0;
	};


	template <typename Tret, typename Tclass, typename Tinstance, typename Tcalltype1, typename Tparam1>
	class FunctionInternal 
		: public FunctionBase<Tret>
	{
	public:

		FunctionInternal(Tret (Tclass::*method)(Tcalltype1), Tinstance instance, Tparam1 p1)
			: FunctionBase<Tret>(), _method(method), _instance(instance), _p1(p1)
		{

		}

		FunctionInternal(Tret (Tclass::*method)(Tcalltype1), Tinstance instance)
			: _method(method), _instance(instance)
		{

		}

		~FunctionInternal()
		{

		}

		FunctionInternal(const FunctionInternal& ref)
			: FunctionBase<Tret>(), _method(ref._method), _instance(ref._instance), _p1(ref._p1)
		{
		
		}

		FunctionInternal& operator=(const FunctionInternal& ref)
		{
			if (this != &ref)
			{
				FunctionInternal tmp(ref);
				std::swap(tmp._instance, this->_instance);
				std::swap(tmp._method, this->_method);
				std::swap(tmp._p1, this->_p1);
			}
			return *this;
		}

		void	setParam(Tparam1 p1)
		{
			this->_p1 = p1;
		}

		Tret	call(void)
		{
			return binder::TraitsCall<Tret, Tclass, Tinstance, Tcalltype1, Tparam1>::call(this->_method, this->_instance, this->_p1);
		}
		
		void	release(void)
		{
			*this = FunctionInternal();
		}

		FunctionBase<Tret>*	clone() const
		{
			return new FunctionInternal(*this);
		}
		

	private:
		FunctionInternal()
			: _method(0), _instance(0), _p1(0)
		{
			

		}
		Tret	    (Tclass::*_method)(Tcalltype1);
		Tinstance   _instance;
		Tparam1	    _p1;
	};



}


#endif