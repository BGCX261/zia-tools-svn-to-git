#ifndef _ZIA_API_ISTREAM_H_
#define _ZIA_API_ISTREAM_H_

#include <string>

#include "defines.hpp"
#include "Callback.hpp"

_BOF_ZIA_API_

/*!
 * \brief Stream interface class.
 *
 * Base of your Zia, this class will permit you to manage all
 * asynchronous datas in your Zia.
 * With this sytem, you will be capable to implement any management
 * system behind the interface.
 *
 * You can write directly into it, and, with the IStream::Reader callback,
 * you are called when there is something to read in it.
 *
 * <h2> Zia core implementations: </h2>
 * \code

//
// Non-virtual IStream members to implement:
//
IStream::IStream();
IStream::~IStream();
void            IStream::setReader(Reader streamReader);
void            IStream::setCloseReader(Reader streamCloseReader);
bool            IStream::isReaderSet() const;
bool            IStream::isCloseReaderSet() const;
void            IStream::setExpectedReadSize(size_t readingSize);
bool            IStream::isClosed() const;

//
// Minimal IStream inherits implementation:
//
namespace zia {

class X : public api::IStream
{
public:
    X();
    virtual ~X();

    virtual int         callReader();
    virtual bool        canRead() const;
    virtual void        write(const std::string& str);
    virtual void        write(const char* buff, size_t buffSize);
    virtual size_t      read(char* buff, size_t maxBuffSize);
    virtual void        drop();
    virtual void        dropAll();
    virtual void        flush();
    virtual void        close();
    virtual void        forceClose();

};

}

 * \endcode
 *
 */
class IStream
{
public:

    /*!
     * \brief The IStream::Reader type.
     *
     * IStream::Reader is the type of IStream reading callback.
     * Callback on a method:
     * \code
     * int          ( IStream& )
     * \endcode
     */
    typedef zia::api::Callback_1p< int, IStream& >  Reader;

    /*!
     * \brief Constructor.
     *
     */
	IStream(){}

    /*!
     * \brief Destructor.
     */
	virtual ~IStream(){}

    /*!
     * \brief Set the IStream::Reader reader of the IStream for reading.
     *
     * \a streamReader will be called every time stream's datas will be
     * available for reading.
     *
     * To unset the reader, call without arguments.
     *
     * \param streamReader The IStream::Reader reader callback.
     */
	void                    setReader(Reader streamReader = Reader())
	{ 
		this->mReader = streamReader; 
	}

    /*!
     * \brief Set the close reader.
     *
     * The \a streamCloseReader will be called when closing the stream.
     * To unset the close reader, call without arguments.
     *
     * Note: After the \a streamCloseReader callback call, you should close
     * all your next IStream.
     *
     * \param streamCloseReader The IStream::Reader called one time
     * when the IStream will be closed.
     */
	void                    setCloseReader(Reader streamCloseReader = Reader())
	{ 
		this->mCloseReader = streamCloseReader;
	}

    /*!
     * \brief Check if the IStream::Reader reader is set.
     *
     * \return true if the IStream::Reader reader is set.
     */
	bool                    isReaderSet() const
	{ 
		return this->mReader.isSet();
	}

    /*!
     * \brief Check if the IStream::Reader close callback is set.
     *
     * \return true if the IStream::Reader close callback is set.
     */
	bool                    isCloseReaderSet() const
	{
		return this->mCloseReader.isSet();
	}

    /*!
     * \brief Set the excpeted reading size
     *
     * \param readingSize The expected size of data you want to
     * read when the reader is called.
     */
	void                    setExpectedReadSize(size_t readingSize)
	{ 
		this->mExpectedSize = readingSize; 
	}

    /*!
     * \brief Check if IStrean is closed.
     *
     * \return true if the IStream is closed.
     */
	bool                    isClosed() const 
	{ 
		return this->mClosed;
	}

    /*!
     * \brief Call the reader.
     *
     * \return the returned value of the callback.
     */
	virtual int             callReader() = 0;

    /*!
     * \brief Check if there is something to read.
     *
     * \return true if there is something to read.
     */
	virtual bool            canRead() const = 0;

    /*!
     * \brief Write a string in the IStream.
     *
     * The string will be copied in the IStream.
     *
     * \param str The string to write.
     */
    virtual void            write(const std::string& str) = 0;

    /*!
     * \brief Write raw data in the IStream.
     *
     * The datas will be copied in the IStream.
     *
     * \param buff The raw datas
     * \param buffSize The size in octets of the \a buff
     */
    virtual void            write(const char* buff, size_t buffSize) = 0;

    /*!
     * \brief Read data from the IStream.
     *
     * This copy data in \a buff, then remove it from the IStream.
     *
     * The reader will be called while there is enought data to read,
     * so you should read or setExpectedReadSize inside your reader callback.
     *
     * \param buff Where the reading data will be copied.
     * \param maxBuffSize The maxium size in octets to read and copy in \a buff.
     * \return The number of octets read.
     */
    virtual size_t          read(char* buff, size_t maxBuffSize) = 0;

    /*!
     * \brief Drop datas.
     *
     * Remove datas from the IStream without calling the reader.
     */
    virtual void            drop() = 0;

    /*!
     * \brief Drop datas everytime.
     *
     * Drop datas everytime and unset the reader.
     * Re-set the reader to stop drop all.
     */
    virtual void            dropAll() = 0;

    /*!
     * \brief Flush datas.
     *
     * Call the reader whatever the expected size.
     */
    virtual void            flush() = 0;

    /*!
     * \brief Close the IStream.
     *
     * This will call the reader while there are datas.
     * If your reader dont read it, it may cause infinite loop
     */
    virtual void            close() = 0;

    /*!
     * \brief Close the IStream NOW.
     *
     * This will close the stream without send waiting datas.
     */
    virtual void            forceClose() = 0;

protected:
    /*!
     * \brief true if is closed.
     */
    bool                    mClosed;

    /*!
     * \brief Exepected reading size.
     */
    size_t                  mExpectedSize;

    /*!
     * \brief Reader callback
     */
    Reader                  mReader;

    /*!
     * \brief Reader callback on close
     */
    Reader                  mCloseReader;

};

_EOF_ZIA_API_

#endif /* _ZIA_API_ISTREAM_H_ */
