#ifndef FILEACCESSHELPER_H
#define FILEACCESSHELPER_H

#include <QString>
#include <QStringList>
#include <QDir>
#include <QVector>

class FileAccessHelper
{
public:
    FileAccessHelper();

    bool isFileAccessAllowed(QString fileName);
    void addFileToAllowedFilesList(QString fileName);
    void addDirToAllowedDirList(QDir dirName);

private:
    QStringList m_allowedFiles;
    QVector<QDir> m_allowedDirs;
};

#endif // FILEACCESSHELPER_H
