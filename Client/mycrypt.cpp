#include "mycrypt.h"

MyCrypt::MyCrypt(std::string strKey,std::string strIV)
{


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

