// Copyright 2021 by FORTYSS

#include <Builder.hpp>

int main(int argc, const char *argv[]) {
  try
  {
    boost::program_options::options_description desc{"Options"};
    boost::program_options::variables_map vm;
    Builder::create_program_options(desc, vm, argc, argv);

    if(vm.count("help"))
      std::cout << desc;
    else if(argc > 1){
      Builder builder{};
      builder.start(vm);
    } else
      throw boost::program_options::error(error_mes);
  } catch (const boost::program_options::error &ex)
  {
    BOOST_LOG_TRIVIAL(error) << ex.what() << '\n';
  }
}