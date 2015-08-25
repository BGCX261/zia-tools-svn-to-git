namespace ip{

	namespace tcp{
		class IAcceptor;
	};

	namespace detail{

		class IVisitByAcceptor
		{
		public:
			virtual	void	access(ip::tcp::IAcceptor& acceptor) = 0;
			virtual	void	access(ip::tcp::IAcceptor& acceptor, ip::tcp::endpoint) = 0;
		};
	};
};