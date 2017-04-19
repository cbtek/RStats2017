/**
  * SystemUtils.hpp
  */
#pragma once

#include "utility/inc/Exception.hpp"

#include <chrono>
#include <locale>
#include <codecvt>
#include <string>
#include <vector>

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

namespace SystemUtils_EmbeddedUtils
{

    /**
    * @brief Converts string to upper-case
    * @param Reference to the string to convert
    */
    inline void toUpperInPlace(std::string &str)
    {
        size_t count=str.size();
        for (size_t a1 = 0;a1<count;++a1)
        {
            str[a1] = static_cast<char>(toupper(str[a1]));
        }
    }

    /**
    * @brief Converts string to lower-case
    * @param Reference to the string to convert
    */
    inline void toLowerInPlace(std::string &str)
    {
        size_t count=str.size();
        for (size_t a1 = 0;a1<count;++a1)
        {
            str[a1] = static_cast<char>(tolower(str[a1]));
        }
    }

    /**
    * @brief Converts string to upper-case
    * @param The string to convert
    * @return The converted string
    */
    inline std::string toUpper(const std::string &str)
    {
        std::string strOut = str;
        toUpperInPlace(strOut);
        return strOut;
    }

    /**
    * @brief Converts wide string to lower-case
    * @param The string to convert
    * @return The converted string
    */
    inline std::string toLower(const std::string &str)
    {
        std::string strOut = str;
        toLowerInPlace(strOut);
        return strOut;
    }
     /**
      * @brief Removes all whitespace (\\t \\r \\n ' ' \\f) from
      *        the beginning and end of inputString.
      * @param Reference to the source string to operate upon
      */
      inline void trimmedInPlace(std::string &str)
      {
          int count=static_cast<int>(str.size());
          for (int a1 = 0;a1<count;++a1)
          {
              if (str[a1]==' '||
                  str[a1]=='\n' ||
                  str[a1]=='\r' ||
                  str[a1]=='\f' ||
                  str[a1]=='\t' )
              {
                  str.erase(str.begin()+a1);
                  a1--;
                  count--;
                  continue;
              }
              else break;
          }


          if (count==0)
          {
              return;
          }
          int cnt = static_cast<int>(count);
          for (int a1 = cnt-1;a1 >= 0;--a1)
          {
              if (str[a1]==' '||
                  str[a1]=='\n' ||
                  str[a1]=='\r' ||
                  str[a1]=='\f' ||
                  str[a1]=='\t' )
              {
                  str.erase(str.begin()+a1);
              }
              else
              {
                  break;
              }
          }
      }

      /**
      * @brief Removes all whitespace (\t \r \n ' ' \f) from
      *        the beginning and end of inputString.
      * @param The source string to operate upon
      * @return Returns the trimmed string as a copy.
      *
      */
      inline std::string trimmed(const std::string &str)
      {
          std::string strOut = str;
          trimmedInPlace(strOut);
          return strOut;
      }


      /**
      * @brief Splits a string based on the delimeter
      * @param inputString The string to split
      * @param delimiter The delimiter used to break the string apart
      * @param splitItems Reference to string vector. Avoids vector copy.
      * @code {.cpp}
          //Example: Split string based on custom delim

          std::string line = "test|item <$CBTEK$> test,data";

          std::vector<std::string>items;

          split(line,"<$CBTEK$>",items);

          //Example Results:
          //items[0]="test|item";
          //items[1]="test,data";
          @endcode
      */
      inline void split(const std::string &str,
                        const std::string &delimiter,
                        std::vector<std::string> &splitItems)
      {
          std::string s = str;
          size_t pos = 0;
          std::string token;
          while ((pos = s.find(delimiter)) != std::string::npos)
          {
              token = s.substr(0, pos);
              splitItems.push_back(token);
              s.erase(0, pos + delimiter.length());
          }
          splitItems.push_back(s);
      }


      /**
      * @brief Splits a string based on the delimeter
      * @param inputString The string to split
      * @param delimiter The delimiter used to break the string apart
      * @return Return a vector of split strings
      * @code {.cpp}
          //Example: Split string based on custom delim

          std::string line = test|item <$CBTEK$> test,data

          std::vector<std::string>items;

          items = split(line,"<$CBTEK$>");

          //Example Results:
          //items[0]="test|item";
          //items[1]="test,data";
          @endcode
      */
      inline std::vector<std::string> split(const std::string &str,
                                            const std::string &delimiter)
      {
          std::vector<std::string> outItems;
          split(str,delimiter,outItems);
          return outItems;
      }

      template<typename T>
      inline T toNumber(const std::string & value)
      {
          std::istringstream in(value,std::istringstream::in);
          T returnValue;
          in>>returnValue;
          return returnValue;
      }


      /**
       * @brief Trims all items and removes empty elements
       * @param items
       */
      inline void clean(std::vector<std::string> & items)
      {
          if (items.size() == 0)
          {
              return;
          }
          int lastIndex = static_cast<int>(items.size()) - 1;
          for (int a1 = lastIndex; a1>=0 ;--a1)
          {
              size_t index = static_cast<size_t>(a1);
              if (items[index].empty())
              {
                  items.erase(items.begin()+index);
                  continue;
              }
              SystemUtils_EmbeddedUtils::trimmedInPlace(items[index]);
          }
      }

    /**
     * @brief findAllThatEqual
     * @param items
     * @param valueToMatch
     * @param itemsOut
     * @param isCaseSensitive
     */
    inline void findAllThatEqual(const std::vector<std::string> &items,
                            const std::string &valueToMatch,
                            std::vector<std::string> &itemsOut,
                            bool isCaseSensitive=true)
    {
        if (isCaseSensitive)
        {
            for (size_t a1 = 0; a1 < items.size(); ++a1)
            {
                if (items[a1] == valueToMatch)
                {
                    itemsOut.push_back(items[a1]);
                }
            }
        }
        else
        {
            std::string value = toUpper(valueToMatch);
            for (size_t a1 = 0; a1 < items.size(); ++a1)
            {
                if (toUpper(items[a1]) == value)
                {
                    itemsOut.push_back(items[a1]);
                }
            }
        }
    }

    /**
     * @brief Perfroms string replace (in-place)
     * @param inputString Reference to the inputString to perform
     * in-place replacement
     * @param oldString The old string to replace
     * @param newString The new string to insert
     * @param isCaseSensitive Should oldString be caseSensitive
     * within inputString?
     */
    inline void replaceInPlace(std::string &inputString,
                                     const std::string &oldString,
                                     const std::string &newString,
                                     bool isCaseSensitive = true)
    {
        if (isCaseSensitive)
        {
            size_t pos = 0;
            while((pos = inputString.find(oldString, pos)) != std::string::npos)
            {
                 inputString.replace(pos, oldString.length(), newString);
                 pos += newString.length();
            }
        }
        else
        {
            std::string subject = toUpper(inputString);
            std::string search  = toUpper(oldString);
            std::string replace = toUpper(newString);
            size_t pos = 0;
            while((pos = subject.find(search, pos)) != std::string::npos)
            {
                 inputString.replace(pos, search.length(), newString);
                 pos += newString.length();
            }
        }
    }



    /**
     * @brief Perfroms string replace (in-place)
     * @param inputString The string that contains oldString to replace
     * @param oldString The old string to replace
     * @param newString The new string to insert
     * @param isCaseSensitive Should oldString be caseSensitive
     * within inputString?
     * @return inputString with the replaced oldString.  If oldString
     * is not found within inputString then inputString is returned
     * unmodified.
     */
    inline std::string replace(const std::string &inputString,
                                     const std::string &oldString,
                                     const std::string &newString,
                                     bool isCaseSensitive = true)
    {

        if (isCaseSensitive)
        {
            std::string subject = inputString;
            std::string search  = oldString;
            std::string replace = newString;

                size_t pos = 0;
                while((pos = subject.find(search, pos)) != std::string::npos)
                {
                     subject.replace(pos, search.length(), replace);
                     pos += replace.length();
                }
                return subject;
        }
        else
        {
            std::string subject = (inputString);
            std::string search  = toUpper(oldString);
            std::string replace = toUpper(newString);

                size_t pos = 0;
                while((pos = subject.find(search, pos)) != std::string::npos)
                {
                     subject.replace(pos, search.length(), replace);
                     pos += replace.length();
                }
                return subject;
        }
    }

    /**
    * @brief Determines if inputString starts with value
    * @param inputString The source input string
    * @param startsWithValue The value that inputString startsWith
    * @param isCaseSensitive Should startsWithValue be case sensitive?
    * @return true if inputString starts with startsValue, else false
    */
    inline bool startsWith(const std::string &inputString,
                           const std::string &startsWithValue,
                           bool isCaseSensitive = true)
    {
        if(inputString.size()<startsWithValue.size())
        {
            return false;
        }

        if (isCaseSensitive)
        {
            return !inputString.compare(0, startsWithValue.size(), startsWithValue);
        }
        else
        {
            std::string str1=toLower(inputString);
            std::string str2=toLower(startsWithValue);
            return !str1.compare(0, str2.size(), str2);
        }
    }

    /**
     * @brief Returns the directory portion of a filePath
     * @param filePath The full path to a file
     * @return directory of filePath
     */
    inline std::string getDirPath(const std::string &filePath)
    {
        std::string universalFilePath = replace(filePath,"\\","/");
        size_t index = 0;

        if((index = universalFilePath.find_last_of('/')) != std::string::npos)
        {
            return universalFilePath.substr(0, index+1);
        }
        return "";
    }

    /**
    * @brief endsWith
    * @param src
    * @param value
    * @param caseSensitive
    * @return
    */
    inline bool endsWith(const std::string &src,
                         const std::string &value,
                         bool caseSensitive = true)
    {
        if(src.size()<value.size())
        {
           return false;
        }
        if (caseSensitive)
        {
           return !src.compare(src.size() - value.size(), value.size(), value);
        }
        else
        {
           std::string srcLower=toLower(src);
           std::string valueLower = toLower(value);
           return !srcLower.compare(srcLower.size() - valueLower.size(), valueLower.size(), valueLower);
        }
    }

    /**
     * @brief Constructs a full file path from a directory
     * path and filename.
     * @param dirPath A directory path (eg. C:\windows, /usr/lib/,etc)
     * @param fileName A file name (eg. test.xml,  run.bat, /exits/exit.bat,etc)
     * @return Constructed file path with system path seperators
     */
    inline std::string buildFilePath(const std::string &dirPath, const std::string &fileName)
    {
        std::string pathSep,file,dir;

        if (SystemUtils_EmbeddedUtils::trimmed(dirPath).size()==0)
        {
            return fileName;
        }

    #   ifdef __WIN32
        pathSep = "\\";
        dir = SystemUtils_EmbeddedUtils::replace(dirPath,"/",pathSep);
        file= SystemUtils_EmbeddedUtils::replace(fileName,"/",pathSep);
    #   else
        pathSep = "/";
        dir = SystemUtils_EmbeddedUtils::replace(dirPath,"\\",pathSep);
        file= SystemUtils_EmbeddedUtils::replace(fileName,"\\",pathSep);
    #   endif

        size_t pathHasSep=
                SystemUtils_EmbeddedUtils::endsWith(SystemUtils_EmbeddedUtils::trimmed(dir),pathSep);

        size_t fileHasSep=
                SystemUtils_EmbeddedUtils::startsWith(SystemUtils_EmbeddedUtils::trimmed(fileName),pathSep);


        if (pathHasSep || fileHasSep)
        {
           if (pathHasSep && fileHasSep)
           {
               int dirSize = static_cast<int>(dir.size());
               for(int a1 = dirSize-1;a1 >= 0;--a1)
               {
                   if (dir[a1]==' ')
                   {
                       continue;
                   }
                   else if (dir[a1]==pathSep[0])
                   {
                       dir.erase(dir.begin()+a1);
                       break;
                   }
               }
           }
            return dir+fileName;
        }
        else
        {
           return dir+pathSep+fileName;
        }
    }


    /**
     * @brief Determines if given filePath is a directory
     * @param filePath Path to file or directory
     * @return true if filePath is directory, false otherwise
     */
    inline bool isDirectory(const std::string &filePath)
    {
    #ifdef _WIN32
        DWORD attr;

        if(filePath.size() && (attr = GetFileAttributesA(filePath.c_str())) != INVALID_FILE_ATTRIBUTES)
        {
            if(attr & FILE_ATTRIBUTE_DIRECTORY)
            {
                return true;
            }
        }

    #else
        struct stat si;

        if(filePath.size() && (stat(filePath.c_str(), &si)) == 0)
        {
            if(S_ISDIR(si.st_mode))
            {
                return true;
            }
        }
    #endif

        return false;
    }


    /**
     * @brief createDirectory
     * @param dirPath
     * @return
     */
    inline bool createDirectory(const std::string &dirPath)
    {
        int nError=0;
        #if defined(_WIN32)
            CreateDirectory(dirPath.c_str(), NULL);
            nError = GetLastError();
        #else
            nError = mkdir(dirPath.c_str(),0733);
        #endif
        return isDirectory(dirPath);
    }
}

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
    SystemUtils_EmbeddedUtils::replaceInPlace(dirStr,"\\","/");
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
    SystemUtils_EmbeddedUtils::replaceInPlace(dirStr,"\\","/");
    return dirStr;
#else
    std::string path = SystemUtils_EmbeddedUtils::buildFilePath(getUserHomeDirectory(), ".local");
    SystemUtils_EmbeddedUtils::createDirectory(path);
    path = SystemUtils_EmbeddedUtils::buildFilePath(getUserHomeDirectory(), ".local/share");
    SystemUtils_EmbeddedUtils::createDirectory(path);
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
    SystemUtils_EmbeddedUtils::replaceInPlace(dirStr,"\\","/");
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
        appPath = SystemUtils_EmbeddedUtils::getDirPath(appPath);
    #endif
    return appPath;
}


inline int executeInTerminal(const std::string& command, const std::string& args)
{
    std::string cmd;
    #ifdef __WIN32
        cmd = "start cmd /K \"" + command+"\" \""+args+"\"";
    #else
//        std::vector<std::string> entries = FileUtils::getFileEntries("/usr/bin","",false);
//        std::vector<std::string> terminalsFound;
//        SystemUtils_EmbeddedUtils::findAllThatEqual(entries,"gnome-terminal",terminalsFound,true);
//        cmd = "/usr/bin/gnome-terminal -x \""+command+"\" \""+args+"\"";
//        if (terminalsFound.size() == 0)
//        {
//            SystemUtils_EmbeddedUtils::findAllThatEqual(entries,"lxterminal",terminalsFound,true);
//            cmd = "/usr/bin/lxterminal -x \""+command+"\" \""+args+"\"";
//        }

//        if (terminalsFound.size() == 0)
//        {
//            SystemUtils_EmbeddedUtils::findAllThatEqual(entries,"xfce4-terminal",terminalsFound,true);
//            cmd = "/usr/bin/xfce4-terminal --execute \""+command+"\" \""+args+"\"";
//        }

//        if (terminalsFound.size() == 0)
//        {
//            SystemUtils_EmbeddedUtils::findAllThatEqual(entries,"konsole",terminalsFound,true);
//            cmd = "/usr/bin/konsole -e \""+command+"\" \""+args+"\"";
//        }

//        if (terminalsFound.size() == 0)
//        {
//            SystemUtils_EmbeddedUtils::findAllThatEqual(entries,"rxvt",terminalsFound,true);
//            cmd = "/usr/bin/rxvt -e \""+command+"\" \""+args+"\"";
//        }

//        if (terminalsFound.size() == 0)
//        {
//            cmd = "/usr/bin/xterm -e \""+command+"\" \""+args+"\"";
//        }
    #endif
        //std::cerr <<"SystemUtils::executeInTerminal - " << cmd<<std::endl;
    return system(cmd.c_str());
}

}}}}//end namespace

