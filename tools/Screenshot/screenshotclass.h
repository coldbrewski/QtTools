#ifndef SCREENSHOTCLASS_H
#define SCREENSHOTCLASS_H

#include <QObject>
#include <QImage>

class ScreenshotClass : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged FINAL)
public:
    explicit ScreenshotClass(QObject *parent = nullptr);
    ~ScreenshotClass();

    QString filePath() const;
    void setFilePath(const QString &path);

   Q_INVOKABLE void takeScreenshot();

signals:
    void filePathChanged();

private slots:

private:
    QString m_filePath;
};

#endif // SCREENSHOTCLASS_H
