// Copyright (c) 2011-2020 The beticoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef beticoin_QT_beticoinADDRESSVALIDATOR_H
#define beticoin_QT_beticoinADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class beticoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit beticoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** beticoin address widget validator, checks for a valid beticoin address.
 */
class beticoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit beticoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // beticoin_QT_beticoinADDRESSVALIDATOR_H
