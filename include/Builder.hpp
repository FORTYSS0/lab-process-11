// Copyright 2021 by FORTYSS

#ifndef INCLUDE_BUILDER_HPP_
#define INCLUDE_BUILDER_HPP_

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <iostream>
#include <boost/program_options.hpp>
#include <string>
#include <boost/process.hpp>
#include <async++.h>
#include "process.hpp"
#include <pthread.h>
#include <future>

const char error_mes[] = "Error\n"
                         "Write to get Help: --help or -h";

class Builder{
 public:
  static void create_program_options(boost::program_options::options_description& desc,
                                     boost::program_options::variables_map& vm,
                                     const int& argc, const char *argv[]);

  void start(const boost::program_options::variables_map& vm);

  void init(const boost::log::trivial::severity_level& sev_lvl);

  boost::log::trivial::severity_level choose_sev_lvl(const std::string& sev_lvl_str);

  void settings_process(const boost::program_options::variables_map& vm);

  bool run_process(const std::string& target, Process_info& process_info);

  ~Builder();

 private:
  Process* p_process;
};

#endif // INCLUDE_BUILDER_HPP_
