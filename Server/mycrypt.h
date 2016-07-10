#ifndef MYCRYPT_H
#define MYCRYPT_H

#include <crypto++/aes.h>
#include <crypto++/cryptlib.h>
#include <crypto++/filters.h>
#include <crypto++/osrng.h>
#include <cryptopp/modes.h>
#include <crypto++/hex.h>
#include <QByteArray>
#include <QDebug>

using namespace CryptoPP;
class MyCrypt
{
private:
    AutoSeededRandomPool prng;
    byte key[AES::MAX_KEYLENGTH];
    byte iv[AES::BLOCKSIZE];

public:
    MyCrypt();
    QByteArray encrypt(QByteArray data);
    QByteArray decrypt(QByteArray data);
    QByteArray makeKey();
    QByteArray makeIV();
    byte* getKey(){ return key;}
};

#endif // MYCRYPT_H
