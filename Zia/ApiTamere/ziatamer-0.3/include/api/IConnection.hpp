#ifndef _ICONNECTION_H_
#define _ICONNECTION_H_

#include "defines.hpp"
#include "Callback.hpp"
#include "IStream.hpp"
#include "DataRep.hpp"
#include "ILog.hpp"

_BOF_ZIA_API_

/*!
 * \brief Callback used to handle FD r/w
 *
 * return false will reset the default system r/w.
 *
 * If used to read:
 *   1st arg : FD/HANDLE to read from.
 *   2nd arg : IStream to write on.
 *
 * If used to write:
 *   1st arg : FD/HANDLE to write on.
 *   2nd arg : IStream to read from.
 *
 */
typedef zia::api::Callback_2p< bool, int, IStream& >        FdCallback;


/*!
 * \brief Connection class.
 *
 * IConnection represent the connection.
 *
 * <h2> Zia core implementations: </h2>
 * \code

//
// Non-virtual IMessage members to implement:
//
IConnection::IConnection();
IConnection::~IConnection();
api::DataRep&               IConnection::info();
api::ILog&                  IConnection::log();

//
// Minimal IMessage inherits implementation:
//
namespace zia {

class X : public api::IConnection
{
public:
    X();
    virtual ~X();

    virtual void                close();
    virtual void                setFdReadCallback(api::FdCallback callback = api::FdCallback());
    virtual void                setFdWriteCallback(api::FdCallback callback = api::FdCallback());
};

}

 * \endcode
 */
class IConnection
{
public:
    IConnection();
    virtual ~IConnection();

    /*!
     * \brief Get connection infos.
     *
     * Inforamtions about connection.
     */
    api::DataRep&               info();

    /*!
     * \brief Get the ILog.
     *
     * Log about the connection.
     */
    api::ILog&                  log();

    /*!
     * \brief Close the connection.
     *
     */
    virtual void                close() = 0;

    /*!
     * \brief Set the input fd callback for reading.
     *
     * The FdCallback \a callback will be called when there
     * will be activity on the input FD of this message. Then,
     * the callback will read on the FD and write in the stream
     * recieved as an argument.
     *
     * \param callback The callback. Dont specify it to unset the callback.
     */
    virtual void                setFdReadCallback(api::FdCallback callback = api::FdCallback()) = 0;

    /*!
     * \brief Set the output fd callback for writing.
     *
     * The FdCallback \a callback will be called when the FD
     * will be available for writing. Then, the callback
     * will read on the stream and write on the FD.
     *
     * \param callback The callback. Dont specify it to unset the callback.
     */
    virtual void                setFdWriteCallback(api::FdCallback callback = api::FdCallback()) = 0;

protected:
    /*!
     * \brief IConnection's ILog.
     *
     * Must be set.
     */
    ILog*                       mLog;

    /*!
     * \brief DataRep connection inforamtions.
     *
     * Must be set.
     */
    DataRep*                    mInfos;

};

_EOF_ZIA_API_

#endif /* _ICONNECTION_H_ */
