#include <gtest/gtest.h>
#include <fileaccesshelper.h>

static const QString accessAllowedFile = QStringLiteral("../test-data/allowed-folder/access-allowed.txt");
static const QString accessNotAllowedFile = QStringLiteral("../test-data/denied-folder/access-not-allowed.txt");
static const QString nonExistingFile = QStringLiteral("../test-data/allowed-folder/foo.txt");

static const QString accessAllowedSubFolder = QStringLiteral("../test-data/allowed-folder/subfolder");
static const QString accessDeniedSubFolder = QStringLiteral("../test-data/denied-folder/subfolder");

static const QString accessAllowedFolder =  QStringLiteral("../test-data/allowed-folder/");
static const QString accessDeniedFolder =  QStringLiteral("../test-data/denied-folder/");
static const QString nonExistingFolder =  QStringLiteral("../test-data/operator/foo/");

static const QString nastyTestFolder =  QStringLiteral("../test-data/allowed-folder/../../test-data/denied-folder");

TEST (FOLDER_ACCESS, NASTY_TEST_FOLDER )
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_FALSE(testAccess.isAccessAllowed(nastyTestFolder));
}

TEST (FOLDER_ACCESS, ALLOWED_SUBFOLDER )
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_TRUE(testAccess.isAccessAllowed(accessAllowedSubFolder));
}

TEST (FOLDER_ACCESS, DENIED_SUBFOLDER )
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_FALSE(testAccess.isAccessAllowed(accessDeniedSubFolder));
}

TEST(FOLDER_ACCESS, NON_EXISTING_FOLDER)
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_FALSE(testAccess.isAccessAllowed(nonExistingFolder + QStringLiteral("bar.lic")));
}

TEST(FILE_ACCESS, EMPTY_ALLOWED_LISTS)
{
    FileAccessHelper testAccess;
    EXPECT_FALSE(testAccess.isAccessAllowed(accessAllowedFile));
}

TEST(FILE_ACCESS, FILE_WITH_ACCESS_ALLOWED)
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_TRUE(testAccess.isAccessAllowed(accessAllowedFile));
}

TEST(FILE_ACCESS, FILE_WITH_ACCESS_NOT_ALLOWED)
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_FALSE(testAccess.isAccessAllowed(accessNotAllowedFile));
}

TEST(FILE_ACCESS, NON_EXISTING_FILE)
{
    FileAccessHelper testAccess;
    testAccess.addDirToAllowedDirList(accessAllowedFolder);
    EXPECT_TRUE(testAccess.isAccessAllowed(nonExistingFile));
}


