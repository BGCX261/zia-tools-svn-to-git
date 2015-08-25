#include "UrlDecoder.h"


std::string zia::utils::UrlDecoder::decode(const std::string& s) 
{
	std::string buffer = "";
	int len = s.length();
	for (int i = 0; i < len; i++) 
	{
		int j = i ;
		char ch = s.at(j);
		if (ch == '%')
		{
			char tmpstr[] = "0x0__";
			int chnum;
			tmpstr[3] = s.at(j + 1);
			tmpstr[4] = s.at(j + 2);
			chnum = ::strtol(tmpstr, 0, 16);	  
			buffer += chnum;
			i += 2;
		}
		else 
		{
			buffer += ch;
		}
	}
	return buffer;

}
