#ifndef SCREENSHOTCLASS_H
#define SCREENSHOTCLASS_H

#include <QObject>
#include <QQuickWindow>

class ScreenshotClass : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged FINAL)
public:
    explicit ScreenshotClass(QObject *parent = nullptr);
    ~ScreenshotClass();

    QString filePath() const;
    void setFilePath(const QString &path);

public slots:
    void takeScreenshot(QQuickWindow* window);

signals:
    void filePathChanged();

private:
    QString m_filePath;
};

#endif // SCREENSHOTCLASS_H
