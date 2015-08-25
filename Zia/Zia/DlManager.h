#ifndef		DLMANAGER_H_
#define		DLMANAGER_H_

#include	<map>

#include	"AbsDl.h"

class		DlManager : private AbsDl
{
public:

  DlManager();
  DlManager(const DlManager&);
  ~DlManager();

  const DlManager&	operator=(const DlManager&);

  void			load(const std::string&, const std::string&);
  void			load(const std::map<std::string, std::string>&);
  void			unload(const std::string&);
  void*			getFunction(const std::string&, const std::string&);

private:

  typedef std::map<std::string, void*>::iterator	itLib;
  typedef std::map<std::string, std::string>::const_iterator	citLib;

  std::map<std::string, void*>		_libraries;
};

#endif	// !DLMANAGER_H_
