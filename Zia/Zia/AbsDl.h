#ifndef		ABSDL_H_
#define		ABSDL_H_

#include	<sstream>
#include	<iomanip>
#include	<cstring>

#include	"IAbsDl.h"
#include	"MyMsgError.hpp"
#include	"MySingleton.hpp"

class		AbsDl : public IAbsDl,
			public MySingleton<AbsDl>
{
public :

  /**
   * \brief Open a dynamic library.
   * \param lib name of library that will be open.
   * \return void* pointer to use the library.
   */
  virtual void*	open(const std::string&);

  /**
   * \brief Close the dynamic library.
   * \param handle the current handled library.
   */
  virtual void	close(void* handle);

  /**
   * \brief Load a symbole (a method) of the library.
   * \param handle the current handled library.
   * \param symbole the method required.
   * \return New thread copy.
   */
  virtual void*	load(void *, const std::string&);

protected:

  AbsDl();
  AbsDl(const AbsDl&);
  ~AbsDl();

  const AbsDl&	operator=(const AbsDl&);

private:
  friend class	MySingleton<AbsDl>;
};

#endif	// !ABSDL_H_
