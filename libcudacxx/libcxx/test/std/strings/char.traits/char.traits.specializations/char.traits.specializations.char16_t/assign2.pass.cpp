//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// template<> struct char_traits<char16_t>

// static void assign(char_type& c1, const char_type& c2);
// constexpr in C++17

#include <string>
#include <cassert>

#include "test_macros.h"

#if TEST_STD_VER > 2014
constexpr bool test_constexpr()
{
    char16_t c = u'1';
    std::char_traits<char16_t>::assign(c, u'a');
    return c == u'a';
}
#endif

int main(int, char**)
{
#ifndef _LIBCUDACXX_HAS_NO_UNICODE_CHARS
    char16_t c = u'\0';
    std::char_traits<char16_t>::assign(c, u'a');
    assert(c == u'a');

#if TEST_STD_VER > 2014
    static_assert(test_constexpr(), "" );
#endif
#endif  // _LIBCUDACXX_HAS_NO_UNICODE_CHARS

  return 0;
}
