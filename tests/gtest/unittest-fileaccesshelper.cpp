#include <gtest/gtest.h>
#include <fileaccesshelper.h>

static const QString accessAllowedFile = QStringLiteral("../test-data/access-allowed.txt");
static const QString accessNotAllowedFile = QStringLiteral("../test-data/access-not-allowed.txt");

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
