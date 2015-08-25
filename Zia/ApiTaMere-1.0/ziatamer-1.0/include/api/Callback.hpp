#ifndef _ZIA_API_CALLBACK_H_
#define _ZIA_API_CALLBACK_H_

#include "defines.hpp"

namespace zia{
	namespace api{

		template <typename T>
		class Callback;

	# define ZIA_CALLBACK_GEN(_TN_TARGS, _TARGS, _CTARGS, _TN_ARGS, _CTN_ARGS, _ARGS, _CARGS) \
	template <typename R _TN_TARGS>                                         \
		class Callback<R (_TARGS)>                                              \
		{                                                                       \
		public:                                                                 \
		template <typename T>                                                 \
		struct Traits                                                         \
		{                                                                   \
		typedef R			(T::*Method)(_TARGS);						    \
		};                                                                  \
		\
		typedef R			(*Funcptr)(_TARGS);									\
		\
		typedef Callback<R (_TARGS)>	This;                                   \
		typedef R			(*CallerPtr)(void * _CTARGS);						\
		\
		inline Callback()                                                     \
		: mInstance(0), mCaller(0)                                          \
		{}                                                                  \
		\
		template <typename T, typename Traits<T>::Method method>              \
		inline static This		create(T* instance)							\
		{                                                                   \
		return (This(instance, &caller<T, method>));                      \
		}                                                                   \
		\
		inline static This		create(CallerPtr func, void* param = 0)		\
		{                                                                   \
		return (This(param, func));                                       \
		}                                                                   \
		\
		inline R			operator()(_TN_ARGS)								\
		{                                                                   \
		return ((*mCaller)(mInstance _CARGS));                            \
		}                                                                   \
		\
		inline bool			isSet() const									\
		{                                                                   \
		return (mCaller != 0);                                            \
		}                                                                   \
		\
		inline void			clear()											\
		{                                                                   \
		mCaller = 0;                                                      \
		}                                                                   \
		\
		private:                                                                \
		void*				mInstance;											\
		CallerPtr			mCaller;											\
		\
		inline Callback(void *instance, CallerPtr ptr)                        \
		: mInstance(instance), mCaller(ptr)                                 \
		{}                                                                  \
		\
		template <typename T, typename Traits<T>::Method method>              \
		inline static R	caller(void* instance _CTN_ARGS)					\
		{                                                                   \
		return ((static_cast<T*>(instance)->*method)(_ARGS));             \
		}                                                                   \
		};

		ZIA_CALLBACK_GEN(,,,,,,)

#define _TN_TARGS_1     , typename TARG1
#define _TARGS_1        TARG1
#define _CTARGS_1       , TARG1
#define _TN_ARGS_1      TARG1 _arg1
#define _CTN_ARGS_1     , _TN_ARGS_1
#define _ARGS_1         _arg1
#define _CARGS_1        , _arg1
			ZIA_CALLBACK_GEN( _TN_TARGS_1, _TARGS_1, _CTARGS_1, _TN_ARGS_1, _CTN_ARGS_1, _ARGS_1, _CARGS_1 )

			// 2 parameters
#define _TN_TARGS_2     _TN_TARGS_1, 	typename TARG2
#define _TARGS_2        _TARGS_1,	TARG2
#define _CTARGS_2       _CTARGS_1, 	TARG2
#define _TN_ARGS_2      _TN_ARGS_1,	TARG2 _arg2
#define _CTN_ARGS_2     _CTN_ARGS_1, 	TARG2 _arg2
#define _ARGS_2         _ARGS_1,	_arg2
#define _CARGS_2        _CARGS_1, 	_arg2
			ZIA_CALLBACK_GEN( _TN_TARGS_2, _TARGS_2, _CTARGS_2, _TN_ARGS_2, _CTN_ARGS_2, _ARGS_2, _CARGS_2 )

			// 3 parameters
#define _TN_TARGS_3     _TN_TARGS_2, 	typename TARG3
#define _TARGS_3        _TARGS_2,	TARG3
#define _CTARGS_3       _CTARGS_2, 	TARG3
#define _TN_ARGS_3      _TN_ARGS_2,	TARG3 _arg3
#define _CTN_ARGS_3     _CTN_ARGS_2, 	TARG3 _arg3
#define _ARGS_3         _ARGS_2,	_arg3
#define _CARGS_3        _CARGS_2, 	_arg3
			ZIA_CALLBACK_GEN( _TN_TARGS_3, _TARGS_3, _CTARGS_3, _TN_ARGS_3, _CTN_ARGS_3, _ARGS_3, _CARGS_3 )

			// 4 parameters
#define _TN_TARGS_4     _TN_TARGS_3, 	typename TARG4
#define _TARGS_4        _TARGS_3,	TARG4
#define _CTARGS_4       _CTARGS_3, 	TARG4
#define _TN_ARGS_4      _TN_ARGS_3,	TARG4 _arg4
#define _CTN_ARGS_4     _CTN_ARGS_3, 	TARG4 _arg4
#define _ARGS_4         _ARGS_3,	_arg4
#define _CARGS_4        _CARGS_3, 	_arg4
			ZIA_CALLBACK_GEN( _TN_TARGS_4, _TARGS_4, _CTARGS_4, _TN_ARGS_4, _CTN_ARGS_4, _ARGS_4, _CARGS_4 )

			// 5 parameters
#define _TN_TARGS_5     _TN_TARGS_4, 	typename TARG5
#define _TARGS_5        _TARGS_4,	TARG5
#define _CTARGS_5       _CTARGS_4, 	TARG5
#define _TN_ARGS_5      _TN_ARGS_4,	TARG5 _arg5
#define _CTN_ARGS_5     _CTN_ARGS_4, 	TARG5 _arg5
#define _ARGS_5         _ARGS_4,	_arg5
#define _CARGS_5        _CARGS_4, 	_arg5
			ZIA_CALLBACK_GEN( _TN_TARGS_5, _TARGS_5, _CTARGS_5, _TN_ARGS_5, _CTN_ARGS_5, _ARGS_5, _CARGS_5 )

			// 6 parameters
#define _TN_TARGS_6     _TN_TARGS_5, 	typename TARG6
#define _TARGS_6        _TARGS_5,	TARG6
#define _CTARGS_6       _CTARGS_5, 	TARG6
#define _TN_ARGS_6      _TN_ARGS_5,	TARG6 _arg6
#define _CTN_ARGS_6     _CTN_ARGS_5, 	TARG6 _arg6
#define _ARGS_6         _ARGS_5,	_arg6
#define _CARGS_6        _CARGS_5, 	_arg6
			ZIA_CALLBACK_GEN( _TN_TARGS_6, _TARGS_6, _CTARGS_6, _TN_ARGS_6, _CTN_ARGS_6, _ARGS_6, _CARGS_6 )

			// 7 parameters
#define _TN_TARGS_7     _TN_TARGS_6, 	typename TARG7
#define _TARGS_7        _TARGS_6,	TARG7
#define _CTARGS_7       _CTARGS_6, 	TARG7
#define _TN_ARGS_7      _TN_ARGS_6,	TARG7 _arg7
#define _CTN_ARGS_7     _CTN_ARGS_6, 	TARG7 _arg7
#define _ARGS_7         _ARGS_6,	_arg7
#define _CARGS_7        _CARGS_6, 	_arg7
			ZIA_CALLBACK_GEN( _TN_TARGS_7, _TARGS_7, _CTARGS_7, _TN_ARGS_7, _CTN_ARGS_7, _ARGS_7, _CARGS_7 )

			// 8 parameters
#define _TN_TARGS_8     _TN_TARGS_7, 	typename TARG8
#define _TARGS_8        _TARGS_7,	TARG8
#define _CTARGS_8       _CTARGS_7, 	TARG8
#define _TN_ARGS_8      _TN_ARGS_7,	TARG8 _arg8
#define _CTN_ARGS_8     _CTN_ARGS_7, 	TARG8 _arg8
#define _ARGS_8         _ARGS_7,	_arg8
#define _CARGS_8        _CARGS_7, 	_arg8
			ZIA_CALLBACK_GEN( _TN_TARGS_8, _TARGS_8, _CTARGS_8, _TN_ARGS_8, _CTN_ARGS_8, _ARGS_8, _CARGS_8 )

	};
};

#endif /* _ZIA_API_CALLBACK_H_ */
