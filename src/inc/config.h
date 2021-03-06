#ifndef __CONFIG_HPP
#define __CONFIG_HPP

#include<map>
#include<string>
#include<mutex>
#include "json/json.h"

class Config {
public:
    Config(const std::string& p, const std::string& af);

    Json::Value get();
    Json::Value get(const std::string& fname);
    bool set(const std::string& fname, const std::string& value);
    void set(const std::string& fname, const Json::Value& value);
    bool remove(const std::string& fname);
    bool activate(const std::string& fname);
    std::string activated();
private:
    Json::Reader reader;
    std::mutex mutex;
    std::string path;
    std::string activation_file;
    std::map<std::string, Json::Value> config_store;
};

#endif
