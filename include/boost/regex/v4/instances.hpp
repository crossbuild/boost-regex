/*
 *
 * Copyright (c) 1998-2002
 * Dr John Maddock
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Dr John Maddock makes no representations
 * about the suitability of this software for any purpose.
 * It is provided "as is" without express or implied warranty.
 *
 */

 /*
  *   LOCATION:    see http://www.boost.org for most recent version.
  *   FILE         instances.cpp
  *   VERSION      see <boost/version.hpp>
  *   DESCRIPTION: Defines those template instances that are placed in the
  *                library rather than in the users object files.
  */

//
// note no include guard, we may include this multiple times:
//
#ifndef BOOST_REGEX_NO_EXTERNAL_TEMPLATES

namespace boost{

//
// this header can be included multiple times, each time with
// a different character type, BOOST_REGEX_CHAR_T must be defined
// first:
//
#ifndef BOOST_REGEX_CHAR_T
#  error "BOOST_REGEX_CHAR_T not defined"
#endif

//
// what follows is compiler specific:
//

#ifdef __BORLANDC__

#pragma option push -a8 -b -Vx -Ve -pc

#  ifndef BOOST_REGEX_INSTANTIATE
#     pragma option push -Jgx
#  endif

template class BOOST_REGEX_DECL reg_expression< BOOST_REGEX_CHAR_T >;

#  ifndef BOOST_REGEX_INSTANTIATE
#     pragma option pop
#  endif

#pragma option pop

#elif defined(BOOST_MSVC)

#  ifndef BOOST_REGEX_INSTANTIATE
#     define template extern template
#  endif

#pragma warning(push)
#pragma warning(disable : 4251 4231 4660)

template class BOOST_REGEX_DECL reg_expression< BOOST_REGEX_CHAR_T >;

#pragma warning(pop)

#  ifdef template
#     undef template
#  endif

#elif !defined(BOOST_REGEX_HAS_DLL_RUNTIME)

//
// for each [member] function declare a full specialisation of that
// [member] function, then instantiate it in one translation unit.
// This is not guarenteed to work according to the standard, but in
// practice it should work for all compilers (unless they use a realy
// perverse name mangling convention).  Unfortunately this approach
// does *not* work for Win32 style import/export, because that can
// alter the class layout.
//

#  ifndef BOOST_REGEX_INSTANTIATE
#     define template template<>
#  endif

template unsigned int BOOST_REGEX_CALL reg_expression<BOOST_REGEX_CHAR_T>::set_expression(const BOOST_REGEX_CHAR_T* p, const BOOST_REGEX_CHAR_T* end, reg_expression<BOOST_REGEX_CHAR_T>::flag_type f);

#  ifdef template
#     undef template
#  endif

#endif

} // namespace boost

#endif // BOOST_REGEX_NO_EXTERNAL_TEMPLATES
 

