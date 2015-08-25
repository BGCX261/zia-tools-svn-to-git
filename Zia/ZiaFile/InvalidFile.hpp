#pragma once

#include "BasicFile.h"
#include "DocumentRoot.h"

namespace filesystem{

template<typename TypeFile>
struct	ErrorFile;
template<>
struct ErrorFile<BasicFile> { static BasicFile invalid(){ return BasicFile();} };

template<>
struct ErrorFile<DocumentRoot> { static DocumentRoot invalid(){ return DocumentRoot();} };


};