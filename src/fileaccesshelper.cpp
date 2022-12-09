/*  This class is intended to use with vf files
 *  the allowed list should contain the allowed folders (for writing)
 *
 *  list of open points
 *  what happens with
 *  - symlinks (containig the desired folder, but pointing somewhere elses
 *  - what happens when folder does not exist
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
    return m_allowedDirs.contains(fileInfo.absoluteDir());
}

void FileAccessHelper::addDirToAllowedDirList(QDir dirName)
{
    m_allowedDirs.append(dirName);
}
