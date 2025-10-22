#include "screenshotclass.h"

#include <QDateTime>
#include <QDebug>
#include <QImage>
#include <QWindow>

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
ScreenshotClass::ScreenshotClass(QObject *parent)
        : QObject{parent}, m_filePath(DEFAULT_SAVE_PATH)
{
}

/*!
 * \brief ScreenshotClass::filePath
 * \return returns the file path beign used
 */
QString ScreenshotClass::filePath() const
{
    return m_filePath;
}

/*!
 * \brief ScreenshotClass::setFilePath
 * \param path
 * \return the file path set by the user in QML
 */
void ScreenshotClass::setFilePath(const QString &path)
{
    if (m_filePath != path)
    {
        m_filePath = path;
        emit filePathChanged();
    }
}

/*!
 * \brief ScreenshotClass::takeScreenshot
 * \param window -> easy way over messing with rootObjects
 * \return a screenshot of qml window on triggered from QML
 */
void ScreenshotClass::takeScreenshot(QQuickWindow* window)
{
    if (!window) {
        qDebug() << "Window is null.";
        return;
    }

    QImage image = window->grabWindow();
    QString fileName = "screenshot_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".png";
    QString filePath = m_filePath + "/" + fileName;

    if (image.save(filePath))
        qDebug() << "Screenshot saved at:" << filePath;
    else
        qDebug() << "Failed to save screenshot.";
}

/*!
 * \brief Destructor
 */
ScreenshotClass::~ScreenshotClass() = default;
