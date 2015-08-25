#ifndef _ZIA_API_ILOG_H_
#define _ZIA_API_ILOG_H_

#include <sstream>
#include <iostream>

#include "defines.hpp"

namespace zia{
	namespace api{
class ILog
{
public:
    enum Level
    {
        ERROR = 1,
        WARNING,
        INFO,
        DEBUG,
        DEBUG2
    };

	ILog();

    virtual ~ILog();
    ILog&               operator << (std::ostream& (*pf)(std::ostream&));
    template <typename T>
    ILog&               operator << (const T& input)
    {
        mLine << input;
        return (*this);
    }
    virtual ILog&  operator << (Level level) = 0;
    virtual void        flush() = 0;
    virtual void        print(Level level, const std::string& format, ...) = 0;

protected:
    std::stringstream   mLine;

};

_EOF_ZIA_API_

#endif /* _ZIA_API_ILOG_H_ */
