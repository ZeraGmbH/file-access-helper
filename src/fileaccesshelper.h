#ifndef FILEACCESSHELPER_H
#define FILEACCESSHELPER_H

#include <QString>
#include <QStringList>

class FileAccessHelper
{
public:
    FileAccessHelper();

    bool isFileAccessAllowed(QString fileName);
    void addFileToAllowedFilesList(QString fileName);

private:
    QStringList m_allowedFiles;
};

#endif // FILEACCESSHELPER_H
