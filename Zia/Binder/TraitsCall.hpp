#ifndef TRAITS_CALL_HPP
#define TRAITS_CALL_HPP

#include "ReferenceContainer.hpp"

namespace binder
{
	template <typename Tret, typename Tclass, typename Tinstance, typename Tcalltype1, typename Tparam1>
	struct TraitsCall
	{
		static Tret	call(Tret (Tclass::*method)(Tcalltype1), Tinstance instance, Tparam1 p1)
		{
			return (instance.*method)(p1);
		}
	};

	template <typename Tret, typename Tclass, typename Tinstance, typename Tcalltype1, typename Tparam1>
	struct TraitsCall<Tret, Tclass, Tinstance*, Tcalltype1, Tparam1>
	{
		static Tret	call(Tret (Tclass::*method)(Tcalltype1), Tinstance* instance, Tparam1 p1)
		{
			return (instance->*method)(p1);
		}
	};

	template <typename Tret, typename Tclass, typename Tinstance, typename Tcalltype1, typename Tparam1>
	struct TraitsCall<Tret, Tclass, binder::ReferenceContainer<Tinstance>, Tcalltype1, Tparam1>
	{
		static Tret	call(Tret (Tclass::*method)(Tcalltype1), binder::ReferenceContainer<Tinstance> instance, Tparam1 p1)
		{
			return (instance.getReference().*method)(p1);
		}
	};
}
#endif