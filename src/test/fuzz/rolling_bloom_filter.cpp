// Copyright (c) 2020-2021 The beticoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <bloom.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <uint256.h>

#include <cassert>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

FUZZ_TARGET(rolling_bloom_filter)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());

    CRollingBloomFilter rolling_bloom_filter{
        fuzzed_data_provider.ConsumeIntegralInRange<unsigned int>(1, 1000),
        0.999 / fuzzed_data_provider.ConsumeIntegralInRange<unsigned int>(1, std::numeric_limits<unsigned int>::max())};
    while (fuzzed_data_provider.remaining_bytes() > 0) {
        CallOneOf(
            fuzzed_data_provider,
            [&] {
                const std::vector<unsigned char> b = ConsumeRandomLengthByteVector(fuzzed_data_provider);
                (void)rolling_bloom_filter.contains(b);
                rolling_bloom_filter.insert(b);
                const bool present = rolling_bloom_filter.contains(b);
                assert(present);
            },
            [&] {
                const std::optional<uint256> u256 = ConsumeDeserializable<uint256>(fuzzed_data_provider);
                if (!u256) {
                    return;
                }
                (void)rolling_bloom_filter.contains(*u256);
                rolling_bloom_filter.insert(*u256);
                const bool present = rolling_bloom_filter.contains(*u256);
                assert(present);
            },
            [&] {
                rolling_bloom_filter.reset();
            });
    }
}
