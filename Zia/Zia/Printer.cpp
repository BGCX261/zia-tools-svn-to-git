#include "Printer.h"


zia::Printer::Printer(void)
	: _stringLvl(6)
{
	_stringLvl[zia::api::LOG_ASSERT] = "Error";
	_stringLvl[zia::api::LOG_ERR] = "Warning";
	_stringLvl[zia::api::LOG_WARN] = "Info";
	_stringLvl[zia::api::LOG_INFO] = "Debug";
	_stringLvl[zia::api::LOG_DEBUG] = "Debug2";
}


zia::Printer::~Printer(void)
{
}

void        zia::Printer::print(zia::api::LogLevel level, const std::string& format, ...)
{

}

void	zia::Printer::flush()
{
	std::cout << this->mLine << std::endl;
}