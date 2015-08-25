#pragma once

class SslInit
{
private:
	static bool	isInit;
	void	init();
public:
	SslInit(void);
	~SslInit(void);

};
