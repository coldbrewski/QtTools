#include "recorder.h"

/*!
 * \brief DEFAULT_SAVE_PATH
 * \details A default save location for if a
 *  path is not set by the user
 */
#if defined(Q_OS_WIN)
    static const QString DEFAULT_SAVE_PATH {"C:/Temp"};
#elif defined(Q_OS_MAC)
    static const QString DEFAULT_SAVE_PATH {"/tmp"};
#else
    static const QString DEFAULT_SAVE_PATH {"/tmp"};
#endif

/*!
 * \brief Constructor
 */
Recorder::Recorder(QObject *parent)
    : QObject{parent}
{

}

/*!
 * \brief Recorder::filePath
 * \return the current save filePath
 */
QString Recorder::filePath() const
{
    return m_filePath;
}

/*!
 * \brief Recorder::setFilePath
 * \param path
 * \return the file path set by the user via QML or other interface
 */
void Recorder::setFilePath(const QString &path)
{
    if (m_filePath != path)
    {
        m_filePath = path;
        emit filePathChanged();
    }
}

/*!
 * \brief Recorder::startRecording
 */
void Recorder::startRecording()
{

}

/*!
 * \brief Recorder::stopRecording
 */
void Recorder::stopRecording()
{

}

/*!
 * \brief Destructor
 */
Recorder::~Recorder() = default;
