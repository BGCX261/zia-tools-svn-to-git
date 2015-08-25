#pragma once

#include <Ws2tcpip.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

namespace ip{
	namespace detail{

		template <int Level, int Name>
		class boolean
		{
		public:
			boolean()
				: _value(0)
			{

			}

			explicit boolean(bool v)
				: _value(v ? 1 : 0)
			{
			}

			boolean& operator=(bool v)
			{
				_value = v ? 1 : 0;
				return *this;
			}

			bool value() const
			{
				return !!_value;
			}

			operator bool() const
			{
				return !!_value;
			}

			bool operator!() const
			{
				return !_value;
			}

			
			int level() const
			{
				return Level;
			}

			
			int name() const
			{
				return Name;
			}

			
			int* data()
			{
				return &_value;
			}

			
			const int* data() const
			{
				return &_value;
			}

			
			std::size_t size() const
			{
				return sizeof(_value);
			}

			
			void resize(std::size_t s)
			{
				switch (s)
				{
				case sizeof(char):
					_value = *reinterpret_cast<char*>(&_value) ? 1 : 0;
					break;
				case sizeof(_value):
					break;
				default:
					{
						std::length_error ex("boolean socket option resize");
					}
				}
			}

		private:
			int _value;
		};

		template <int Level, int Name>
		class integer
		{
		public:
			integer()
				: _value(0)
			{
			}

			explicit integer(int v)
				: _value(v)
			{
			}

			integer& operator=(int v)
			{
				_value = v;
				return *this;
			}

			int value() const
			{
				return _value;
			}

			
			int level() const
			{
				return Level;
			}

			
			int name() const
			{
				return Name;

			}
			
			int* data()
			{
				return &_value;
			}

			
			const int* data() const
			{
				return &_value;
			}

			// Get the size of the int data.
			
			std::size_t size() const
			{
				return sizeof(_value);
			}

			// Set the size of the int data.
			
			void resize(std::size_t s)
			{
				if (s != sizeof(_value))
				{
					std::length_error ex("integer socket option resize");
					boost::throw_exception(ex);
				}
			}

		private:
			int _value;
		};

		typedef ip::detail::boolean<SOL_SOCKET, SO_BROADCAST>	broadcast;
		typedef ip::detail::boolean<SOL_SOCKET, SO_DEBUG>		debug;
		typedef ip::detail::boolean<SOL_SOCKET, SO_DONTROUTE>	do_not_route;
		typedef ip::detail::boolean<SOL_SOCKET, SO_KEEPALIVE>	keep_alive;
		typedef ip::detail::integer< SOL_SOCKET, SO_SNDLOWAT> 	send_low_watermark;
		typedef ip::detail::integer< SOL_SOCKET, SO_RCVBUF> 	receive_buffer_size;
		typedef ip::detail::integer< SOL_SOCKET, SO_RCVLOWAT> 	receive_low_watermark;
		typedef ip::detail::boolean<SOL_SOCKET, SO_REUSEADDR> 	reuse_address;
	};
};