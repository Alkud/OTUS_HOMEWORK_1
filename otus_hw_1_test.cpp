// otus_hw_1_test.cpp in Otus Homework #1

#define BOOST_TEST_MODULE Otus_HW_1_test

#include <boost/test/unit_test.hpp>
#include "helper_functions.h"


BOOST_AUTO_TEST_SUITE(homework_1_test);

BOOST_AUTO_TEST_CASE(is_version_set)
{
  int major{}, minor{}, patch{};
  getVersion(major, minor, patch);
  BOOST_CHECK(patch > 0 );
}

BOOST_AUTO_TEST_SUITE_END()
