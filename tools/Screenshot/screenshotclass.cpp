#include "screenshotclass.h"

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QScreen>

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

QString ScreenshotClass::filePath() const
{
    return m_filePath;
}

void ScreenshotClass::setFilePath(const QString &path)
{
    if (m_filePath != path)
    {
        m_filePath = path;
        emit filePathChanged();
    }
}

void ScreenshotClass::takeScreenshot()
{
    // Get the primary screen
    QScreen *screen =QGuiApplication::primaryScreen();
    if (!screen)
    {
        qDebug() << "Failed to capture primary screen";
        return;
    }

    // Capture the screen:
    QImage image = screen->grabWindow(0).toImage();

    // Create a file name:
    QString fileName = "/screenshot_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".png";
    QString fileLocation = m_filePath + fileName;
    if (image.save(fileLocation))
        qDebug() << "Screenshot saved as: " << fileLocation << " \nIn location: " << fileLocation;
    else
        qDebug() << "Failed to save screenshot.";
}

/*!
 * \brief Destructor
 */
ScreenshotClass::~ScreenshotClass() = default;
