#ifndef BIND_HPP
#define BIND_HPP

#include "function.hpp"
#include "ReferenceContainer.hpp"
#include "FunctionInternal.hpp"

namespace binder
{
  template <typename Tret, typename Tclass, typename Tinstance, typename Tcalltype1, typename Tparam1>
  binder::function<Tret ()>    bind(Tret (Tclass::*method)(Tcalltype1), Tinstance instance, Tparam1 p1)
  {
    binder::function<Tret ()>	function;
    binder::FunctionBase<Tret>* internal_fct(new binder::FunctionInternal<Tret, Tclass, Tinstance, Tcalltype1, Tparam1>(method, instance, p1));
	function.setBase(internal_fct);
	return function;
  }
}

#endif