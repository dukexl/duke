#ifndef _SYSTEMCONFIG_H_
#define _SYSTEMCONFIG_H_

#include <string>
#include <map>
#include <fstream>

namespace PUBLIC
{
    class SystemConfig
    {
    public:
        SystemConfig(const std::string &filepath);
        void Load();
        const std::string &GetProperty(const std::string &name);

    private:
        std::map<std::string, std::string> properties_;
        std::string filepath_;
    };
} // namespace PUBLIC

#endif