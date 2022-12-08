#include "fileaccesshelper.h"

FileAccessHelper::FileAccessHelper()
{

}

bool FileAccessHelper::isFileAccessAllowed(QString fileName)
{
    return m_allowedFiles.contains(fileName);
}

void FileAccessHelper::addFileToAllowedFilesList(QString fileName)
{
    m_allowedFiles.append(fileName);
}
