// Copyright (c) 2009-2010 betishi Nakamoto
// Copyright (c) 2009-2019 The beticoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef beticoin_SUPPORT_CLEANSE_H
#define beticoin_SUPPORT_CLEANSE_H

#include <stdlib.h>

/** Secure overwrite a buffer (possibly containing secret data) with zero-bytes. The write
 * operation will not be optimized out by the compiler. */
void memory_cleanse(void *ptr, size_t len);

#endif // beticoin_SUPPORT_CLEANSE_H
