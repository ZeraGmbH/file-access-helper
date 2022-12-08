#include "fileaccesshelper.h"
#include <QFileInfo>

FileAccessHelper::FileAccessHelper()
{

}

bool FileAccessHelper::isFileAccessAllowed(QString fileName)
{
    QFileInfo fileInfo(fileName);
    if(m_allowedDirs.contains(fileInfo.absoluteDir())) {
        return true;
    }
    return m_allowedFiles.contains(fileName);
}

void FileAccessHelper::addFileToAllowedFilesList(QString fileName)
{
    m_allowedFiles.append(fileName);
}

void FileAccessHelper::addDirToAllowedDirList(QDir dirName)
{
    m_allowedDirs.append(dirName);
}
