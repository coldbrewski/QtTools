#ifndef RECORDER_H
#define RECORDER_H

#include <QObject>

class Recorder : public QObject
{
    Q_OBJECT
public:
    explicit Recorder(QObject *parent = nullptr);
    ~Recorder();

    QString filePath() const;
    void setFilePath(const QString &path);

signals:
    void filePathChanged();

public slots:
    void startRecording();
    void stopRecording();

private:
    QString m_filePath;
};

#endif // RECORDER_H
