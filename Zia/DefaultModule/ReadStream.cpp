#include "ReadStream.h"


void	zia::ReadStream::readAstream(zia::api::AStream& input, std::string&	dest, char* from, const size_t buffsize)
{
	int	readed;
	while ((readed = input.read(from, buffsize)) > 0)
	{
		from[readed] = '\0';	
		dest += from;
	}
}
