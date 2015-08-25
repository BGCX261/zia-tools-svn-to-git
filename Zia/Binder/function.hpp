#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "FunctionInternal.hpp"


namespace binder
{
	template<typename Tret>
	class	function;

	template<typename Tret>
	class	function<Tret ()>
	{
	public:
		function()
			: _base(0)
		{

		}

		~function()
		{
			if (this->_base != 0)
				delete this->_base;
		}

		function(const function<Tret ()>& other)
		{
			if (other._base != 0)
				this->_base = other._base->clone();
			else
				this->_base = 0;
		}

		function<Tret()>& operator=(const function<Tret()>& ref)
		{
			function tmp(ref);
			std::swap(tmp._base, this->_base);
			return *this;
		}

		Tret	operator()()
		{
			if (this->isSet() == false)
				throw std::exception("fonction can't be called because, it's empty!");
			return this->_base->call();
		}

		bool	isSet() const
		{
			return this->_base > 0;
		}


		void	setBase(binder::FunctionBase<Tret>* base)
		{
			this->_base = base;
		}

		void	clear()
		{
			this->_base.release();
		}

	private:
		FunctionBase<Tret>*  _base;
	};

}


#endif