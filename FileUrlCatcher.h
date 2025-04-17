#ifndef FILEURLCATCHER_H
#define FILEURLCATCHER_H

#include <QObject>
#include <QDebug>
#include <QUrl>

class FileUrlCatcher : public QObject {
    Q_OBJECT
public:
    FileUrlCatcher() = default;

public slots:
    void getFileUrl(const QUrl& fileUrl) {
        QString filePath = fileUrl.toLocalFile();
        emit sendFilePath(filePath);
        qDebug() << "FileUrlCatcher:" << filePath;
    }

signals:
    void sendFilePath(const QString& filePath);
};

#endif // FILEURLCATCHER_H
