#ifndef __MPMESSAGE_H__
# define __MPMESSAGE_H__



#include <string>

class	MPMessage
{
public:
	MPMessage(const std::string& msg);
	MPMessage(const MPMessage& message);
	std::string&	getCurMsg();
	const std::string&	getIniMsg() const;
	void	refreshMessage();
	void	updateMessage(const MPMessage& refMsg);
	void	updateMessage(const std::string& refMsg);
private:
	std::string	_curMsg;
	const std::string	_iniMsg;
};

#endif /* __MPMESSAGE_H__ */