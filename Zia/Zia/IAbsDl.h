#ifndef		IABSDL_H_
#define		IABSDL_H_

#include	<string>

#include	"ApiDlRevision.h"

/**
 * \class IAbsDl
 * \author Antoine Benevaut
 * \date Sat Feb 12 15:19:04 2011
 *
 * \brief IAbsDl.
 *
 */
class		IAbsDl : public ApiDl::Revision
{
public:

  /**
   * \brief Open a dynamic library.
   * \param lib name of library that will be open.
   * \return void* pointer to use the library.
   */
  virtual void*	open(const std::string&) = 0;

  /**
   * \brief Close the dynamic library.
   * \param handle the current handled library.
   */
  virtual void	close(void*) = 0;

  /**
   * \brief Load a symbole (a method) of the library.
   * \param handle the current handled library.
   * \param symbole the method required.
   * \return New thread copy.
   */
  virtual void*	load(void*, const std::string&) = 0;

protected:

  /**
   * \brief Virtual destructor.
   */
  virtual ~IAbsDl() {}
};

#endif	// !IABSDL_H_
