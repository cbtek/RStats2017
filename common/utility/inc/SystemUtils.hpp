/**
  * SystemUtils.hpp
  */
#pragma once

#include "utility/inc/StringUtils.hpp"
#include "utility/inc/FileUtils.hpp"
#include "utility/inc/Exception.hpp"

#include <chrono>
#include <locale>
#include <codecvt>
#include <string>

#ifdef _WIN32
#   include <windows.h>
#   include <shlobj.h>
#   include <Lmcons.h>
#else
#   include <dirent.h>
#   include <unistd.h>
#   include <libgen.h>
#   include <sys/types.h>
#   include <sys/stat.h>
#   include <fcntl.h>
#   include <pwd.h>
#   include <dlfcn.h>
#endif
#ifndef c_MAX_PATH
#define c_MAX_PATH 1024
#endif

namespace cbtek {
namespace common {
namespace utility {
namespace SystemUtils {

/**
 * @brief getUserHomeDirectory Gets user home directory
 * @return Returns string representing user home directory
 */
inline std::string getUserHomeDirectory()
{
#ifdef _WIN32
    char dir[c_MAX_PATH];

    SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0, dir);

    std::string dirStr(dir);
    StringUtils::replaceInPlace(dirStr,"\\","/");
    return dirStr;
#else
    return std::string(getenv("HOME"));
#endif
}

/**
 * @brief getUserAppDirectory Gets current user application directory
 * @return Return string representing the current users application directory
 */
inline std::string getUserAppDirectory()
{
#ifdef _WIN32
    char dir[c_MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, dir);
    std::string dirStr(dir);
    StringUtils::replaceInPlace(dirStr,"\\","/");
    return dirStr;
#else
    std::string path = FileUtils::buildFilePath(getUserHomeDirectory(), ".local");
    FileUtils::createDirectory(path);
    path = FileUtils::buildFilePath(getUserHomeDirectory(), ".local/share");
    FileUtils::createDirectory(path);
    return path;
#endif
}

/**
 * @brief getUserTempDirectory Gets temporary directory for current user
 * @return Returns string representing the current users temporary directory
 */
inline std::string getUserTempDirectory()
{
#ifdef _WIN32
    char dir[c_MAX_PATH];

    GetTempPathA(c_MAX_PATH, dir);
    GetLongPathNameA(dir, dir, c_MAX_PATH);

    std::string dirStr(dir);
    StringUtils::replaceInPlace(dirStr,"\\","/");
    return dirStr;
#else
    return std::string("/tmp");
#endif
}

/**
 * @brief getUserName Gets the login name of the current user
 * @return Returns string representing current users login name
 */
inline std::string getUserName()
{
#ifdef _WIN32
    char username[UNLEN+1];
    DWORD username_len = UNLEN+1;
    GetUserNameA(username, &username_len);
    return std::string(username);
#else
    struct passwd *passwd;
    passwd =getpwuid ( getuid());
    return std::string(passwd->pw_name);
#endif
}

/**
 * @brief execute
 * @param command
 * @param args
 * @return
 */
inline int execute(const std::string& command,
                          const std::string& args)
{
    return system((command+" "+args).c_str());  //one day this will do more
}

/**
 * @brief execute Simple command to start an external application
 * @param command Full path to the command to run
 * @return
 */
inline int execute(const std::string &command)
{
    return execute(command,"");
}

/**
 * @brief getCurrentDirectory Gets the current directory
 * @return Returns string representing the current directory
 */
inline std::string getCurrentDirectory()
{
    char dir[c_MAX_PATH];
    #ifdef _WIN32
        GetCurrentDirectoryA(MAX_PATH, dir);
    #else
        char * ret = getcwd(dir, c_MAX_PATH);
        if (ret)
        {
            delete ret;
        }
    #endif
    return std::string(dir);
}

/**
 * @brief getCurrentExecutableDirectory Gets the executable directory
 * @return Returns string representing directory where executable launched from
 */
inline std::string getCurrentExecutableDirectory()
{
    std::string appPath;
    char buffer[PATH_MAX];
    #ifdef _WIN32
        GetModuleFileNameA(NULL,buffer,256);
        appPath = std::string(buffer);
        appPath = FileUtils::getDirPath(appPath);

    #else  
        ssize_t len = ::readlink("/proc/self/exe", buffer, sizeof(buffer)-1);
        if (len != -1)
        {
          buffer[len] = '\0';
          appPath = std::string(buffer);
        }
        //Fix to remove exe name
        appPath = FileUtils::getDirPath(appPath);
    #endif
    return appPath;
}


inline int executeInTerminal(const std::string& command, const std::string& args)
{
    std::string cmd;
    #ifdef __WIN32
        cmd = "start cmd /K \"" + command+"\" \""+args+"\"";
    #else
        std::vector<std::string> entries = FileUtils::getFileEntries("/usr/bin","",false);
        std::vector<std::string> terminalsFound;
        StringUtils::findAllThatEqual(entries,"gnome-terminal",terminalsFound,true);
        cmd = "/usr/bin/gnome-terminal -x \""+command+"\" \""+args+"\"";
        if (terminalsFound.size() == 0)
        {
            StringUtils::findAllThatEqual(entries,"lxterminal",terminalsFound,true);
            cmd = "/usr/bin/lxterminal -x \""+command+"\" \""+args+"\"";
        }

        if (terminalsFound.size() == 0)
        {
            StringUtils::findAllThatEqual(entries,"xfce4-terminal",terminalsFound,true);
            cmd = "/usr/bin/xfce4-terminal --execute \""+command+"\" \""+args+"\"";
        }

        if (terminalsFound.size() == 0)
        {
            StringUtils::findAllThatEqual(entries,"konsole",terminalsFound,true);
            cmd = "/usr/bin/konsole -e \""+command+"\" \""+args+"\"";
        }

        if (terminalsFound.size() == 0)
        {
            StringUtils::findAllThatEqual(entries,"rxvt",terminalsFound,true);
            cmd = "/usr/bin/rxvt -e \""+command+"\" \""+args+"\"";
        }

        if (terminalsFound.size() == 0)
        {
            cmd = "/usr/bin/xterm -e \""+command+"\" \""+args+"\"";
        }
    #endif
        std::cerr <<"SystemUtils::executeInTerminal - " << cmd<<std::endl;
    return system(cmd.c_str());
}

}}}}//end namespace

