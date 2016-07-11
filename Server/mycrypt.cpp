#include "mycrypt.h"

MyCrypt::MyCrypt()
{
    prng.GenerateBlock(key,AES::MAX_KEYLENGTH);
    prng.GenerateBlock(iv,AES::BLOCKSIZE);

    std::string strKey="1AAE0C7222C0D716B4A197321E602F2BE31D4344AF0A0577EE029D23154DA9EA";
    std::string strIV="81D605853779AD15B106C8FDE4E2A9D3";

    qDebug()<<strKey.c_str();
    qDebug()<<strIV.c_str();

    memcpy(key,strKey.c_str(),AES::MAX_KEYLENGTH);
    memcpy(iv,strIV.c_str(),AES::BLOCKSIZE);


}

QByteArray MyCrypt::encrypt(QByteArray data){
    try{
        CBC_Mode<AES>::Encryption *e=new CBC_Mode<AES>::Encryption;
        e->SetKeyWithIV(key,sizeof(key),iv);
        std::string chiper1,chiper2;
        chiper1.clear();
        chiper2.clear();
        StringSource(data.data(),true,
                     new StreamTransformationFilter(*e, new StringSink(chiper1),StreamTransformationFilter::PKCS_PADDING) );
        chiper2.clear();
        StringSource(chiper1,true,new HexEncoder(new StringSink(chiper2)));
        data.clear();
        data.append(chiper2.c_str());
        delete e;
        return data;
    }catch(const CryptoPP::Exception& e)
    {
      qDebug() << e.what();
    }

    return NULL;

}

QByteArray MyCrypt::decrypt(QByteArray data){
    try{
        CBC_Mode<AES>::Decryption *d=new CBC_Mode<AES>::Decryption;
        d->SetKeyWithIV(key,sizeof(key),iv);
        std::string chiper1,chiper2;
        chiper1.clear();
        chiper2.clear();
        chiper2=data.data();
        StringSource(chiper2,true,new HexDecoder(new StringSink(chiper1)));
        chiper2.clear();
        StringSource(chiper1,true,
                     new StreamTransformationFilter(*d, new StringSink(chiper2)));
        data.clear();
        data.append(chiper2.c_str());
        delete d;
        return data;
    }catch(const CryptoPP::Exception& e)
    {
        qDebug()<<e.what();
    }
    return NULL;
}

QByteArray MyCrypt::makeKey(){
    byte cKey[AES::MAX_KEYLENGTH];
    prng.GenerateBlock(cKey,sizeof(key));
    std::string strKey;
    StringSource(cKey,AES::MAX_KEYLENGTH,true, new HexEncoder(new StringSink(strKey)));
    return QByteArray(strKey.c_str());
}

QByteArray MyCrypt::makeIV(){
    byte cIV[AES::BLOCKSIZE];
    prng.GenerateBlock(cIV,sizeof(cIV));
    std::string strIV;
    StringSource(cIV,AES::BLOCKSIZE,true, new HexEncoder(new StringSink(strIV)));
    return QByteArray(strIV.c_str());
}
