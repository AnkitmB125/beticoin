// Copyright (c) 2009-2010 betishi Nakamoto
// Copyright (c) 2009-2020 The beticoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef beticoin_ATTRIBUTES_H
#define beticoin_ATTRIBUTES_H

#if defined(__clang__)
#  if __has_attribute(lifetimebound)
#    define LIFETIMEBOUND [[clang::lifetimebound]]
#  else
#    define LIFETIMEBOUND
#  endif
#else
#  define LIFETIMEBOUND
#endif

#endif // beticoin_ATTRIBUTES_H
