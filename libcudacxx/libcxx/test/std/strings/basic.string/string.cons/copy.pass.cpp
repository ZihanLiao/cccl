//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// basic_string(const basic_string<charT,traits,Allocator>& str);

#include <string>
#include <cassert>

#include "test_macros.h"
#include "test_allocator.h"
#include "min_allocator.h"

template <class S>
void
test(S s1)
{
    S s2 = s1;
    LIBCPP_ASSERT(s2.__invariants());
    assert(s2 == s1);
    assert(s2.capacity() >= s2.size());
    assert(s2.get_allocator() == s1.get_allocator());
}

int main(int, char**)
{
    {
    typedef test_allocator<char> A;
    typedef std::basic_string<char, std::char_traits<char>, A> S;
    test(S(A(3)));
    test(S("1", A(5)));
    test(S("1234567890123456789012345678901234567890123456789012345678901234567890", A(7)));
    }
    {
    typedef min_allocator<char> A;
    typedef std::basic_string<char, std::char_traits<char>, A> S;
    test(S(A{}));
    test(S("1", A()));
    test(S("1234567890123456789012345678901234567890123456789012345678901234567890", A()));
    }

  return 0;
}
