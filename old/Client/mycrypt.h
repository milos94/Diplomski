#ifndef MYCRYPT_H
#define MYCRYPT_H

#include <crypto++/aes.h>
#include <crypto++/cryptlib.h>
#include <crypto++/filters.h>
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
    MyCrypt(std::string,std::string);
    QByteArray encrypt(QByteArray data);
    QByteArray decrypt(QByteArray data);
    byte* getKey(){ return key;}
};

#endif // MYCRYPT_H
