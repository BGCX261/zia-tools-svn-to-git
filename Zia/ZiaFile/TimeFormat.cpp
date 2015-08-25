#include "TimeFormat.h"

const std::string	TimeFormat::getCurrentTime()
{
	char	buffer[31];
	time_t	rTime;
	time(&rTime);
	tm*	sTime;
	sTime = gmtime(&rTime);
	strftime (buffer, 30, "%a, %d %b %Y %H:%M:%S GMT", sTime);
	buffer[30] = '\0';
	std::string	res = buffer;
	return res;
}