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
    byte key[AES::MAX_KEYLENGTH];
    byte iv[AES::BLOCKSIZE];

public:
    MyCrypt();
    QByteArray encrypt(QByteArray data);
    QByteArray decrypt(QByteArray data);
    static QByteArray makeKey();
    static QByteArray makeIV();
    void setKeyIv(std::string key,std::string iv);
    byte* getKey(){ return key;}
};

#endif // MYCRYPT_H
