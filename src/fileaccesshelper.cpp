/*  This class is intended to use with vf files
 *  the allowed list should contain the allowed folders (for writing)
 *
 *  list of open points
 *
 *  - usb and serial number
*/
#include "fileaccesshelper.h"
#include <QFileInfo>

FileAccessHelper::FileAccessHelper()
{

}

bool FileAccessHelper::isAccessAllowed(QString fileName)
{
    QFileInfo fileInfo(fileName);
    QString absoluteFilePath(fileInfo.absolutePath());

    return m_allowedDirs.contains(absoluteFilePath);
}

void FileAccessHelper::addDirToAllowedDirList(QDir dirName)
{
    m_allowedDirs.append(dirName);
}
