#include "DlManager.h"

DlManager::DlManager()
  : AbsDl(), _libraries() {}

DlManager::DlManager(const DlManager& from)
  : AbsDl(from), _libraries(from._libraries) {}

DlManager::~DlManager() {
  for (itLib it = _libraries.begin(); it != _libraries.end(); ++it) {
    AbsDl::close((*it).second);
    _libraries.erase(it);
  }
}

const DlManager&	DlManager::operator=(const DlManager& from) {
  if (this != &from) {
    _libraries = from._libraries;
  }
  return *this;
}

void			DlManager::load(const std::string& library,
					const std::string& path) {
  if (_libraries[library])
    throw msg_error("This library: "
		    + library
		    + " was loaded previously!");
  _libraries[library] = AbsDl::open(path);
}

void			DlManager::load(const std::map<std::string, std::string>& libraries) {
  for (citLib it = libraries.begin(); it != libraries.end(); ++it) {
    load((*it).first, (*it).second);
  }
}

void			DlManager::unload(const std::string& library) {
  try {
    if (_libraries.empty())
      throw std::exception();
    AbsDl::close(_libraries[library]);
    _libraries.erase(_libraries.find(library));
  }
  catch (const std::exception&) {
    throw msg_error("This library: "
		    + library
		    + " was not loaded!");
  }
}

void*			DlManager::getFunction(const std::string& library, const std::string& symbole) {
  void*			tmp = AbsDl::load(_libraries[library], symbole);

  if (tmp)
    return tmp;
  throw msg_error("This library: "
		  + library + " or this symbole: "
		  + symbole + " was not found!");
}
