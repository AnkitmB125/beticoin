// Copyright (c) 2020 The beticoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef beticoin_WALLET_DUMP_H
#define beticoin_WALLET_DUMP_H

#include <fs.h>

class CWallet;

struct bilingual_str;

bool DumpWallet(CWallet& wallet, bilingual_str& error);
bool CreateFromDump(const std::string& name, const fs::path& wallet_path, bilingual_str& error, std::vector<bilingual_str>& warnings);

#endif // beticoin_WALLET_DUMP_H
