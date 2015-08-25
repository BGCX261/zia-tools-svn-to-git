#include "AbsDl.h"
#define WIN32_LEAN_AND_MEAN
#include	<windows.h>
#include <fstream>
#include <iostream>

AbsDl::AbsDl()
  : IAbsDl(), MySingleton<AbsDl>() {}

AbsDl::AbsDl(const AbsDl& from)
  : IAbsDl(from), MySingleton<AbsDl>(from) {}

AbsDl::~AbsDl() {}

const AbsDl&	AbsDl::operator=(const AbsDl& from) {
  if (this != &from) {
  }
  return *this;
}

/**
 * \sa LoadLibrary
 */
void*		AbsDl::open(const std::string& n_dll)
{
  void* handle = LoadLibrary(n_dll.c_str());
  if (!handle)
    throw msg_error(" can't open LoadLibrary.");
  return handle;
}

/**
 * \sa GetProcAddress
 */
void*		AbsDl::load(void *handle, const std::string& sym)
{
    void* prc = GetProcAddress(static_cast<HMODULE>(handle), sym.c_str());
	if (prc == 0)
		throw msg_error(sym + " can't be loaded.");
	return prc;
}

/**
 * \sa FreeLibrary
 */
void		AbsDl::close(void* handle) {
  if (!FreeLibrary(static_cast<HMODULE>(handle)))
    throw msg_error(" can't close Library.");
}
