#ifndef _ZIA_API_ISTREAM_H_
#define _ZIA_API_ISTREAM_H_

#include <string>

#include "defines.hpp"
#include "Callback.hpp"

namespace zia{
	namespace api{

	
		class AStream
		{
		public:
			typedef zia::api::Callback< int (AStream&) >  Reader;

			AStream();
			virtual ~AStream();
			void                    setReader(Reader streamReader = Reader());
			void                    setCloseReader(Reader streamCloseReader = Reader());
			bool                    isReaderSet() const;
			bool                    isCloseReaderSet() const;
			void                    setExpectedReadSize(size_t readingSize);
			bool                    isClosed() const;
			virtual int             callReader() = 0;
			virtual bool            canRead() const = 0;
			virtual void            write(const std::string& str) = 0;
			virtual void            write(const char* buff, size_t buffSize) = 0;
			virtual size_t          read(char* buff, size_t maxBuffSize) = 0;
			virtual void            drop() = 0;
			virtual void            dropAll() = 0;
			virtual void            flush() = 0;
			virtual void            close() = 0;
			virtual void            forceClose() = 0;

		protected:
			bool                    mClosed;
			size_t                  mExpectedSize;
			Reader                  mReader;
			Reader                  mCloseReader;
		};

	};
};

#endif /* _ZIA_API_ISTREAM_H_ */
