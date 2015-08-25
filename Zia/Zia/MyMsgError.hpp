#ifndef		MYMSGERROR_H_
# define	MYMSGERROR_H_

#include	<exception>

class		msg_error : public std::exception
{
public:
  msg_error(const std::string& msg)
    : _msg(msg) {}

  virtual ~msg_error() throw() {}

  virtual const char*	what() const throw() {
    return _msg.c_str();
  }

private:
  std::string		_msg;
};

#endif	// !MYMSGERROR_H_
