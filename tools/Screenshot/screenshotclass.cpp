#include "screenshotclass.h"

#include <QDateTime>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QImage>
#include <QStandardPaths>
#include <QWindow>

/*!
 * \brief Constructor
 */
ScreenshotClass::ScreenshotClass(QObject *parent)
        : QObject{parent}
{
    m_filePath = { QString("%1/%2").arg(
            QStandardPaths::writableLocation(QStandardPaths::HomeLocation)
            , "Screenshots/")
    };

    if (!QFileInfo::exists(m_filePath))
        QDir().mkpath(m_filePath);
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
