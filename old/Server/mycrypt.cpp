#include "mycrypt.h"

MyCrypt::MyCrypt()
{

}

void MyCrypt::setKeyIv(std::string strKey, std::string strIv){

    qDebug()<<strKey.c_str();
    qDebug()<<strIv.c_str();

    std::string sKey,sIv;

    StringSource(strKey,true,new HexDecoder(new StringSink(sKey)));
    StringSource(strIv,true,new HexDecoder(new StringSink(sIv)));

    memcpy(key,sKey.c_str(),AES::MAX_KEYLENGTH);
    memcpy(iv,sIv.c_str(),AES::BLOCKSIZE);

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
    AutoSeededRandomPool* prng=new AutoSeededRandomPool;
    byte cKey[AES::MAX_KEYLENGTH];
    prng->GenerateBlock(cKey,sizeof(key));
    std::string strKey;
    StringSource(cKey,AES::MAX_KEYLENGTH,true, new HexEncoder(new StringSink(strKey)));
    delete prng;
    return QByteArray(strKey.c_str());
}

QByteArray MyCrypt::makeIV(){
    AutoSeededRandomPool* prng=new AutoSeededRandomPool;
    byte cIV[AES::BLOCKSIZE];
    prng->GenerateBlock(cIV,sizeof(cIV));
    std::string strIV;
    StringSource(cIV,AES::BLOCKSIZE,true, new HexEncoder(new StringSink(strIV)));
    delete prng;
    return QByteArray(strIV.c_str());
}
