//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// template<> struct char_traits<char32_t>

// static constexpr bool eq(char_type c1, char_type c2);

#include <string>
#include <cassert>

#include "test_macros.h"

int main(int, char**)
{
#ifndef _LIBCUDACXX_HAS_NO_UNICODE_CHARS
    assert(std::char_traits<char32_t>::eq(U'a', U'a'));
    assert(!std::char_traits<char32_t>::eq(U'a', U'A'));
#endif  // _LIBCUDACXX_HAS_NO_UNICODE_CHARS

  return 0;
}
