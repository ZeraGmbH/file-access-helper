#include <gtest/gtest.h>
#include <fileaccesshelper.h>

static const QString accessAllowedFile = QStringLiteral("../test-data/access-allowed.txt");
static const QString accessNotAllowedFile = QStringLiteral("../test-data/access-not-allowed.txt");
static const QString nonExistingFile = QStringLiteral("../test-data/foo.txt");

static const QString accessAllowedFolder =  QStringLiteral("../test-data/operator/logger/");
static const QString accessNotAllowedFolder =  QStringLiteral("../test-data/operator/license-key/");
static const QString nonExistingFolder =  QStringLiteral("../test-data/operator/foo/");

TEST(FILE_ACCESS, EMPTY_ALLOWED_LISTS)
{
    FileAccessHelper testAccess;
    EXPECT_FALSE(testAccess.isFileAccessAllowed(accessAllowedFile));
}

TEST(FILE_ACCESS, FILE_WITH_ACCESS_ALLOWED)
{
    FileAccessHelper testAccess;
    testAccess.addFileToAllowedFilesList(accessAllowedFile);
    EXPECT_TRUE(testAccess.isFileAccessAllowed(accessAllowedFile));
}

TEST(FILE_ACCESS, FILE_WITH_ACCESS_NOT_ALLOWED)
{
    FileAccessHelper testAccess;
    testAccess.addFileToAllowedFilesList(accessAllowedFile);
    EXPECT_FALSE(testAccess.isFileAccessAllowed(accessNotAllowedFile));
}

TEST(FILE_ACCESS, NON_EXISTING_FILE)
{
    FileAccessHelper testAccess;
    testAccess.addFileToAllowedFilesList(accessAllowedFile);
    EXPECT_FALSE(testAccess.isFileAccessAllowed(nonExistingFile));
}

TEST(FILE_ACCESS, FOLDER_WITH_ACCESS_ALLOWED)
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_TRUE(testAccess.isFileAccessAllowed(accessAllowedFolder + QStringLiteral("test.db")));
}

TEST(FILE_ACCESS, FOLDER_WITH_ACCESS_NOT_ALLOWED)
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_FALSE(testAccess.isFileAccessAllowed(accessNotAllowedFolder + QStringLiteral("test.lic")));
}

TEST(FILE_ACCESS, NON_EXISTING_FOLDER)
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_FALSE(testAccess.isFileAccessAllowed(nonExistingFolder + QStringLiteral("bar.lic")));
}
